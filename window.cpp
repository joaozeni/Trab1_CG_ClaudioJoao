#include "window.h"

Window::Window(){
    mywindow = new Polygon();
    mynormalizewindow = new Polygon();
    mywindow->addPoint(new Coordinate(0, 0));
    mywindow->addPoint(new Coordinate(550, 0));
    mywindow->addPoint(new Coordinate(550, 550));
    mywindow->addPoint(new Coordinate(0, 550));
    mynormalizewindow->addPoint(new Coordinate(-0.95, -0.95));
    mynormalizewindow->addPoint(new Coordinate(-0.95, 0.95));
    mynormalizewindow->addPoint(new Coordinate(0.95, 0.95));
    mynormalizewindow->addPoint(new Coordinate(0.95, -0.95));
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

void Window::project(){
	std::vector<Coordinate*> coors = mywindow->getCoordinates();
    Coordinate * wc = mywindow->getCenter();
    Coordinate * vpn = new Coordinate(((coors.at(2)->x()+coors.at(3)->x())/2)-wc->x(),((coors.at(2)->y()+coors.at(3)->y())/2)-wc->y());
    
    float yvec[2] = {0.0, 550.0};
    float dot = (vup->x()*yvec[0]) + (vup->y()*yvec[1]);
    float det = (vup->x()*yvec[1]) - (vup->y()*yvec[0]);
    float angle = (atan2(det, dot)*180)/ M_PI;

    float xvec[2] = {0.0, 550.0};
    float dot = (vup->x()*yvec[0]) + (vup->y()*yvec[1]);
    float det = (vup->x()*yvec[1]) - (vup->y()*yvec[0]);
    float angle = (atan2(det, dot)*180)/ M_PI;

    Coordinate * scalec = new Coordinate(2.0/(mywindow->getXMax()-mywindow->getXMin()),2.0/(mywindow->getYMax()-mywindow->getYMin()));
    Coordinate * mwc = new Coordinate(-wc->x(),-wc->y(), -wc->z());

    std::vector<std::vector<float> > moveM = mwc->generateMoveMatrix();
    std::vector<std::vector<float> > rotateM = GeometricObject::generateRotateMatrix(angle);
    std::vector<std::vector<float> > scaleM = scalec->generateScaleMatrix();

    std::vector<std::vector<float> > interM = Matrix::mult(moveM, rotateM);
    std::vector<std::vector<float> > finalM = Matrix::mult(interM, scaleM);

    for(int i = 0; i < displayfile.size(); i++){
        displayfile.at(i)->normalize(finalM);
    }
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

int cohenQuadrant(float x, float y) {
    int code = 0;
    if(y > 0.95)
        code += 1 << 0;
    if(y < -0.95)
        code += 1 << 1;
    if(x > 0.95)
        code += 1 << 2;
    if(x < -0.95)
        code += 1 << 3;
    return code;
}

void Window::clipLineCohenSutherland(std::vector<Coordinate*> coords, int i){
    Coordinate* p1 = coords.at(0);
    Coordinate* p2 = coords.at(1);
    int p1code = cohenQuadrant(p1->x(), p1->y());
    int p2code = cohenQuadrant(p2->x(), p2->y());

    if((p1code & p2code) != 0) // LINHA FORA DA JANELA
        return;
    if((p1code == p2code) && p1code == 0) {//LINHA TOTALMENTE DENTRO
        clipedObjects.push_back(new DisplayFileObject(new Line(*p1,*p2), displayfile.at(i)->getName()));
        return;
    }

    // 0 topo - 1 baixo - 2 direita - 3 esquerda

    float p1x = p1->x();
    float p2x = p2->x();
    float p1y = p1->y();
    float p2y = p2->y();
    float m = (p2y- p1y)/(p2x - p1x);

    while(p1code) {
        if(p1code & 0x01) { //sai no topo
            p1x = p1x + (1.0/m)*(0.95-p1y);
            p1y = 0.95;
        } else if(p1code & 0x02) { //sai embaixo
            p1x = p1x + (1.0/m)*(-0.95-p1y);
            p1y = -0.95;
        } else if(p1code & 0x04) { //sai na direita
            p1y = m*(0.95 - p1x) + p1y;
            p1x = 0.95;
        } else if(p1code & 0x08) {//sai na esquerda
            p1y = m*(-0.95 - p1x) + p1y;
            p1x = -0.95;
        }
        p1code = cohenQuadrant(p1x, p1y);
    }

    while(p2code) {
        if(p2code & 0x01) { //sai no topo
            p2x = p1x + (1.0/m)*(0.95-p1y);
            p2y = 0.95;
        } else if(p2code & 0x02) { //sai embaixo
            p2x = p1x + (1.0/m)*(-0.95-p1y);
            p2y = -0.95;
        } else if(p2code & 0x04) { //sai na direita
            p2y = m*(0.95 - p1x) + p1y;
            p2x = 0.95;
        } else if(p2code & 0x08) {//sai na esquerda
            p2y = m*(-0.95 - p1x) + p1y;
            p2x = -0.95;
        }
        p2code = cohenQuadrant(p2x, p2y);
    }

    Coordinate* c1 = new Coordinate(p1x, p1y);
    Coordinate* c2 = new Coordinate(p2x, p2y);
    clipedObjects.push_back(new DisplayFileObject(new Line(c1,c2), displayfile.at(i)->getName()));
}

void Window::clipLineLiangBarsky(std::vector<Coordinate*> coords, int i){
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
    Coordinate * c1;
    Coordinate *c2;
    float r;
    bool flag = false;
    for(int k = 0; k < p.size(); k++){
        if(p.at(k) == 0.0){
            if(q.at(k) < 0.0){
                flag = true;
            }
        } else if(p.at(k) > 0.0){
            r = q.at(k)/p.at(k);
            if(r < 0.0){
                flag = true;
            }
            dzeta2.push_back(r);
        }
        else{
            r = q.at(k)/p.at(k);
            if(r > 1.0){
                flag = true;
            }
            dzeta1.push_back(r);
        }
    }
    if(flag){
        return;
    }
    float u1 = *std::max_element(dzeta1.begin(), dzeta1.end());
    if(u1 != 0.0){
        float x = coords.at(0)->x() + (u1*p2);
        float y = coords.at(0)->y() + (u1*p4);
        c1 = new Coordinate(x,y);
    } else{
        c1 = coords.at(0);
    }
    float u2 = *std::min_element(dzeta2.begin(), dzeta2.end());
    if(u2 != 1.0){
        float x = coords.at(1)->x() + (u2*p2);
        float y = coords.at(1)->y() + (u2*p4);
        c2 = new Coordinate(x,y);
    } else{
        c2 = coords.at(1);
    }
    //std::cout << c2->x() << "\n";
    clipedObjects.push_back(new DisplayFileObject(new Line(c1,c2), displayfile.at(i)->getName()));
}

bool Window::insideEdge(Coordinate * a, Coordinate * b, Coordinate * x){
//    std::cout << "a: (" << a->x() << "," << a->y() << ")";
//    std::cout << "b: (" << b->x() << "," << b->y() << ")\n";
    if(b->x() > a->x()){ //up side
        if(x->y() <= a->y()) return true;
    }
    if(b->x() < a->x()){ //down side
        if(x->y() >= a->y()) return true;
    }
    if(b->y() > a->y()){ //left side
        if(x->x() >= a->x()) return true;
    }
    if(b->y() < a->y()){ //right side
        if(x->x() <= a->x()) return true;
    }
    return false;
}

Coordinate * Window::intersection(Coordinate * a, Coordinate * b, Coordinate * s, Coordinate * e){
    float x;
    float y;
    if(a->y() == b->y()){ //vertical
        y = a->y();
        x = s->x() + ((a->y()-s->y())*(e->x()-s->x()))/(e->y()-s->y());
    } else{ //horisontal
        x = a->x();
        y = s->y() + ((a->x()-s->x())*(e->y()-s->y()))/(e->x()-s->x());
    }
    Coordinate * nx = new Coordinate(x,y);
    return nx;
}

void Window::clipPolygonSutherlandHodgman(std::vector<Coordinate*> coords, int k){
    std::vector<Coordinate*> outputList = coords;
    std::vector<Coordinate*> inputList;
    std::vector<Coordinate*> clipPoly = mynormalizewindow->getCoordinates();
    Coordinate * a;
    Coordinate * b;
    for (int i = 0; i < clipPoly.size(); i++){
        a = clipPoly.at(i);
        std::cout << " i:" << i << "\n";
        if(i == clipPoly.size()-1){
            b = clipPoly.at(0);
        } else {
            b = clipPoly.at(i+1);
        }
        inputList = outputList;
        outputList.clear();
        Coordinate * s = inputList.at(inputList.size()-1);
         for (int j = 0; j < inputList.size(); j++){
            Coordinate * e = inputList.at(j);
            //std::cout << "e: (" << e->x() << "," << e->y() << ")" << "\n";
             if(insideEdge(a,b,e)){
                 if(!insideEdge(a,b,s)){
                     outputList.push_back(intersection(a,b,s,e));
                 }
                 outputList.push_back(e);
             } else if(insideEdge(a,b,s)){
                 outputList.push_back(intersection(a,b,s,e));
             }
             s = e;
         }
         if(outputList.empty()){
             return;
         }
    }
    clipedObjects.push_back(new DisplayFileObject(new Polygon(outputList), displayfile.at(k)->getName()));
}

void Window::clip(){
    clipedObjects.clear();
    for(int i = 0; i < displayfile.size(); i++){
        std::vector<Coordinate*> coords = displayfile.at(i)->getNormalizedCoordinates();
        if (displayfile.at(i)->getType() == "point"){
            clipedObjects.push_back(displayfile.at(0));
        } else if(displayfile.at(i)->getType() == "line"){
            clipLineCohenSutherland(coords, i);
        } else if(displayfile.at(i)->getType() == "polygon"){
            clipPolygonSutherlandHodgman(coords, i);
        } else {
            clipedObjects.push_back(displayfile.at(i));
        }
    }
}

void Window::move(Coordinate * c){
    mywindow->move(c);
    normalize();
    clip();
}

void Window::zoom(float factor){
    Coordinate * c = new Coordinate(1.0+factor,1.0+factor);
    mywindow->scale(c);
    normalize();
    clip();
}

void Window::rotate(float factor){
    mywindow->rotate(factor);
    normalize();
    clip();
}
