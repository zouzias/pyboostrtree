#ifndef RTREEADAPTER_DOT_HPP
#define RTREEADAPTER_DOT_HPP

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

class RTreePoint2D {

private:

    typedef std::pair<point_t, long> value;

    // create the rtree using default constructor
    bgi::rtree< value, bgi::rstar<16, 4> > rtree;

public:
    int x0, y0, x1, y1;
    RTreePoint2D(int x0, int y0, int x1, int y1);
    ~RTreePoint2D();
    int getLength();
    int getHeight();
    void insertPoint(double x, double y, long value);
    long size();
    int getArea();
    void move(int dx, int dy);
};
}

#endif
