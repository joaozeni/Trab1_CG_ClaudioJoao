#ifndef GEOMETRIC_OBJECTS_H
#define GEOMETRIC_OBJECTS_H

#include "coordinate.h"

struct Point{
    Coordinate c;
};

struct Line{
    Coordinate c[2];
};

struct Polygon{
    std::vector<Coordinate> c;
};

#endif
