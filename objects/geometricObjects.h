#ifndef GEOMETRIC_OBJECTS_H
#define GEOMETRIC_OBJECTS_H

#include <vector>
#include <string>
#include "coordinate.h"

class GeometricObject {
public:
    std::vector<Coordinate> getCoordinates(){
        return c;
    }
    std::string getType(){
        return type;
    }
protected:
    std::string type;
    std::vector<Coordinate> c;
};

class Point: public GeometricObject {
public:
    Point(Coordinate coor){
        type = "point";
        c.push_back(coor);
    };
};

class Line: public GeometricObject {
public:
    Line(Coordinate coor1, Coordinate coor2){
        type = "Line";
        c.push_back(coor1);
        c.push_back(coor2);
    };
};

class Polygon: public GeometricObject {
public:
    Polygon(){
        type = "polygon";
    };
    void addPoint(Coordinate coor){
        c.push_back(coor);
    };
};

#endif
