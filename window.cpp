#include "window.h"

Window::Window(){
    mywindow = new Polygon();
    mywindow->addPoint(new Coordinate(0, 0));
    mywindow->addPoint(new Coordinate(550, 0));
    mywindow->addPoint(new Coordinate(550, 550));
    mywindow->addPoint(new Coordinate(0, 550));
}

Window::~Window(){
}

void Window::addObject(DisplayFileObject *d){
    displayfile.push_back(d);
}

int Window::objectCont(){
    return displayfile.size();
}

DisplayFileObject * Window::getObject(int position){
    return displayfile.at(position);
}

float Window::maxX(){
    std::vector<Coordinate*> c = mywindow->getCoordinates();
    return c.at(2)->x();
}

float Window::minX(){
    std::vector<Coordinate*> c = mywindow->getCoordinates();
    return c.at(0)->x();
}

float Window::maxY(){
    std::vector<Coordinate*> c = mywindow->getCoordinates();
    return c.at(2)->y();
}

float Window::minY(){
    std::vector<Coordinate*> c = mywindow->getCoordinates();
    return c.at(0)->y();
}
