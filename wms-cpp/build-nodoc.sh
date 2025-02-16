#!/bin/bash
mkdir out out/build
cd out/build
cmake -DCLOSE_SWAGGER_DOC=1 ../../
make
make install