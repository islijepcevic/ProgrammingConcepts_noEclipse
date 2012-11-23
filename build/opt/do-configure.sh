#!/bin/bash

rm CMakeCache.txt

cmake \
    -D CMAKE_BUILD_TYPE:STRING=RELEASE \
    -D CMAKE_CXX_COMPILER:STRING=mpicxx \
    -D CMAKE_CXX_FLAGS:STRING="-Wall -Wconversion" \
    ../../
