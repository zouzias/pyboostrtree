#!/bin/bash

# Builds and test the python package within  a virtualenv

# Package version
VERSION=`cat version.py | awk '{print $3}' | sed "s/'//g"`

rm -rf env/
rm -rf dist/

make clean
pip install virtualenv cython disttools
python setup.py sdist

virtualenv env
source env/bin/activate
env/bin/pip install numpy cython
env/bin/pip install  --upgrade dist/boostrtrees-${VERSION}.tar.gz
python -c 'from boostrtrees import RTree'
deactivate
