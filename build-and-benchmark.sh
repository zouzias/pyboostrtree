#!/bin/bash

# Build and benchmark the python package within a virtualenv

# Package version
VERSION=`cat version.py | awk '{print $3}' | sed "s/'//g"`

rm -rf env/
rm -rf dist/

make clean
pip install cython disttools
python setup.py sdist

virtualenv env/
source env/bin/activate
env/bin/pip install numpy cython pandas
env/bin/pip install  --upgrade dist/boostrtrees-${VERSION}.tar.gz
cd benchmarks/ && python benchmark.py
