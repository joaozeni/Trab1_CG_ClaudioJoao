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
private:
    Polygon * mywindow;
    std::vector<DisplayFileObject*> displayfile;
    std::vector<DisplayFileObject*> normalizeddisplayfile;
};

#endif // WINDOW_H
