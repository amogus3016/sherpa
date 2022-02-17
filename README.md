# Sherpa

![alt text](https://raw.githubusercontent.com/amogus3016/amogus3016/main/sherpa%20logo.png)

The simplest terminal around

Sherpa is a lightweight terminal for Linux. Developed for Everest Linux. Provides a strong baseline for customization.

**Installation**

Download one of the precompiled binaries on the releases page

**OR**

Clone this reository to /tmp, then run: `gcc -O2 -Wall $(pkg-config --cflags vte-2.91) sherpa.c -o sherpa $(pkg-config --libs vte-2.91)` to compile the main executable. Run `gcc -O2 -Wall sherpa-version.c` to compile the version script (optional), then move the executable to /usr/bin by running: `sudo mv /path/to/executable /usr/bin`. Do the same with the version script (you must rename it first)

**Features**

Lightweight terminal emulator out of the box

Strong base to customize

Less lines of code than most terminal emulators (including st)

**Notes**

Runs on any GTK capable system. This includes KDE Plasma.
