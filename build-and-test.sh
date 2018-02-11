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
sdist/bin/pip install numpy cython
sdist/bin/pip install  --upgrade dist/boostrtrees-${VERSION}.tar.gz
cd sdist/ && python -c 'from boostrtrees import RTree'
