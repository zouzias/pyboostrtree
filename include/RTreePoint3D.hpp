#pragma once

#include "BoostGeometryTypes.hpp"

namespace rtrees {

class RTreePoint3D {
public:

    RTreePoint3D();

    ~RTreePoint3D();

    /**
     * K-nearest neighbor search using Rtree
     *
     * @param x
     * @param y
     * @param z
     * @param k Number of nearest neighbors to return
     * @return
     */
    std::vector<long> knn(double x, double y, double z, int k);

    /**
     * K-nearest neighbor search using Rtree
     *
     * @param coords Numpy array containing coordinates (x, y, z)
     * @param k Number of nearest neighbors to return
     * @return
     */
    std::vector<long> knn_np(double* coords, int k);

     /**
     * Minimum distance from Rtree
     *
     * @param x
     * @param y
     * @param z
     * @return vector of values corresponding to 
     */
    double minDistance(double x, double y, double z);

    /**
     * Insert a point with value in Rtree
     * @param x
     * @param y
     * @param z
     * @param value
     */
    void insertPoint(double x, double y, double z, long value);

    /**
     * Inserts points from numpy 3D array
     *
     * @param points Numpy array containing rows (x, y, z, value)
     * @param m Number of points to be inserted (rows)
     * @param n Number of columns (must equal to 4)
     */
    void insertPoints(double* points, long m, long n);

    /**
     * Inserts points from numpy 3D array
     *
     * @param points Numpy array containing rows (x, y, z, value)
     * @param m Number of points to be inserted (rows)
     * @param n Number of columns (must equal to 4)
     */
    void removePoints(double* points, long m, long n);

    /**
     * Returns bounding box containing all points
     * @return A vector of size 4 containing [min_x, min_y, min_z, max_x, max_y, max_z]
     */
    std::vector<double> bounds();

    /**
     * Returns points inside a 3D cuboid specified by two 3D coordinates
     *
     * @param 2 points Numpy array containing 2 rows (x, y, z)
     */
    std::vector<long> intersection(double* coords);

    /**
     * Returns number of points in Rtree
     * @return
     */
    long size();

private:

    /**
     * Instantiate a 3D Rtree
     */
    bgi::rtree< value3d, bgi::rstar<27, 9> > rtree;

    /**
     * Sort coordinates to get min and max corners
     */
    void _sortMinMaxCorners(double* points, long m, long n);

};

} // end namespace rtree
