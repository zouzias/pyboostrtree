#!/bin/bash

docker build docker-python/ -t boostrtrees
docker run -ti boostrtrees pip install --index-url https://test.pypi.org/simple/ boostrtrees && python3
