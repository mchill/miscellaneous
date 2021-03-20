# RSS Merger

I created this tool to address several problems that I encountered with certain podcasts that use Patreon to serve premium content.

* Free content is served on a public feed, and premium content on a separate private feed.
* Previously free content that was moved to Patreon has incorrect publish dates.
* Video content is omitted entirely from the RSS feed that Patreon generates.

This tool takes a public feed, a private Patreon feed, and a list of all campaign posts, and generates a single RSS feed with all content and corrected metadata. That .rss file can be easily served by a static website.

I wrote an additional tool that downloads all content and configures the generated output feed so that the content can also be self-hosted.

## Usage

To generate a single RSS feed:

```bash
python build.py --config config.yaml
```

To download all media and update metadata to self-host the media:

```bash
python download.py --url https://my.server.com/path/ --folder /path/to/folder
```

## Configuration

Rather than use command-line arguments, most of tool's configuration is defined by a single yaml file. The file format is documented below.

> Note: This is only for documentation. I included a full example [here](example-config.yaml).

```yaml
auth:                       # Patreon credentials (only required if posts "campaignId" is given rather than "filename")
  email: user@google.com    # Patreon email
  password: password123     # Patreon password

feeds:                      # List of feeds to merge
  - name: public            # Reference name for the feed
    url: google.com         # URL of the RSS feed (specify either "url" or "filename")
    filename: public.rss    # Filename of the feed (specify either "url" or "filename")
    channelTags:            # List of channel tags to copy to the output
      - title
    itemTags:               # List of item tags to copy to each item of the output
      - title

posts:                      # Patreon post configuration
  campaignId: 1             # Patreon campaign id to fetch posts (specify either "campaignId" or "filename")
  filename: posts.json      # Filename of the posts file (specify either "campaignId" or "filename")
  tags:                     # List of tags to create for each Patreon video post
    - tag: guid             # Element name
      text: id              # Post's JSON path of the text to copy to the element
      attributes:           # List of attributes to set for the element
        - name: isPermaLink # Attribute name
          value: "false"    # Raw value of the attribute (specify either "value" or "from")
          from: embed.url   # Post's JSON path of the text to copy to the attribute (specify either "value" or "from")

defaults:                   # Default output values to use if no value is copied
  channel:                  # List of channel defaults
    - tag: title            # Element name
      text: Custom Title    # Raw inner text of the element
  items:                    # List of item defaults
    - tag: itunes:image     # Element name
      attributes:           # List of attributes to set for the element
        - name: href        # Attribute name
          value: google.com # Raw value of the attribute

overrides:                  # List of overrides
  - guid: "1"               # guid of the item to override
    tags:                   # List of tags to override
      - tag: title          # Element name
        text: Custom Title  # Raw inner text of the element
```
