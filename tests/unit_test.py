#!/usr/bin/env python

"""
boostrtrees.pyx and Rtree test code

designed to be run-able with py.test
"""
import pytest
import numpy as np
from boostrtrees import RTree
import math


def test_size():
    rec_ptr = RTree()
    assert(rec_ptr.size() == 0)
    rec_ptr.insert_point(1, 2, 10)
    assert(rec_ptr.size() == 1)
    rec_ptr.insert_point(3, 4, 10)
    assert (rec_ptr.size() == 2)
    rec_ptr.insert_point(3, 4, 10)
    assert (rec_ptr.size() == 3)


def test_knn():
    rec_ptr = RTree()
    rec_ptr.insert_point(1, 2, 1)
    rec_ptr.insert_point(3, 4, 2)
    rec_ptr.insert_point(5, 6, 3)
    rec_ptr.insert_point(8, 9, 4)
    assert (rec_ptr.knn(5, 6, 2) == [3, 2])


def test_bounds():
    rec_ptr = RTree()
    rec_ptr.insert_point(3, 5, 10)
    rec_ptr.insert_point(6, 7, 10)
    assert rec_ptr.bounds() == {'min_x': 3.0, 'max_x': 6.0, 'min_y': 5.0, 'max_y': 7.0}


def test_insert_numpy_points_size():
    rec_ptr = RTree()
    pts = np.array([(1.0, 2.0, 10), (1.0, 4.0, 11.0),
                    (3.0, 5.0, 12), (5.0, 7.0, 13)])
    rec_ptr.insert_points(pts)
    assert (rec_ptr.size() == 4)


def test_insert_numpy_points_bounds():
    rec_ptr = RTree()
    pts = np.array([(1.0, 2.0, 10), (1.0, 4.0, 11.0),
                    (3.0, 5.0, 12), (5.0, 7.0, 13)])
    rec_ptr.insert_points(pts)
    assert rec_ptr.bounds() == {'min_x': 1.0, 'max_x': 5.0, 'min_y': 2.0, 'max_y': 7.0}


def test_insert_numpy_points_withquery():
    rec_ptr = RTree()
    pts = np.array([(1.0, 2.0, 10), (1.0, 4.0, 11.0),
                    (3.0, 5.0, 12), (5.0, 7.0, 13)])
    rec_ptr.insert_points(pts)
    nn = rec_ptr.knn(0.0, 0.0, 1)
    assert nn == [10]


def test_minimum_distance():
    rec_ptr = RTree()
    pts = np.array([(1.0, 2.0, 10), (1.0, 4.0, 11.0),
                    (3.0, 5.0, 12), (5.0, 7.0, 13)])
    rec_ptr.insert_points(pts)
    dist = rec_ptr.min_distance(0.0, 0.0)
    assert math.fabs(dist - math.sqrt(5.0)) < 10e-5
    dist = rec_ptr.min_distance(7.0, 9.0)
    assert math.fabs(dist - math.sqrt(8.0)) < 10e-5
