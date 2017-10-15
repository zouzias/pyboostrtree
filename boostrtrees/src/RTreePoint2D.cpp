#include "RTreePoint2D.hpp"
#include <cassert>

using namespace rtrees;

RTreePoint2D::RTreePoint2D() {
}

RTreePoint2D::~RTreePoint2D() {
}


void RTreePoint2D::insertPoint(double x, double y, long value)
{
    point_t p(x, y);
    this->rtree.insert(std::make_pair(p, value));
}

void RTreePoint2D::insertPoints(double* points, long m, long n)
{
    assert(n == 3); // points should be an m x 3 matrix

    for (long i = 0 ; i < m * n; i = i + 3){
        point_t p(points[i], points[i + 1]);
        this->rtree.insert(std::make_pair(p, points[i + 2]));
    }
}


long RTreePoint2D::size(){
    return this->rtree.size();
}

std::vector<long> RTreePoint2D::knn(double x, double y, int k){
    point_t p(x, y);
    std::vector<value> results;
    rtree.query(bgi::nearest(p, k), std::back_inserter(results));
    std::vector<long> values;
    for (auto result : results){
        values.insert(values.begin(), result.second);
    }
    return values;
}

std::vector<double> RTreePoint2D::bounds(){
    auto bbox = this->rtree.bounds();
    auto min_corner = bbox.min_corner();
    auto max_corner = bbox.max_corner();
    std::vector<double> boundaries;

    boundaries.push_back(bg::get<0>(min_corner));
    boundaries.push_back(bg::get<1>(min_corner));
    boundaries.push_back(bg::get<0>(max_corner));
    boundaries.push_back(bg::get<1>(max_corner));

    return boundaries;
}
