#ifndef BOOSTRTREES_BOOSTGEOMETRYTYPES_HPP
#define BOOSTRTREES_BOOSTGEOMETRYTYPES_HPP

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

namespace rtrees {

// Helpful namespace shortcuts
namespace b = boost;
namespace bg = boost::geometry;
namespace bgi = boost::geometry::index;


// Typedefs for points, polygons and multipolygons
typedef bg::model::d2::point_xy<double> point_t;
typedef bg::model::polygon <point_t> polygon_t;
typedef bg::model::multi_polygon <polygon_t> mpolygon_t;

// Typedefs for bbox
typedef bg::model::box <point_t> bbox;
typedef std::pair<point_t, long> value;

typedef bg::model::point<float, 3, bg::cs::cartesian> point3d;
typedef bg::model::box<point3d> bbox3d;
typedef std::pair<point3d, long> value3d;

}

#endif //BOOSTRTREES_BOOSTGEOMETRYTYPES_HPP
