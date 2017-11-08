#!/bin/bash

make clean
docker build docker-manylinux1/ -t manylinux1
docker run --rm -v `pwd`:/io manylinux1 /io/travis/build-wheels.sh
