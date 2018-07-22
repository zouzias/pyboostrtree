#!/usr/bin/env python

import sys
import os
import re
import io
import numpy
from glob import glob
from os import path
from setuptools import setup, find_packages
from setuptools.extension import Extension
from Cython.Distutils import build_ext


here = path.abspath(path.dirname(__file__))

# Get the long description from the README file
with open(path.join(here, 'README.rst')) as f:
    long_description = f.read()

__version__ = re.search(
    r'__version__\s*=\s*[\'"]([^\'"]*)[\'"]',  # It excludes inline comment too
    io.open('version.py', encoding='utf_8').read()
    ).group(1)


compile_args = ['-Wall', '-g', '-std=c++11']

# Last argument is required, see https://stackoverflow.com/questions/47978722/missing-c-std-library-methods-and-other-errors-while-compiling-eos-on-ubuntu-1
if sys.platform == 'darwin':
    compile_args.append('-mmacosx-version-min=10.7')
    compile_args.append('-stdlib=libc++')

if 'BOOST_ROOT' not in os.environ:
    print('=' * 40)
    print('|  You must install Boost >= 1.59.0         |')
    print('|  and set BOOST_ROOT to boost include dir  |')
    print('|  MacOS: `brew install boost`              |')
    print('|  Ubuntu: apt-get install libboost-all-dev |')
    print('|  Manually: wget https://sourceforge.net/projects/boost/files/boost/1.65.1/boost_1_65_1.tar.gz|')
    print('=' * 40)

print('Using boost from BOOST_ROOT = {}'.format(os.environ['BOOST_ROOT']))

sources = glob("*.pyx") + glob("src/*.cpp")

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
    setup_requires=['Cython >= 0.18'],
    install_requires=['numpy', 'cython'],
    cmdclass={'build_ext': build_ext},
    ext_modules=[Extension("boostrtrees",
                           sources=sources,
                           language="c++",
                           extra_compile_args=compile_args,
                           include_dirs=[numpy.get_include(), os.environ['BOOST_ROOT'], 'include']
                           )],
    keywords=['c++ boost geometry rtree'],
    zip_safe=False,
    classifiers=[
        'Development Status :: 3 - Alpha',
        'Intended Audience :: Developers',
        'Operating System :: POSIX :: Linux',
        'Programming Language :: Cython',
        'Programming Language :: C++',
        'Programming Language :: Python :: 2.7',
        'Programming Language :: Python :: 3.5',
        'Programming Language :: Python :: 3.6',
        'Topic :: Software Development :: Libraries']
)
