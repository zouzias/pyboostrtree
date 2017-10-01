#!/usr/bin/env python

"""
rect.pyx and Rectangle.cpp test code

designed to be run-able with py.test
"""
import pytest
from rect import *

def test_area():
    rec_ptr = PyRectangle(1, 2, 3, 4)
    expectedArea = 4
    recArea = rec_ptr.getArea()
    assert np.abs(recArea - expectedArea) < 10e-3
