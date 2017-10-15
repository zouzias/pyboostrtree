"""
boostrtrees.pyx

Cython wrapper of Boost C++ geometry rtree
"""

import cython

import numpy as np
cimport numpy as np

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
        void insertPoints(double* , long, long)
        long size()
        vector[long] knn(double, double, int)
        vector[double] bounds()
        void move(int, int)

@cython.boundscheck(False)
@cython.wraparound(False)
cdef class PyRTreePoint2D:
    cdef unique_ptr[RTreePoint2D] thisptr
    def __cinit__(self):
        self.thisptr.reset(new RTreePoint2D())
    def insert_point(self, double x, double y, long value):
        deref(self.thisptr).insertPoint(x, y, value)
    def insert_points(self, np.ndarray[double, ndim=2, mode="c"] points not None):
        cdef long m, n
        m, n = points.shape[0], points.shape[1]
        assert(n == 3, "Input matrix must have 3 columns (x, y, value)")
        deref(self.thisptr).insertPoints(&points[0,0], m, n)
    def bounds(self):
        bnds = deref(self.thisptr).bounds()
        return {'min_x': bnds[0], 'max_x': bnds[2], 'min_y': bnds[1], 'max_y': bnds[3]}
    def size(self):
        return deref(self.thisptr).size()
    def knn(self, double x, double y, int k):
        return deref(self.thisptr).knn(x, y, k)