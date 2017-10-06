"""
dot.pyx

simple cython test of accessing numpy arrays's data and compute the dot product

the C function: c_dot computes the inner product between two 1-d arrays.

"""

import cython

# import both numpy and the Cython declarations for numpy
import numpy as np
cimport numpy as np

from libcpp.memory cimport unique_ptr
from cython.operator cimport dereference as deref

from libcpp.vector cimport vector


cdef extern from "RTreePoint2D.hpp" namespace "rtrees":
    cdef cppclass RTreePoint2D:
        RTreePoint2D(int, int, int, int) except +
        int x0, y0, x1, y1
        int getLength()
        int getHeight()
        int getArea()
        void insertPoint(double, double, long)
        long size()
        vector[long] knn(double, double, int)
        void move(int, int)

cdef class PyRTreePoint2D:
    cdef unique_ptr[RTreePoint2D] thisptr
    def __cinit__(self, int x0, int y0, int x1, int y1):
        self.thisptr.reset(new RTreePoint2D(x0, y0, x1, y1))
    def getLength(self):
        return deref(self.thisptr).getLength()
    def getHeight(self):
        return deref(self.thisptr).getHeight()
    def getArea(self):
        return deref(self.thisptr).getArea()
    def move(self, dx, dy):
        deref(self.thisptr).move(dx, dy)
    def insert_point(self, x, y, value):
        deref(self.thisptr).insertPoint(x, y, value)
    def size(self):
        return deref(self.thisptr).size()
    def knn(self, x, y, k):
        return deref(self.thisptr).knn(x, y, k)
    @property
    def x0(self):
        return self.c_rect.x0
    @x0.setter
    def x0(self, x0):
        def __set__(self, x0): self.c_rect.x0 = x0
