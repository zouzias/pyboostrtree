#!/usr/bin/env python

"""
boostrtrees.pyx and RTreePoint2D.cpp test code

designed to be run-able with py.test
"""
import pytest
from boostrtrees import PyRTreePoint2D, np

def test_size():
    rec_ptr = PyRTreePoint2D(1, 2, 3, 4)
    assert(rec_ptr.size() == 0)
    rec_ptr.insert_point(1, 2, 10)
    assert(rec_ptr.size() == 1)
    rec_ptr.insert_point(3, 4, 10)
    assert (rec_ptr.size() == 2)
    rec_ptr.insert_point(3, 4, 10)
    assert (rec_ptr.size() == 3)


def test_knn():
    rec_ptr = PyRTreePoint2D(1, 2, 3, 4)
    rec_ptr.insert_point(1, 2, 1)
    rec_ptr.insert_point(3, 4, 2)
    rec_ptr.insert_point(5, 6, 3)
    rec_ptr.insert_point(8, 9, 4)
    assert (rec_ptr.knn(5, 6, 2) == [3, 2])

def test_bounds():
    rec_ptr = PyRTreePoint2D(1, 2, 3, 4)
    rec_ptr.insert_point(3, 4, 10)
    rec_ptr.insert_point(4, 3, 10)
    assert rec_ptr.bounds() == [3.0, 3.0, 4.0, 4.0]
