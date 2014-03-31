# MAC OS X Installation

## Install prerequisites

    https://xquartz.macosforge.org

    brew install sdl --universal --with-x11-driver
    brew install sdl_net --universal
    brew install sdl_mixer --universal --with-libvorbis

## Building

    cmake -DCMAKE_CXX_FLAGS=-Wno-narrowing -DCMAKE_EXE_LINKER_FLAGS=-Wl,-headerpad_max_install_names .
    make

## Installation

    sudo make install

## Creation of application bundle

    mac_application_bundle.sh

## About the application bundle

* Both the actual game files and the SDL libraries go into SmashBattle.app/Contents/MacOS/
* The name of the app, icon and executable are defined in the Info.plist. This is copied from scripts/mac/
* The icon(s) are in the SB.icns in the SmashBattle.app/Contents/Resources/ folder. This is copied from scripts/mac/
