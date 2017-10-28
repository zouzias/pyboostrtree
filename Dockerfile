FROM ubuntu:xenial

WORKDIR /opt

RUN apt-get update -qq && apt-get install -qq software-properties-common wget && \
    add-apt-repository ppa:ubuntu-toolchain-r/test -y && \
    apt-get update -qq

# Install numpy, cython
RUN apt-get install -y python3 python3-dev python3-pip && pip3 install --upgrade pip
RUN pip3 install cython numpy

# Install boost 1.65.1
RUN wget https://sourceforge.net/projects/boost/files/boost/1.65.1/boost_1_65_1.tar.gz
RUN mkdir -p /usr/include/boost
RUN tar zxvf boost_1_65_1.tar.gz -C /usr/include/boost/
ENV BOOST_ROOT /usr/include/boost/boost_1_65_1

ADD . /opt

# Upload boostrtrees to PyPi
RUN python3 setup.py sdist bdist_wheel
