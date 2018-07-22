FROM quay.io/pypa/manylinux1_i686


RUN yum install -y wget
ENV BOOST_VERSION_=1_67_0
RUN wget --no-check-certificate https://s3.eu-central-1.amazonaws.com/boostrtrees/boost_${BOOST_VERSION_}.tar.gz

RUN tar zxf boost_${BOOST_VERSION_}.tar.gz -C /opt/
ENV BOOST_ROOT=/opt/boost_${BOOST_VERSION_}
