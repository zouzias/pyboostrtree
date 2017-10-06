#include "RTreePoint2D.hpp"
using namespace rtrees;

RTreePoint2D::RTreePoint2D(int X0, int Y0, int X1, int Y1) {
    x0 = X0;
    y0 = Y0;
    x1 = X1;
    y1 = Y1;
}

RTreePoint2D::~RTreePoint2D() {
}

int RTreePoint2D::getLength() {
    return (x1 - x0);
}

int RTreePoint2D::getHeight()
{
    return (y1 - y0);
}

void RTreePoint2D::insertPoint(double x, double y, long value)
{
    point_t p(x, y);
    this->rtree.insert(std::make_pair(p, value));
}

long RTreePoint2D::size(){
    return this->rtree.size();
}

std::vector<long> RTreePoint2D::knn(int x, int y, int k){
    point_t p(x, y);
    std::vector<value> results;
    rtree.query(bgi::nearest(p, k), std::back_inserter(results));
    std::vector<long> values;
    for (auto result : results){
        values.insert(values.begin(), result.second);
    }
    return values;
}

int RTreePoint2D::getArea() {
    return (x1 - x0) * (y1 - y0);
}

void RTreePoint2D::move(int dx, int dy) {
    x0 += dx;
    y0 += dy;
    x1 += dx;
    y1 += dy;
}

