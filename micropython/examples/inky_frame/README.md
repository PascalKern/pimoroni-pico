# Pico Enviro+ MicroPython Examples <!-- omit in toc -->

- [PicoGraphics](#picographics)
- [Examples](#examples)
  - [Daily Activity](#daily-activity)
  - [News](#news)
  - [PlaceKitten](#placekitten)
  - [Quote of the Day](#quote-of-the-day)
  - [Random Joke](#random-joke)
  - [XKCD Daily](#xkcd-daily)

## PicoGraphics

You can draw on Inky Frame using our tiny PicoGraphics display library.
- [PicoGraphics MicroPython function reference](../../modules/picographics)

## Examples

The examples need `network_manager.py` and `WIFI_CONFIG.py` from the `common` directory to be saved to your Pico W. Open up `WIFI_CONFIG.py` in Thonny to add your wifi details (and save it when you're done).

You'll also need to install the `micropython-urllib.urequest` library using Thonny's 'Tools' > 'Manage Packages' or `common/lib/urllib` which contains a compiled `.mpy` version that uses less RAM. You should place this directory in `lib` on your Pico W.

Finally for examples loading images, you'll need `sdcard.mpy` from `common/lib`. You should place this file in `lib` on your Pico W.

### Daily Activity
[inky_frame_daily_activity.py](inky_frame_daily_activity.py)

### News
[inky_frame_news.py](inky_frame_news.py)

Display headlines from BBC news.

### PlaceKitten
[inky_frame_placekitten.py](inky_frame_placekitten.py)

Download a random (from a small subset) image from PlaceKitten.

### Quote of the Day
[inky_frame_quote_of_the_day.py](inky_frame_quote_of_the_day.py)

Load the WikiQuotes Quote of the Day and display it.

### Random Joke
[inky_frame_random_joke.py](inky_frame_random_joke.py)

Load a random joke from JokeAPI.dev and display it.

Jokes are rendered into images "offline" by our feed2image service for two reasons:

1. Saves the Pico W having to process them
2. JokeAPI.dev needs TLS1.3 which Pico W does not support!

For bugs/contributions or to complain about a joke, see: https://github.com/pimoroni/feed2image

### XKCD Daily
[inky_frame_xkcd_daily.py](inky_frame_xkcd_daily.py)

Download and display the daily webcomic from https://xkcd.com/

The webcomic is rendered "offline" by our feed2image service since xkcd.com requires TLS1.3!

For bugs/contributions see: https://github.com/pimoroni/feed2image
