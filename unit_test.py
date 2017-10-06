#!/usr/bin/env python

"""
boostrtrees.pyx and RTreePoint2D.cpp test code

designed to be run-able with py.test
"""
import pytest
from boostrtrees import PyRTreePoint2D, np
def test_area():
    rec_ptr = PyRTreePoint2D(1, 2, 3, 4)
    rec_ptr.insert_point(1, 2, 10)
    assert(rec_ptr.size() == 1)
    rec_ptr.insert_point(3, 4, 10)
    assert (rec_ptr.size() == 2)
    rec_ptr.insert_point(3, 4, 10)
    assert (rec_ptr.size() == 3)

def test_size():
    rec_ptr = PyRTreePoint2D(1, 2, 3, 4)
    expectedArea = 4
    recArea = rec_ptr.getArea()
    assert np.abs(recArea - expectedArea) < 10e-3
