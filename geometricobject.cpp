#include "geometricobject.h"

std::vector<Coordinate*> GeometricObject::getCoordinates(){
    return c;
}

std::string GeometricObject::getType(){
    return type;
}

static std::vector<std::vector<float> > GeometricObject::generateRotateMatrix(float factor){
    std::vector<std::vector<float> > baseMatrix;
    std::vector<float> l1;
    std::vector<float> l2;
    std::vector<float> l3;

    baseMatrix.push_back(l1);
    baseMatrix.push_back(l2);
    baseMatrix.push_back(l3);

    baseMatrix.at(0).push_back(cos(factor*M_PI/180));
    baseMatrix.at(0).push_back(-sin(factor*M_PI/180));
    baseMatrix.at(0).push_back(0.0);

    baseMatrix.at(1).push_back(sin(factor*M_PI/180));
    baseMatrix.at(1).push_back(cos(factor*M_PI/180));
    baseMatrix.at(1).push_back(0.0);

    baseMatrix.at(2).push_back(0.0);
    baseMatrix.at(2).push_back(0.0);
    baseMatrix.at(2).push_back(1.0);

    return baseMatrix;
}

Coordinate * GeometricObject::getCenter() {
    float cx = 0.0;
    float cy = 0.0;
    for(int i =0; i < c.size(); i++){
        cx = cx + c.at(i)->x();
        cy = cy + c.at(i)->y();
    }
    cx = cx/c.size();
    cy = cy/c.size();
    Coordinate * coorc = new Coordinate(cx, cy);
    return coorc;
}

float GeometricObject::getXMax(){
    float maxx = c.at(0)->x();
    for(int i =0; i < c.size(); i++){
        if (maxx < c.at(i)->x()) {
            maxx = c.at(i)->x();
        }
    }
    return maxx;
}

float GeometricObject::getYMax(){
    float maxy = c.at(0)->y();
    for(int i =0; i < c.size(); i++){
        if (maxy < c.at(i)->y()) {
            maxy = c.at(i)->y();
        }
    }
    return maxy;
}

float GeometricObject::getXMin(){
    float minx = c.at(0)->x();
    for(int i =0; i < c.size(); i++){
        if (minx > c.at(i)->x()) {
            minx = c.at(i)->x();
        }
    }
    return minx;
}

float GeometricObject::getYMin(){
    float miny = c.at(0)->y();
    for(int i =0; i < c.size(); i++){
        if (miny > c.at(i)->y()) {
            miny = c.at(i)->y();
        }
    }
    return miny;
}
    
void Point::move(Coordinate *coor) : public GeometricObject{
    std::vector<std::vector<float> > moveM = coor->generateMoveMatrix();
    std::vector<std::vector<float> > baseM = c.at(0)->generateBaseMatrix();
    std::vector<std::vector<float> > newPoint = Matrix::mult(baseM, moveM);
    Coordinate * newcoor = new Coordinate(newPoint.at(0).at(0), newPoint.at(0).at(1));
    c.at(0) = newcoor;
}

void Point::scale(Coordinate *coor): public GeometricObject{
    std::vector<std::vector<float> > scaleM = coor->generateScaleMatrix();
    std::vector<std::vector<float> > baseM = c.at(0)->generateBaseMatrix();
    std::vector<std::vector<float> > newPoint = Matrix::mult(baseM, scaleM);
    Coordinate * newcoor = new Coordinate(newPoint.at(0).at(0), newPoint.at(0).at(1));
    c.at(0) = newcoor;
}

void Point::rotate(float factor): public GeometricObject{
    std::vector<std::vector<float> > rotateM = GeometricObject::generateRotateMatrix(factor);
    std::vector<std::vector<float> > baseM = c.at(0)->generateBaseMatrix();
    std::vector<std::vector<float> > newPoint = Matrix::mult(baseM, rotateM);
    Coordinate * newcoor = new Coordinate(newPoint.at(0).at(0), newPoint.at(0).at(1));
    c.at(0) = newcoor;
}

void Line::move(Coordinate *coor){
    std::vector<std::vector<float> > moveM = coor->generateMoveMatrix();
    std::vector<std::vector<float> > baseM0 = c.at(0)->generateBaseMatrix();
    std::vector<std::vector<float> > baseM1 = c.at(1)->generateBaseMatrix();
    std::vector<std::vector<float> > newPoint0 = Matrix::mult(baseM0, moveM);
    std::vector<std::vector<float> > newPoint1 = Matrix::mult(baseM1, moveM);
    Coordinate * newcoor0 = new Coordinate(newPoint0.at(0).at(0), newPoint0.at(0).at(1));
    Coordinate * newcoor1 = new Coordinate(newPoint1.at(0).at(0), newPoint1.at(0).at(1));
    c.at(0) = newcoor0;
    c.at(1) = newcoor1;
}

void Line::scale(Coordinate *coor){
    Coordinate * coorc = getCenter();
    float mcx = -coorc->x();
    float mcy = -coorc->y();
    Coordinate * coormc = new Coordinate(mcx, mcy);

    std::vector<std::vector<float> > scaleM = coor->generateScaleMatrix();
    std::vector<std::vector<float> > movecM = coorc->generateMoveMatrix();
    std::vector<std::vector<float> > movemcM = coormc->generateMoveMatrix();

    std::vector<std::vector<float> > moveScale1 = Matrix::mult(movemcM, scaleM);
    std::vector<std::vector<float> > finalM = Matrix::mult(moveScale1, movecM);

    std::vector<std::vector<float> > baseM0 = c.at(0)->generateBaseMatrix();
    std::vector<std::vector<float> > baseM1 = c.at(1)->generateBaseMatrix();

    std::vector<std::vector<float> > newPoint0 = Matrix::mult(baseM0, finalM);
    std::vector<std::vector<float> > newPoint1 = Matrix::mult(baseM1, finalM);

    Coordinate * newcoor0 = new Coordinate(newPoint0.at(0).at(0), newPoint0.at(0).at(1));
    Coordinate * newcoor1 = new Coordinate(newPoint1.at(0).at(0), newPoint1.at(0).at(1));
    c.at(0) = newcoor0;
    c.at(1) = newcoor1;
}

void Line::rotate(float factor){
    Coordinate * coorc = getCenter();
    float mcx = -coorc->x();
    float mcy = -coorc->y();
    Coordinate * coormc = new Coordinate(mcx, mcy);

    std::vector<std::vector<float> > rotateM = GeometricObject::generateRotateMatrix(factor);
    std::vector<std::vector<float> > movecM = coorc->generateMoveMatrix();
    std::vector<std::vector<float> > movemcM = coormc->generateMoveMatrix();

    std::vector<std::vector<float> > moveScale1 = Matrix::mult(movemcM, rotateM);
    std::vector<std::vector<float> > finalM = Matrix::mult(moveScale1, movecM);

    std::vector<std::vector<float> > baseM0 = c.at(0)->generateBaseMatrix();
    std::vector<std::vector<float> > baseM1 = c.at(1)->generateBaseMatrix();

    std::vector<std::vector<float> > newPoint0 = Matrix::mult(baseM0, finalM);
    std::vector<std::vector<float> > newPoint1 = Matrix::mult(baseM1, finalM);

    Coordinate * newcoor0 = new Coordinate(newPoint0.at(0).at(0), newPoint0.at(0).at(1));
    Coordinate * newcoor1 = new Coordinate(newPoint1.at(0).at(0), newPoint1.at(0).at(1));
    c.at(0) = newcoor0;
    c.at(1) = newcoor1;
}
