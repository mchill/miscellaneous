# Audiobook RSS

I have a need to self-host some audiobooks. There are a few options for Android apps, but I found all of the ones that I tried to have significant problems. The best option seems to be Plex for hosting and Prologue for streaming, but that is only available for iOS.

Meanwhile, there are several mature and feature-rich podcast apps available. All that I need to take advantage of those apps is a small script to convert a directory of chapter audio files to an RSS feed, and a static file server.

## Usage

1. Structure your files. The only strict requirement is that they are ordered alphabetically. It is also recommended to avoid spaces and special characters in folder names to make the feed url easier to type. For example:

    ```
      audiobooks/
        Author_Name/
          Book_Title/
            Chapter 01 - Title.mp3
            Chapter 02 - Title.mp3
    ```

2. Create a configuration file. Each book is configured with a simple yaml file.

    ```yaml
    directory: /path/to/book/               # Path with existing audio files
    base_url: https://my.site/path/to/book/ # Base url to serve files from
    title: Title                            # Book title
    author: Author                          # Author name
    image: https://site.com/image.jpg       # Cover image
    date: 2000/01/01                        # Release date
    description: |                          # Book description
      Description
      Can be multiple lines.
    ```

3. Generate the RSS feed:

    ```bash
    python convert.py --config config.yaml
    ```
