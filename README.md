# m64core
M64Core is the first ever cross-platform emulator dedicated to *Super Mario 64* machinima.<br>
Built with mupen64plus and Qt5.

![windows](https://raw.githubusercontent.com/Llennpie/m64core/master/ss-windows10.png)

## Requirements
NOTE: *These have been tested on Ubuntu 20.04 and Windows 10 (MSYS2) only. Dependencies may change per distribution or OS.*

#### Ubuntu 20.04
```
sudo apt install qt5-default libqt5websockets5 libsdl2-2.0-0 libsdl2-net-2.0-0 libhidapi-hidraw0 libminizip1 p7zip-full libsdl2-dev libhidapi-dev
```
#### Windows 10
Requires [MSYS2](https://www.msys2.org/). This has only been tested with MinGW 64-bit.
```
pacman -S make mingw-w64-x86_64-SDL2 mingw-w64-x86_64-qt5 mingw-w64-x86_64-gcc mingw-w64-x86_64-SDL2_net mingw-w64-x86_64-hidapi mingw-w64-x86_64-minizip p7zip mingw-w64-x86_64-libsamplerate mingw-w64-x86_64-cmake zip
```

There are plans to release M64Core on **Mac OSX**.<br>
Check [loganmc10/m64p](https://github.com/loganmc10/m64p) for dependencies.

## Building
```
$ git clone https://github.com/Llennpie/m64core
$ cd m64core
$ ./build.sh
```

## Special Thanks
- [mupen64plus](https://github.com/mupen64plus)
- loganmc10 (creator of [m64p](https://m64p.github.io/) and [mupen64plus-gui](https://github.com/m64p/mupen64plus-gui))
- GlitchyPSI (creator of [M64MM3](https://github.com/projectcomet64/M64MM))
