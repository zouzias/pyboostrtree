#!/usr/bin/env python

import sys, os
from distutils.core import setup
from distutils.extension import Extension
from Cython.Distutils import build_ext

import numpy

compile_args = ['-g', '-std=c++11', '-stdlib=libc++']

if sys.platform == 'darwin':
    compile_args.append('-mmacosx-version-min=10.7')

if 'BOOST_ROOT' not in os.environ:
    os.environ['BOOST_ROOT'] = '/usr/local/Cellar/boost/1.65.1'

print('BOOST_ROOT = {}'.format(os.environ['BOOST_ROOT']))

setup(cmdclass = {'build_ext': build_ext},
                ext_modules = [Extension("boostrtrees",
                sources=["boostrtrees.pyx", "RTreePoint2D.cpp"],
                language="c++",
                extra_compile_args=compile_args,
                include_dirs=[numpy.get_include(), os.environ['BOOST_ROOT'] + '/include'])],
)
