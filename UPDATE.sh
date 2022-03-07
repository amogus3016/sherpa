#!/bin/sh
# Sherpa update script
# This script compiles the Sherpa source files into executable binaries, removes the outdated binaries, and replaces them with the updated binaries

echo "Updating Sherpa..."
gcc -O2 -Wall $(pkg-config --cflags vte-2.91) sherpa.c -o sherpa $(pkg-config --libs vte-2.91) # Compile main Sherpa binary
echo "CC sherpa.c"
rm /usr/bin/sherpa
mv sherpa /usr/bin
echo "+----------------------------------------------+"
echo "| Sherpa has been succesfully updated.         |"
echo "+----------------------------------------------+"
# //
#   //
#    //
#   //
#  //
