#!/bin/bash
set -e -x

# Install a system package required by our library
yum -y update
yum install -y boost

ls -al /opt/python/
rm -rf /opt/python/cp26-*
rm -rf /opt/python/cp33-*
rm -rf /opt/python/cp34-*
ls -al /opt/python/

# Compile wheels
for PYBIN in /opt/python/*/bin; do
    "${PYBIN}/pip" install -r /io/dev-requirements.txt
    "${PYBIN}/pip" wheel /io/ -w wheelhouse/
done

# Bundle external shared libraries into the wheels
for whl in wheelhouse/*.whl; do
    auditwheel repair "$whl" -w /io/wheelhouse/
done

# Install packages and test
for PYBIN in /opt/python/*/bin/; do
#    "${PYBIN}/pip" install python-manylinux-demo --no-index -f /io/wheelhouse
#    (cd "$HOME"; "${PYBIN}/nosetests" pymanylinuxdemo)
done
