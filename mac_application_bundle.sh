#!/bin/sh

# Create application bundle
mkdir -p SmashBattle.app/Contents/MacOS
mkdir -p SmashBattle.app/Contents/Resources

# Copy main content into application bundle
cp -r /usr/share/games/smashbattle/* SmashBattle.app/Contents/MacOS

# Copy libraries into application bundle
cp /usr/local/lib/libSDL-1.2.0.dylib SmashBattle.app/Contents/MacOS
cp /usr/local/lib/libSDL_mixer-1.2.0.dylib SmashBattle.app/Contents/MacOS
cp /usr/local/lib/libSDL_net-1.2.0.dylib SmashBattle.app/Contents/MacOS

# Change location of linked libraries
install_name_tool -change /usr/local/lib/libSDL-1.2.0.dylib @executable_path/libSDL-1.2.0.dylib SmashBattle.app/Contents/MacOS/smashbattle
install_name_tool -change /usr/local/lib/libSDL_mixer-1.2.0.dylib @executable_path/libSDL_mixer-1.2.0.dylib SmashBattle.app/Contents/MacOS/smashbattle
install_name_tool -change /usr/local/lib/libSDL_net-1.2.0.dylib @executable_path/libSDL_net-1.2.0.dylib SmashBattle.app/Contents/MacOS/smashbattle

# Copy icons into application bundle
cp scripts/mac/SB.icns SmashBattle.app/Contents/Resources

# Copy info.plist into application bundle
cp scripts/mac/Info.plist SmashBattle.app/Contents
