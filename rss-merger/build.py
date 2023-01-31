import argparse
from copy import deepcopy
from dateutil.parser import parse
import json
import lxml.etree as etree
import requests
from urllib import request
import yaml

NSMAP = {}


def getNestedJson(value, path):
    """Get a nested JSON value by a period delimited path."""

    for key in path.split('.'):
        value = value[key]
    return value


def sanitizeTag(tag):
    """Convert tag prefixes using the namespace map."""

    if ':' not in tag:
        return tag
    parts = tag.partition(':')
    return '{{{}}}{}'.format(NSMAP[parts[0]], parts[2])


def copyElement(source, destination, tag):
    """Find an element by tag name in the source, and copy it to the destination if it exists."""

    child = source.find(sanitizeTag(tag))
    if child is not None:
        destination.append(deepcopy(child))


def setElement(item, override, overwrite=False):
    """Get or create an element by tag name, and set the given inner text and attributes."""

    tag = sanitizeTag(override['tag'])
    element = item.find(tag)

    if element is not None and not overwrite:
        return
    if element is None:
        element = etree.SubElement(item, tag)

    if 'text' in override:
        element.text = override['text']
    if 'attributes' in override:
        for attribute in override['attributes']:
            element.attrib[attribute['name']] = attribute.get('value')


def createTree(feeds, defaults):
    """Create the output RSS tree and set channel tags."""

    global NSMAP

    tree = etree.Element('rss')
    tree.attrib['version'] = '2.0'
    channel = etree.SubElement(tree, 'channel')

    for feed in feeds:
        NSMAP.update(feed['feed'].nsmap)
    etree.cleanup_namespaces(tree, top_nsmap=NSMAP, keep_ns_prefixes=NSMAP.keys())

    for feed in feeds:
        for tag in feed['channelTags']:
            copyElement(feed['feed'].find('channel'), channel, tag)

    for custom in defaults['channel']:
        setElement(channel, custom)

    return tree


def createAudioItems(feeds):
    """Create output audio items from input feeds."""

    items = []
    titles = []

    for feed in feeds:
        for item in feed['feed'].find('channel').findall('item'):
            title = item.find('title').text
            if title in titles:
                continue
            titles.append(title)

            copy = etree.Element('item')
            for tag in feed['itemTags']:
                copyElement(item, copy, tag)
            items.append(copy)

    return items


def createVideoItems(posts, auth):
    """Create output video items from Patreon posts."""

    if 'filename' in posts:
        with open(posts['filename']) as f:
            data = json.load(f)
    else:
        session = requests.Session()
        session.cookies.set("datadome", auth['datadome'], domain="patreon.com")
        headers = {'User-Agent': 'Mozilla/5.0 (Macintosh; Intel Mac OS X 10.15; rv:107.0) Gecko/20100101 Firefox/107.0'}

        payload = {'data': {'email': auth['email'], 'password': auth['password']}}
        response = session.post('https://www.patreon.com/api/login', headers=headers, json=payload)
        if response.status_code != 200:
            raise RuntimeError('Patreon authentication failed')

        response = session.get('https://www.patreon.com/api/posts?filter[campaign_id]={}&page[size]=1000'.format(posts['campaignId']), headers=headers)
        if response.status_code != 200:
            raise RuntimeError('Failed to fetch posts')
        data = response.json()

    items = []

    for post in [item for item in data['data'] if item['attributes']['embed'] is not None and item['attributes']['embed']['provider'] == 'YouTube']:
        attributes = post['attributes']
        item = etree.Element('item')
        items.append(item)

        for tag in posts['tags']:
            element = etree.SubElement(item, sanitizeTag(tag['tag']))
            if 'text' in tag:
                element.text = getNestedJson(post, tag['text'])
            if 'attributes' in tag:
                for attribute in tag['attributes']:
                    element.attrib[attribute['name']] = attribute.get('value') or getNestedJson(post, attribute['from'])

    return items


def normalizeItems(items, feeds, defaults, overrides):
    """Set defaults and overrides for each item."""

    for override in overrides:
        item = next(item for item in items if item.find('guid').text == override['guid'])
        for change in override['tags']:
            setElement(item, change, True)

    for item in items:
        pubDate = item.find('pubDate')
        pubDate.text = parse(pubDate.text).strftime('%a, %d %b %Y %H:%M:%S %z')

        for default in defaults['items']:
            setElement(item, default)

    items[:] = sorted(items, key=lambda item: parse(item.find('pubDate').text), reverse=True)


def main():
    """Create an RSS feed from a list of input feeds and additional data."""

    argParser = argparse.ArgumentParser(description='Download RSS media')
    argParser.add_argument('--config', '-c', help='config file', default='config.yaml')
    args = argParser.parse_args()

    parser = etree.XMLParser(strip_cdata=False, remove_blank_text=True)
    with open(args.config) as f:
        config = yaml.full_load(f)

    for feed in config['feeds']:
        if 'filename' in feed:
            feed['feed'] = etree.parse(feed['filename'], parser).getroot()
            continue
        feed['feed'] = etree.parse(request.urlopen(feed['url']), parser).getroot()

    tree = createTree(config['feeds'], config['defaults'])
    audioItems = createAudioItems(config['feeds'])
    videoItems = createVideoItems(config['posts'], config.get('auth'))

    items = audioItems + videoItems
    normalizeItems(items, config['feeds'], config['defaults'], config['overrides'])
    tree.find('channel').extend(items)

    etree.ElementTree(tree).write('output.rss', encoding='UTF-8', xml_declaration=True, pretty_print=True)


if __name__ == "__main__":
    main()
