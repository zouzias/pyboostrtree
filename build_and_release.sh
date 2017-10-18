#!/bin/bash

rm -rf build/
rm -rf dist/
rm -rf sdist/


python setup.py sdist bdist_wheel

virtualenv sdist

sdist/bin/pip install numpy cython
sdist/bin/pip install  --upgrade dist/boostrtrees-0.0.6.tar.gz
cd sdist/
bin/python2.7 -c 'from boostrtrees import RTree'
