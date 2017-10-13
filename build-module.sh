#!/usr/bin/env bash

python setup.py build_ext --inplace
mv *.so boostrtrees/

