#!/bin/bash

cmake \
    -D CMAKE_BUILD_TYPE:STRING=DEBUG \
    -D CMAKE_CXX_FLAGS:STRING="-Wall -Wconversion" \
    ../../
