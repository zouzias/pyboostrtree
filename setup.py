#!/usr/bin/env python

import sys
import os
import re
import io
import numpy
from os import path
from setuptools import setup, find_packages
from setuptools.extension import Extension
from Cython.Distutils import build_ext

here = path.abspath(path.dirname(__file__))

# Get the long description from the README file
with open(path.join(here, 'README.rst'), encoding='utf-8') as f:
    long_description = f.read()

__version__ = re.search(
    r'__version__\s*=\s*[\'"]([^\'"]*)[\'"]',  # It excludes inline comment too
    io.open('version.py', encoding='utf_8').read()
    ).group(1)


compile_args = ['-Wall', '-g', '-std=c++11']

if sys.platform == 'darwin':
    compile_args.append('-mmacosx-version-min=10.7')
    compile_args.append('-stdlib=libc++')

if 'BOOST_ROOT' not in os.environ:
    os.environ['BOOST_ROOT'] = '/usr/local/Cellar/boost/1.65.1/include'

print('BOOST_ROOT = {}'.format(os.environ['BOOST_ROOT']))

setup(
    name="boostrtrees",
    author="Anastasios Zouzias",
    author_email="zouzias@gmail.com",
    version=__version__,
    url="https://github.com/zouzias/pyboostrtree.git",
    description="Python Wrapper of Boost Geometry Rtree",
    long_description=long_description,
    license="Apache 2.0",
    platforms=['Linux'],
    packages=find_packages(),
    install_requires=['numpy'],
    cmdclass={'build_ext': build_ext},
    ext_modules=[Extension("boostrtrees",
                           sources=["boostrtrees.pyx", "boostrtrees/src/RTreePoint2D.cpp"],
                           language="c++",
                           extra_compile_args=compile_args,
                           include_dirs=[numpy.get_include(), os.environ['BOOST_ROOT'], 'boostrtrees/include/']
                           )],
    keywords=['rtree', 'boost'],
    setup_requires=['Cython >= 0.18'],
    zip_safe=False,
    classifiers=[
        'Development Status :: 3 - Alpha',
        'Intended Audience :: Developers',
        'Operating System :: POSIX :: Linux',
        'Programming Language :: Cython',
        'Programming Language :: C++',
        'Topic :: Software Development :: Libraries'
])
