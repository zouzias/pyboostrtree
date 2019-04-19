#include "RTreePoint3D.hpp"
#include <cassert>

using namespace rtrees;

RTreePoint3D::RTreePoint3D() {
}

RTreePoint3D::~RTreePoint3D() {
}


void RTreePoint3D::insertPoint(double x, double y, double z, long value)
{
    point3d p(x, y, z);
    this->rtree.insert(std::make_pair(p, value));
}

void RTreePoint3D::insertPoints(double* points, long m, long n)
{
    assert(n == 4); // points should be an m x 4 matrix

    for (long i = 0 ; i < m * n; i = i + 4){
        point3d p(points[i], points[i + 1], points[i + 2]);
        this->rtree.insert(std::make_pair(p, long(points[i + 3])));
    }
}

long RTreePoint3D::size(){
    return this->rtree.size();
}

std::vector<long> RTreePoint3D::knn(double x, double y, double z, int k){
    point3d p(x, y, z);
    std::vector<value3d> results;
    rtree.query(bgi::nearest(p, k), std::back_inserter(results));
    std::vector<long> values;
    for (auto result : results){
        values.insert(values.begin(), result.second);
    }
    return values;
}

std::vector<long> RTreePoint3D::knn_np(double* coords, int k){
    point3d p(coords[0], coords[1], coords[2]);
    std::vector<value3d> results;
    rtree.query(bgi::nearest(p, k), std::back_inserter(results));
    std::vector<long> values;
    for (auto result : results){
        values.insert(values.begin(), result.second);
    }
    return values;
}


double RTreePoint3D::minDistance(double x, double y, double z){
    point3d p(x, y, z);
    std::vector<value3d> results;
    rtree.query(bgi::nearest(p, 1), std::back_inserter(results));

    double dist = std::numeric_limits<double>::max();
	for ( const value3d& v: results){
		double localDist = bg::distance(p, v.first);
		if (localDist < dist) dist = localDist;
	}

    return dist;
}

std::vector<double> RTreePoint3D::bounds(){
    auto bbox = this->rtree.bounds();
    auto min_corner = bbox.min_corner();
    auto max_corner = bbox.max_corner();

    std::vector<double> boundaries;
    boundaries.push_back(bg::get<0>(min_corner));
    boundaries.push_back(bg::get<1>(min_corner));
    boundaries.push_back(bg::get<2>(min_corner));
    boundaries.push_back(bg::get<0>(max_corner));
    boundaries.push_back(bg::get<1>(max_corner));
    boundaries.push_back(bg::get<2>(max_corner));

    return boundaries;
}

std::vector<long> RTreePoint3D::intersection(double* coords){

    _sortMinMaxCorners(coords, 2, 3);
    point3d minp(coords[0], coords[1], coords[2]), maxp(coords[3], coords[4], coords[5]);
    bbox3d query_box(minp, maxp);

    std::vector<value3d> results;
    rtree.query(bgi::intersects(query_box), std::back_inserter(results));
    std::vector<long> values;
    for (auto result : results){
        values.insert(values.begin(), result.second);
    }
    return values;
}

void RTreePoint3D::removePoints(double* points, long m, long n){
    assert(n == 4); // points should be an m x 3 matrix

    for (long i = 0 ; i < m * n; i = i + n){
        point3d p(points[i], points[i + 1], points[i + 2]);
        this->rtree.remove(std::make_pair(p, long(points[i + n-1])));
    }
}

void RTreePoint3D::_sortMinMaxCorners(double* points, long m, long n)
{
    assert(n == 3);
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
