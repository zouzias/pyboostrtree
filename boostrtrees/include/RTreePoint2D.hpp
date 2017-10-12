#ifndef RTREEADAPTER_DOT_HPP
#define RTREEADAPTER_DOT_HPP

#include <vector>
#include <boost/foreach.hpp>
#include <boost/geometry.hpp>
#include <boost/geometry/geometries/geometries.hpp>
#include <boost/geometry/geometries/point_xy.hpp>
#include <boost/geometry/algorithms/distance.hpp>
#include <boost/geometry/geometries/point.hpp>
#include <boost/geometry/geometries/box.hpp>
#include <boost/geometry/geometries/polygon.hpp>
#include <boost/geometry/index/rtree.hpp>


namespace b = boost;
namespace bg = boost::geometry;
namespace bgi = boost::geometry::index;


namespace rtrees {

// Typedefs for points, polygons and multipolygons
typedef bg::model::d2::point_xy<double> point_t;
typedef bg::model::polygon<point_t> polygon_t;
typedef bg::model::multi_polygon<polygon_t> mpolygon_t;

// Typedefs for bbox
typedef bg::model::box<point_t> bbox;
typedef std::pair<point_t, long> value;

class RTreePoint2D {
public:
    RTreePoint2D();
    ~RTreePoint2D();
    std::vector<long> knn(double x, double y, int k);
    void insertPoint(double x, double y, long value);
    std::vector<double> bounds();
    long size();

   private:
    // create the rtree using default constructor
    bgi::rtree< value, bgi::rstar<16, 4> > rtree;
};
}

#endif
