#!/bin/bash

docker build docker-python/ -t boostrtrees
docker run -t -v `pwd`:/opt/python-package/ boostrtrees make clean
docker run -t -v `pwd`:/opt/python-package/ boostrtrees python3 setup.py sdist bdist_wheel
