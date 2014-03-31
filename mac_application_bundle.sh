#!/bin/sh

#
# This script creates an application bundle in the current directory based on
# the locally installed game. Make sure you compiled and installed before
# running this script.
#
# Also, SDL should be installed in /usr/local. If not, change the location in
# the lines below
#
# Based on http://stackoverflow.com/questions/1596945/building-osx-app-bundle
#

# Create application bundle
mkdir -p SmashBattle.app/Contents/MacOS
mkdir -p SmashBattle.app/Contents/Resources

# Copy main content into application bundle
cp -r /usr/share/games/smashbattle/* SmashBattle.app/Contents/MacOS

# Copy libraries into application bundle
cp /usr/local/lib/libSDL-1.2.0.dylib SmashBattle.app/Contents/MacOS
cp /usr/local/lib/libSDL_mixer-1.2.0.dylib SmashBattle.app/Contents/MacOS
cp /usr/local/lib/libSDL_net-1.2.0.dylib SmashBattle.app/Contents/MacOS

chmod 766 SmashBattle.app/Contents/MacOS/libSDL*

# Change location of linked libraries
install_name_tool -change /usr/local/lib/libSDL-1.2.0.dylib @executable_path/libSDL-1.2.0.dylib SmashBattle.app/Contents/MacOS/smashbattle
install_name_tool -change /usr/local/lib/libSDL-1.2.0.dylib @executable_path/libSDL-1.2.0.dylib SmashBattle.app/Contents/MacOS/libSDL-1.2.0.dylib
install_name_tool -change /usr/local/lib/libSDL-1.2.0.dylib @executable_path/libSDL-1.2.0.dylib SmashBattle.app/Contents/MacOS/libSDL_mixer-1.2.0.dylib
install_name_tool -change /usr/local/lib/libSDL-1.2.0.dylib @executable_path/libSDL-1.2.0.dylib SmashBattle.app/Contents/MacOS/libSDL_net-1.2.0.dylib
install_name_tool -change /usr/local/lib/libSDL_mixer-1.2.0.dylib @executable_path/libSDL_mixer-1.2.0.dylib SmashBattle.app/Contents/MacOS/smashbattle
install_name_tool -change /usr/local/lib/libSDL_net-1.2.0.dylib @executable_path/libSDL_net-1.2.0.dylib SmashBattle.app/Contents/MacOS/smashbattle

# Copy launcher into application bundle
cp scripts/mac/launcher SmashBattle.app/Contents/MacOS

# Copy icons into application bundle
cp scripts/mac/SB.icns SmashBattle.app/Contents/Resources

# Copy info.plist into application bundle
cp scripts/mac/Info.plist SmashBattle.app/Contents
