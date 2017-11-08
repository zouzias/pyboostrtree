FROM quay.io/pypa/manylinux1_i686


RUN yum install -y wget
ENV BOOST_VERSION=1.65.1
ENV BOOST_VERSION_=1_65_1
RUN wget --no-check-certificate https://sourceforge.net/projects/boost/files/boost/${BOOST_VERSION}/boost_${BOOST_VERSION_}.tar.gz

RUN tar zxf boost_${BOOST_VERSION_}.tar.gz -C /opt/
ENV BOOST_ROOT=/opt/boost_${BOOST_VERSION_}
