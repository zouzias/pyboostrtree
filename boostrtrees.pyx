"""
boostrtrees.pyx

Cython wrapper of Boost C++ geometry rtree
"""

import cython

# import both numpy and the Cython declarations for numpy
import numpy as np

from libcpp.memory cimport unique_ptr
from libcpp.vector cimport vector
from cython.operator cimport dereference as deref

from libcpp.vector cimport vector

cdef extern from "RTreePoint2D.hpp" namespace "rtrees":
    cdef cppclass RTreePoint2D:
        RTreePoint2D() except +
        void insertPoint(double, double, long)
        long size()
        vector[long] knn(double, double, int)
        vector[double] bounds()
        void move(int, int)

cdef class PyRTreePoint2D:
    cdef unique_ptr[RTreePoint2D] thisptr
    def __cinit__(self):
        self.thisptr.reset(new RTreePoint2D())
    def insert_point(self, double x, double y, long value):
        deref(self.thisptr).insertPoint(x, y, value)
    def insert_points(self, points):
        for (x, y, value) in points:
            deref(self.thisptr).insertPoint(x, y, value)
    def bounds(self):
        bnds = deref(self.thisptr).bounds()
        return {'min_x': bnds[0], 'max_x': bnds[2], 'min_y': bnds[1], 'max_y': bnds[3]}
    def size(self):
        return deref(self.thisptr).size()
    def knn(self, double x, double y, int k):
        return deref(self.thisptr).knn(x, y, k)