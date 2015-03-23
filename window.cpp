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
    return 1.0;
}

float Window::minX(){
    return -1.0;
}

float Window::maxY(){
    return 1.0;
}

float Window::minY(){
    return -1.0;
}

void Window::move(Coordinate * c){
    mywindow->move(c);
    std::vector<Coordinate*> coors = mywindow->getCoordinates();
    Coordinate * wc = mywindow->getCenter();
    Coordinate * vup = new Coordinate(((coors.at(2)->x()+coors.at(3)->x())/2)-wc->x(),((coors.at(2)->y()+coors.at(3)->y())/2)-wc->y());
    float yvec[2] = {0.0, 550.0};
    float dot = (vup->x()*yvec[0]) + (vup->y()*yvec[1]);
    float det = (vup->x()*yvec[1]) - (vup->y()*yvec[0]);
    float angle = (atan2(det, dot)*180)/ M_PI;
    Coordinate * scalec = new Coordinate(2.0/550.0,2.0/550.0);
    Coordinate * mwc = new Coordinate(-wc->x(),-wc->y());

    std::vector<std::vector<float> > moveM = mwc->generateMoveMatrix();
    std::vector<std::vector<float> > rotateM = GeometricObject::generateRotateMatrix(angle);
    std::vector<std::vector<float> > scaleM = scalec->generateScaleMatrix();

    std::vector<std::vector<float> > interM = Matrix::mult(moveM, rotateM);
    std::vector<std::vector<float> > finalM = Matrix::mult(interM, scaleM);

    for(int i = 0; i < displayfile.size(); i++){
        displayfile.at(i)->normalize(finalM);
    }
}
