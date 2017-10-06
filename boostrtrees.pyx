"""
dot.pyx

simple cython test of accessing numpy arrays's data and compute the dot product

the C function: c_dot computes the inner product between two 1-d arrays.

"""

import cython

# import both numpy and the Cython declarations for numpy
import numpy as np
cimport numpy as np

cdef extern from "RTreePoint2D.hpp" namespace "rtrees":
    cdef cppclass RTreePoint2D:
        RTreePoint2D(int, int, int, int) except +
        int x0, y0, x1, y1
        int getLength()
        int getHeight()
        int getArea()
        void insertPoint(double, double, long)
        long size()
        void move(int, int)

cdef class PyRTreePoint2D:
    cdef RTreePoint2D *thisptr
    def __cinit__(self, int x0, int y0, int x1, int y1):
        self.thisptr = new RTreePoint2D(x0, y0, x1, y1)
    def __dealloc__(self):
        del self.thisptr
    def getLength(self):
        return self.thisptr.getLength()
    def getHeight(self):
        return self.thisptr.getHeight()
    def getArea(self):
        return self.thisptr.getArea()
    def move(self, dx, dy):
        self.thisptr.move(dx, dy)
    def insert_point(self, x, y, value):
        self.thisptr.insertPoint(x, y, value)
    def size(self):
        return self.thisptr.size()
    @property
    def x0(self):
        return self.c_rect.x0
    @x0.setter
    def x0(self, x0):
        def __set__(self, x0): self.c_rect.x0 = x0
