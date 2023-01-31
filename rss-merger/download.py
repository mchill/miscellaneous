import argparse
import lxml.etree as etree
from os import path
import requests
from tinytag import TinyTag
import urllib.parse
from yt_dlp import YoutubeDL


def sanitizeTag(tag, nsmap):
    """Convert tag prefixes using the namespace map."""

    if ':' not in tag:
        return tag
    parts = tag.partition(':')
    return '{{{}}}{}'.format(nsmap[parts[0]], parts[2])


def formatDuration(duration):
    """Format a duration in milliseconds to the format HH:MM:SS."""

    hours, remainder = divmod(duration, 3600)
    minutes, seconds = divmod(remainder, 60)
    return '{:02}:{:02}:{:02}'.format(int(hours), int(minutes), int(seconds))


def processItem(item, args, nsmap):
    """Set media metadata for an item that couldn't be set before downloading."""

    title = item.find('title').text
    enclosure = item.find('enclosure')
    url = enclosure.attrib['url']
    guid = item.find('guid').text.replace(':', '')
    suffix = 'mp4' if 'youtu' in url else url.partition('?')[0].rpartition('.')[2]
    filename = '{}.{}'.format(guid, suffix)
    filepath = path.join(args.folder, filename)

    download(title, url, filepath)
    size = path.getsize(filepath)
    enclosure.attrib['length'] = str(size)
    enclosure.attrib['url'] = urllib.parse.urljoin(args.url, filename)

    file = TinyTag.get(filepath)
    duration = formatDuration(file.duration)
    durationElement = item.find(sanitizeTag('itunes:duration', nsmap))
    if durationElement is None:
        durationElement = etree.SubElement(item, sanitizeTag('itunes:duration', nsmap))
    durationElement.text = duration


def download(title, url, filepath):
    """Download the file if it can't be found on the local filesystem."""

    if path.exists(filepath):
        return

    print(f'Downloading {title}')

    if 'youtu' not in url:
        response = requests.get(url, allow_redirects=True)
        open(filepath, 'wb').write(response.content)
        return

    ydl_opts = {
        'format': 'best',
        'postprocessors': [{
            'key': 'FFmpegVideoConvertor',
            'preferedformat': 'mp4'
        }],
        'outtmpl': filepath
    }
    with YoutubeDL(ydl_opts) as ydl:
        ydl.download([url])


def main():
    """Download all media served by the RSS feed and update metadata accordingly to serve the media."""

    argParser = argparse.ArgumentParser(description='Download RSS media')
    argParser.add_argument('--url', help='URL prefix where files will be served', required=True)
    argParser.add_argument('--folder', help='folder to download media to', required=True)
    args = argParser.parse_args()

    xmlParser = etree.XMLParser(strip_cdata=False, remove_blank_text=True)
    output = etree.parse('output.rss', xmlParser).getroot()
    outputItems = output.find('channel').findall('item')
    nsmap = output.nsmap

    for item in outputItems:
        processItem(item, args, nsmap)

    etree.ElementTree(output).write('output.rss', encoding='UTF-8', xml_declaration=True, pretty_print=True)


if __name__ == "__main__":
    main()
