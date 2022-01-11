# Sherpa

![alt text](https://raw.githubusercontent.com/amogus3016/amogus3016/main/sherpa%20logo.png)

The simplest terminal around

Sherpa is a lightweight terminal for unix-like operating systems. Developed for Everest Linux. Provides a strong baseline for customization.

**Installation**

Download one of the precompiled binaries on the releases page

**OR**

Clone this reository to any directory (EXCEPT /tmp), then run: `gcc -O2 -Wall $(pkg-config --cflags vte-2.91) sherpa.c -o sherpa $(pkg-config --libs vte-2.91)`, then run `make`

**Notes**

At the moment, sherpa only runs on GTK based desktop environments. Expect a Qt version in the near future.
