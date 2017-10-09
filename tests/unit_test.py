#!/usr/bin/env python

"""
boostrtrees.pyx and RTreePoint2D.cpp test code

designed to be run-able with py.test
"""
import pytest
from boostrtrees import PyRTreePoint2D, np


def test_insert_points():
    rec_ptr = PyRTreePoint2D()
    pts = [(1.0,2.0,10),(1.0,4.0,11.0),(3.0,5.0,12),(5.0,7.0,13)]
    rec_ptr.insert_points(pts)
    assert (rec_ptr.size() == 4)


def test_size():
    rec_ptr = PyRTreePoint2D()
    assert(rec_ptr.size() == 0)
    rec_ptr.insert_point(1, 2, 10)
    assert(rec_ptr.size() == 1)
    rec_ptr.insert_point(3, 4, 10)
    assert (rec_ptr.size() == 2)
    rec_ptr.insert_point(3, 4, 10)
    assert (rec_ptr.size() == 3)


def test_knn():
    rec_ptr = PyRTreePoint2D()
    rec_ptr.insert_point(1, 2, 1)
    rec_ptr.insert_point(3, 4, 2)
    rec_ptr.insert_point(5, 6, 3)
    rec_ptr.insert_point(8, 9, 4)
    assert (rec_ptr.knn(5, 6, 2) == [3, 2])


def test_bounds():
    rec_ptr = PyRTreePoint2D()
    rec_ptr.insert_point(3, 5, 10)
    rec_ptr.insert_point(6, 7, 10)
    assert rec_ptr.bounds() == {'min_x': 3.0, 'max_x': 6.0, 'min_y': 5.0, 'max_y': 7.0}
