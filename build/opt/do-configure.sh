#!/bin/bash

cmake \
    -D CMAKE_BUILD_TYPE:STRING=RELEASE \
    -D CMAKE_CXX_COMPILER:STRING=mpiCC \
    -D CMAKE_CXX_FLAGS:STRING="-Wall -Wconversion" \
    ../../
