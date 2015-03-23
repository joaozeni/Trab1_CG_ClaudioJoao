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
    return mywindow->getXMax();
}

float Window::minX(){
    return mywindow->getXMin();
}

float Window::maxY(){
    return mywindow->getYMax();
}

float Window::minY(){
    return mywindow->getYMin();
}

void Window::move(Coordinate * c){
    mywindow->move(c);
}