#!/bin/bash

# Release to pypi test manylinux wheels
rm -rf wheelhouse/

echo "Uploading source tar.gz to pypitest"
python setup.py sdist
twine upload -r pypitest --sign dist/boostrtrees-*.tar.gz

echo "Building manylinux1 wheels"
./build-manylinux1.sh

echo "Uploading wheels to pypitest"
twine upload -r pypitest --sign wheelhouse/boostrtrees-*many*

echo "Go to https://testpypi.python.org/pypi/boostrtrees/X.Y.Z to check the release"
