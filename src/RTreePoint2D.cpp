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

double RTreePoint2D::minDistance(double x, double y){
    point_t p(x, y);
    std::vector<value> results;
    rtree.query(bgi::nearest(p, 1), std::back_inserter(results));

    double dist = std::numeric_limits<double>::max();
	for ( const value& v: results){
		double localDist = bg::distance(p, v.first);
		if (localDist < dist) dist = localDist;
	}

    return dist;
}

std::vector<long> RTreePoint2D::intersection(double* coords){

    _sortMinMaxCorners(coords, 2, 2);
    point_t minp(coords[0], coords[1]), maxp(coords[2], coords[3]);
    bbox query_box(minp, maxp);

    std::vector<value> results;
    rtree.query(bgi::intersects(query_box), std::back_inserter(results));
    std::vector<long> values;
    for (auto result : results){
        values.insert(values.begin(), result.second);
    }
    return values;
}

void RTreePoint2D::removePoints(double* points, long m, long n){
    assert(n == 3); // points should be an m x 3 matrix

    for (long i = 0 ; i < m * n; i = i + n){
        point_t p(points[i], points[i + 1]);
        this->rtree.remove(std::make_pair(p, long(points[i + n-1])));
    }
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

void RTreePoint2D::_sortMinMaxCorners(double* points, long m, long n)
{
    assert(n == 2);
    assert(m == 2);

    double temp = 0.0;
    for (long i = 0 ; i < n; i++){
        if(points[i] > points[i+n]){
            temp = points[i];
            points[i] = points[i+n];
            points[i+n] = temp;
        }
    }
}