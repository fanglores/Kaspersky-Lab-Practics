#!/bin/bash

BUILD=$PWD/build
mkdir -p $BUILD && cd $BUILD

export LANG=C
export TARGET="arm-kos"
export PKG_CONFIG=""
export SDK_PREFIX="/opt/KasperskyOS-Community-Edition-1.0.1.4"
BUILD_SIM_TARGET="y"
export PATH="$SDK_PREFIX/toolchain/bin:$PATH"

cmake -G "Unix Makefiles" \
      -D CMAKE_BUILD_TYPE:STRING=Debug \
      -D CMAKE_INSTALL_PREFIX:STRING=$BUILD/../install \
      -D CMAKE_TOOLCHAIN_FILE=$SDK_PREFIX/toolchain/share/toolchain-arm-kos.cmake \
      ../ && make kos-image
