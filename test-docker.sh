#!/bin/bash

# Build a docker image with python and
# pip install boosrtrees package from test pypi

IMAGE="boostrtrees:latest"
docker rmi ${IMAGE}
docker build docker-python/ -t ${IMAGE}
docker run -ti ${IMAGE} pip install --index-url https://test.pypi.org/simple/ boostrtrees && python3
