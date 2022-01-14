# Sherpa

![alt text](https://raw.githubusercontent.com/amogus3016/amogus3016/main/sherpa%20logo.png)

The simplest terminal around

Sherpa is a lightweight terminal for Linux. Developed for Everest Linux. Provides a strong baseline for customization.

**Installation**

Download one of the precompiled binaries on the releases page

**OR**

Clone this reository to any directory (EXCEPT /tmp), then run: `gcc -O2 -Wall $(pkg-config --cflags vte-2.91) sherpa.c -o sherpa $(pkg-config --libs vte-2.91)`, then run `make`

**Features**

Lightweight terminal emulator out of the box

Strong base to customize

Less lines of code than most terminal emulators (including st)

**Notes**

Runs on any GTK capable system. This includes KDE Plasma.
