#!/bin/bash

# Build wheels using the manylinux approach for both x86_64 and i686
make clean
docker build docker-manylinux1_x86_64/ -t manylinux1_x86_64
docker run --rm -v `pwd`:/io manylinux1_x86_64 /io/travis/build-wheels.sh

export PRE_CMD=linux32
docker build docker-manylinux1_i686/ -t manylinux1_i686
docker run --rm -v `pwd`:/io manylinux1_i686 /io/travis/build-wheels.sh
