#!/bin/bash

# Builds and test the python package within  a virtualenv

# Package version
VERSION=`cat version.py | awk '{print $3}' | sed "s/'//g"`

rm -rf sdist/

make clean
pip install cython disttools
python setup.py sdist

virtualenv sdist
source sdist/bin/activate
sdist/bin/pip install numpy cython pandas
sdist/bin/pip install  --upgrade dist/boostrtrees-${VERSION}.tar.gz
cd benchmarks/ && python benchmark.py
