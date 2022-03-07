#!/bin/sh
# Sherpa installation script
# This script compiles the Sherpa source files into executable binaries, and moves them into their appropriate locations

echo "Compiling Sherpa..."
gcc -O2 -Wall $(pkg-config --cflags vte-2.91) /tmp/sherpa/sherpa.c -o Sherpa $(pkg-config --libs vte-2.91) # Compile main Sherpa binary
echo "CC sherpa.c"
echo "Compiling sherpa-version..."
gcc -O2 -Wall /tmp/sherpa/sherpa-version.c # Compile Sherpa version script
echo "CC sherpa-version.c"
cp /tmp/sherpa/a.out /tmp/sherpa/sherpa-version.c
mv /tmp/sherpa/sherpa /usr/bin
mv /tmp/sherpa/sherpa-version /usr/bin
