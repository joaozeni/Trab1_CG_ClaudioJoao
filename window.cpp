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
    return clipedObjects.size();
}

DisplayFileObject * Window::getObject(int position){
    return clipedObjects.at(position);
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

void Window::normalize(){
    std::vector<Coordinate*> coors = mywindow->getCoordinates();
    Coordinate * wc = mywindow->getCenter();
    Coordinate * vup = new Coordinate(((coors.at(2)->x()+coors.at(3)->x())/2)-wc->x(),((coors.at(2)->y()+coors.at(3)->y())/2)-wc->y());
    float yvec[2] = {0.0, 550.0};
    float dot = (vup->x()*yvec[0]) + (vup->y()*yvec[1]);
    float det = (vup->x()*yvec[1]) - (vup->y()*yvec[0]);
    float angle = (atan2(det, dot)*180)/ M_PI;
    Coordinate * scalec = new Coordinate(2.0/(mywindow->getXMax()-mywindow->getXMin()),2.0/(mywindow->getYMax()-mywindow->getYMin()));
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

void Window::clipLiangBarsky(){
    clipedObjects.clear();
    for(int i = 0; i < displayfile.size(); i++){
        std::vector<Coordinate*> coords = displayfile.at(i)->getNormalizedCoordinates();
        if (displayfile.at(i)->getType() == "point"){
            clipedObjects.push_back(displayfile.at(0));
        } else if(displayfile.at(i)->getType() == "line"){
            std::vector<float> p;
            std::vector<float> q;
            float p2 = coords.at(1)->x() - coords.at(0)->x();
            float p1 = -p2;
            p.push_back(p1);
            p.push_back(p2);
            float p4 = coords.at(1)->y() - coords.at(0)->y();
            float p3 = -p4;
            p.push_back(p3);
            p.push_back(p4);
            float q1 = coords.at(0)->x() + 0.95;
            q.push_back(q1);
            float q2 = 0.95 - coords.at(0)->x();
            q.push_back(q2);
            float q3 = coords.at(0)->y() + 0.95;
            q.push_back(q3);
            float q4 = 0.95 - coords.at(0)->y();
            q.push_back(q4);
            std::vector<float> dzeta1;
            dzeta1.push_back(0.0);
            std::vector<float> dzeta2;
            dzeta2.push_back(1.0);
            for(int k = 0; k < p.size(); k++){
                if(p.at(k) == 0.0){
                    if(q.at(k) >= 0.0){
                        clipedObjects.push_back(displayfile.at(i));
                    }
                } else if(p.at(k) > 0.0){
                    dzeta2.push_back(q.at(k)/p.at(k));
                }
                else{
                    dzeta1.push_back(q.at(k)/p.at(k));
                }
            }
            Coordinate * c1;
            float u1 = *std::max_element(dzeta1.begin(), dzeta1.end());
            if(u1 != 0.0){
                float x = coords.at(0)->x() + (u1*p2);
                float y = coords.at(0)->y() + (u1*p4);
                c1 = new Coordinate(x,y);
            } else{
                c1 = coords.at(0);
            }
            Coordinate *c2;
            float u2 = *std::min_element(dzeta2.begin(), dzeta2.end());
            if(u1 != 1.0){
                float x = coords.at(0)->x() + (u2*p2);
                float y = coords.at(0)->y() + (u2*p4);
                c2 = new Coordinate(x,y);
            } else{
                c2 = coords.at(1);
            }
            clipedObjects.push_back(new DisplayFileObject(new Line(c1,c2), displayfile.at(i)->getName()));
        } else{
            clipedObjects.push_back(displayfile.at(0));
        }
    }
}

void Window::move(Coordinate * c){
    mywindow->move(c);
    normalize();
    clipLiangBarsky();
}

void Window::zoom(float factor){
    Coordinate * c = new Coordinate(1.0+factor,1.0+factor);
    mywindow->scale(c);
    normalize();
    clipLiangBarsky();
}

void Window::rotate(float factor){
    mywindow->rotate(factor);
    normalize();
    clipLiangBarsky();
}
