FROM quay.io/pypa/manylinux1_x86_64


RUN yum install -y wget
ENV BOOST_VERSION=1.67.0
ENV BOOST_VERSION_=1_67.0
RUN wget --no-check-certificate https://sourceforge.net/projects/boost/files/boost/${BOOST_VERSION}/boost_${BOOST_VERSION_}.tar.gz

RUN tar zxf boost_${BOOST_VERSION_}.tar.gz -C /opt/
ENV BOOST_ROOT=/opt/boost_${BOOST_VERSION_}
