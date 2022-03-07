#!/bin/sh
# Sherpa installation script
# This script compiles the Sherpa source files into executable binaries, and moves them into their appropriate locations

echo "Compiling Sherpa..."
gcc -O2 -Wall $(pkg-config --cflags vte-2.91) ../sherpa.c -o Sherpa $(pkg-config --libs vte-2.91) # Compile main Sherpa binary
echo "CC sherpa.c"
echo "Compiling sherpa-version..."
gcc -O2 -Wall ../sherpa-version.c # Compile Sherpa version script
echo "CC sherpa-version.c"
cp ../a.out ../sherpa-version.c
mv sherpa /usr/bin
mv sherpa-version /usr/bin
