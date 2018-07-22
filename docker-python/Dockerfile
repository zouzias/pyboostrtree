FROM ubuntu:xenial

MAINTAINER Anastasios Zouzias <my_last_name@gmail.com>

WORKDIR /opt

RUN apt-get update -qq && apt-get install -qq software-properties-common wget && \
    add-apt-repository ppa:ubuntu-toolchain-r/test -y && \
    apt-get update -qq

# Install Python with packages numpy, cython
RUN apt-get install -y python3 python3-dev python3-pip && \
    pip3 install --upgrade pip && \
    pip3 install cython numpy

# Install Boost C++ 1.67.0
RUN wget https://sourceforge.net/projects/boost/files/boost/1.67.0/boost_1_67_0.tar.gz
RUN mkdir -p /usr/include/boost
RUN tar zxvf boost_1_67_0.tar.gz -C /usr/include/boost/
ENV BOOST_ROOT /usr/include/boost/boost_1_67_0

WORKDIR /opt/python-package
