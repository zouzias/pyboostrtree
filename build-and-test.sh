#!/bin/bash

# Builds and test the python package with  a virtualenv

VERSION=`cat version.py | awk '{print $3}' | sed "s/'//g"`

rm -rf sdist/

make clean
python setup.py sdist

virtualenv sdist
sdist/bin/pip install numpy cython
sdist/bin/pip install  --upgrade dist/boostrtrees-${VERSION}.tar.gz
cd sdist/
bin/python2.7 -c 'from boostrtrees import RTree'
