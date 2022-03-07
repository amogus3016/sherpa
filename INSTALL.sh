#!/bin/sh
# Sherpa installation script
# This script compiles the Sherpa source files into executable binaries, and moves them into their appropriate locations

echo "Compiling Sherpa..."
gcc -O2 -Wall $(pkg-config --cflags vte-2.91) sherpa.c -o sherpa $(pkg-config --libs vte-2.91) # Compile main Sherpa binary
echo "CC sherpa.c"
mv sherpa /usr/bin
echo "Sherpa was successfully installed."
echo "To update Sherpa, run the UPDATE.sh script."

//
  //
   //
  //
 //
