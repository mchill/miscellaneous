import argparse
import glob
import os
from datetime import timedelta
from dateutil import parser, tz
from feedgen.feed import FeedGenerator
from mutagen.mp3 import MP3
import yaml


def createFeed(config):
    """Create RSS feed."""

    feed_url = config['base_url'] + 'feed.rss'

    feed = FeedGenerator()
    feed.load_extension('podcast')

    feed.id(feed_url)
    feed.title(config['title'])
    feed.author({'name': config['author']})
    feed.image(config['image'])
    feed.description(config['description'])
    feed.link(href=feed_url, rel='self')
    feed.language('en')
    feed.podcast.itunes_block(True)
    feed.podcast.itunes_complete(True)

    return feed


def addChapter(feed, config, index, track):
    """Add entry to RSS feed."""

    filename = os.path.basename(track)
    title = os.path.splitext(filename)[0]

    entry = feed.add_entry()

    entry.guid(str(index))
    entry.title(title)
    entry.description(title)
    entry.published((parser.parse(config['date']) + timedelta(seconds=index + 1)).replace(tzinfo=tz.gettz()))
    entry.enclosure(config['base_url'] + filename, str(os.path.getsize(track)), 'audio/mpeg')
    entry.podcast.itunes_order(index + 1)
    entry.podcast.itunes_duration(formatDuration(MP3(track).info.length))
    entry.podcast.itunes_image(config['image'])

    return entry


def formatDuration(duration):
    """Format a duration in milliseconds to the format HH:MM:SS."""

    hours, remainder = divmod(duration, 3600)
    minutes, seconds = divmod(remainder, 60)
    return '{:02}:{:02}:{:02}'.format(int(hours), int(minutes), int(seconds))


def main():
    """Build audiobook RSS feed."""

    argParser = argparse.ArgumentParser(description='Build audiobook RSS feed')
    argParser.add_argument('--config', '-c', help='config file', default='config.yaml')
    args = argParser.parse_args()

    with open(args.config) as f:
        config = yaml.full_load(f)

    feed = createFeed(config)

    for index, track in enumerate(sorted(glob.glob(config['directory'] + '*.mp3'))):
        addChapter(feed, config, index, track)

    feed.rss_file(config['directory'] + 'feed.rss', pretty=True)


if __name__ == "__main__":
    main()
