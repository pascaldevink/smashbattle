# MAC OS X Installation

## Install prerequisites

    brew install sdl sdl_net sdl_mixer

## Building

    cmake -DCMAKE_CXX_FLAGS=-Wno-narrowing .
    make

## Installation

    sudo make install

## Creation of application bundle

    mac_application_bundle.sh

## About the application bundle

* Both all the actual game files and the SDL libraries go into SmashBattle.app/Contents/MacOS/
* The name of the app, icon and executable are defined in the Info.plist. This is copied from scripts/mac
* The icon(s) are in the SB.icns in the SmashBattle.app/Contents/Resources folder. This is copied from scripts/mac
