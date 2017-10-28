#!/bin/bash

docker build . -t boostrtrees
docker run -ti boostrtrees
