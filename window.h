#ifndef WINDOW_H
#define WINDOW_H

#include <vector>
#include <cmath>
#include <iostream>
#include "geometricobject.h"
#include "coordinate.h"
#include "displayfileobject.h"

class Window
{
public:
    Window();
    ~Window();
    void addObject(DisplayFileObject * d);
    int objectCont();
    DisplayFileObject * getObject(int position);
    float maxX();
    float minX();
    float maxY();
    float minY();
    void move(Coordinate * c);
    void zoom(float factor);
    void rotate(float factor);
    void normalize();
    void clip();
    void clipLineCohenSutherland(std::vector<Coordinate*> coords, int i);
    void clipLineLiangBarsky(std::vector<Coordinate*> coords, int i);
    void clipPolygonSutherlandHodgman(std::vector<Coordinate*> coords, int k);
    bool insideEdge(Coordinate * a, Coordinate * b, Coordinate * x);
    Coordinate * intersection(Coordinate * a, Coordinate * b, Coordinate * s, Coordinate * e);
private:
    Polygon * mywindow;
    Polygon * mynormalizewindow;
    std::vector<DisplayFileObject*> displayfile;
    //std::vector<DisplayFileObject*> normalizeddisplayfile;
    std::vector<DisplayFileObject*> clipedObjects;
};

#endif // WINDOW_H
