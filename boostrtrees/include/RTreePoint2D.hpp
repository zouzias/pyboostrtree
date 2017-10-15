#pragma once

#include "BoostGeometryTypes.hpp"

namespace rtrees {

class RTreePoint2D {
public:

    RTreePoint2D();

    ~RTreePoint2D();

    /**
     * K-nearest neighbor search using Rtree
     *
     * @param x
     * @param y
     * @param k Number of nearest neighbors to return
     * @return
     */
    std::vector<long> knn(double x, double y, int k);

    /**
     * Insert a point with value in Rtree
     * @param x
     * @param y
     * @param value
     */
    void insertPoint(double x, double y, long value);

    /**
     * Inserts points from numpy 2D array
     *
     * @param points Numpy array containing rows (x, y, value)
     * @param m Number of points to be inserted (rows)
     * @param n Number of columns (must equal to 3)
     */
    void insertPoints(double* points, long m, long n);

    /**
     * Returns bounding box containing all points
     * @return A vector of size 4 containing [min_x, min_y, max_x, max_y]
     */
    std::vector<double> bounds();

    /**
     * Returns number of points in Rtree
     * @return
     */
    long size();

private:

    /**
     * Instantiate an Rtree
     */
    bgi::rtree< value, bgi::rstar<16, 4> > rtree;
};

} // end namespace rtree
