#ifndef GEOMETRICOBJECT
#define GEOMETRICOBJECT

#include <vector>
#include <string>
#include <iostream>
#include <math.h>
#include "coordinate.h"

class Matrix{
public:
    static std::vector<std::vector<float> > mult(std::vector<std::vector<float> > m1, std::vector<std::vector<float> > m2){
        std::vector<std::vector<float> > nm;
        float sum = 0.0;
        std::vector<float> l1;
        std::vector<float> l2;
        std::vector<float> l3;
        nm.push_back(l1);
        nm.push_back(l2);
        nm.push_back(l3);
        for(int i=0; i<m1.size() ;i++){
            for(int j=0; j < m1.at(0).size() ;j++){
                for(int k=0;k < m1.at(0).size();k++){
                    sum = sum+(m1.at(i).at(k)*m2.at(k).at(j));
                }
                nm.at(i).push_back(sum);
                sum = 0.0;
            }
        }
        return nm;
    }
};

class GeometricObject {
public:
    virtual void move(Coordinate * coor) = 0;
    virtual void scale(Coordinate * coor) = 0;
    virtual void rotate(float factor) = 0;
    std::vector<Coordinate*> getCoordinates(){
        return c;
    }
    std::string getType(){
        return type;
    }
    std::vector<std::vector<float> > generateRotateMatrix(float factor){
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
protected:
    std::string type;
    std::vector<Coordinate*> c;
};

class Point: public GeometricObject {
public:
    Point(Coordinate * coor){
        type = "point";
        c.push_back(coor);
    };
    Point(Coordinate& refcoor){
        type = "point";
        Coordinate* coor = new Coordinate(refcoor.x(), refcoor.y(), refcoor.z());
        c.push_back(coor);
    };
    void move(Coordinate *coor){
        std::vector<std::vector<float> > moveM = coor->generateMoveMatrix();
        std::vector<std::vector<float> > baseM = c.at(0)->generateBaseMatrix();
        std::vector<std::vector<float> > newPoint = Matrix::mult(baseM, moveM);
        Coordinate * newcoor = new Coordinate(newPoint.at(0).at(0), newPoint.at(0).at(1));
        c.at(0) = newcoor;
    };
    void scale(Coordinate *coor){
        std::vector<std::vector<float> > scaleM = coor->generateScaleMatrix();
        std::vector<std::vector<float> > baseM = c.at(0)->generateBaseMatrix();
        std::vector<std::vector<float> > newPoint = Matrix::mult(baseM, scaleM);
        Coordinate * newcoor = new Coordinate(newPoint.at(0).at(0), newPoint.at(0).at(1));
        c.at(0) = newcoor;
    };
    void rotate(float factor){
        std::vector<std::vector<float> > rotateM = generateRotateMatrix(factor);
        std::vector<std::vector<float> > baseM = c.at(0)->generateBaseMatrix();
        std::vector<std::vector<float> > newPoint = Matrix::mult(baseM, rotateM);
        Coordinate * newcoor = new Coordinate(newPoint.at(0).at(0), newPoint.at(0).at(1));
        c.at(0) = newcoor;
    };
};

class Line: public GeometricObject {
public:
    Line(Coordinate * coor1, Coordinate * coor2){
        type = "line";
        c.push_back(coor1);
        c.push_back(coor2);
    };
    Line(Coordinate& refcoor1, Coordinate& refcoor2){
        type = "line";
        Coordinate* coor1 = new Coordinate(refcoor1.x(), refcoor1.y(), refcoor1.z());
        Coordinate* coor2 = new Coordinate(refcoor2.x(), refcoor2.y(), refcoor2.z());
        c.push_back(coor1);
        c.push_back(coor2);
    };
    void move(Coordinate *coor){
        std::vector<std::vector<float> > moveM = coor->generateMoveMatrix();
        std::vector<std::vector<float> > baseM0 = c.at(0)->generateBaseMatrix();
        std::vector<std::vector<float> > baseM1 = c.at(1)->generateBaseMatrix();
        std::vector<std::vector<float> > newPoint0 = Matrix::mult(baseM0, moveM);
        std::vector<std::vector<float> > newPoint1 = Matrix::mult(baseM1, moveM);
        Coordinate * newcoor0 = new Coordinate(newPoint0.at(0).at(0), newPoint0.at(0).at(1));
        Coordinate * newcoor1 = new Coordinate(newPoint1.at(0).at(0), newPoint1.at(0).at(1));
        c.at(0) = newcoor0;
        c.at(1) = newcoor1;
    };
    void scale(Coordinate *coor){
        float cx = (c.at(0)->x() + c.at(1)->x())/2;
        float cy = (c.at(0)->y() + c.at(1)->y())/2;
        float mcx = -cx;
        float mcy = -cy;
        Coordinate * coorc = new Coordinate(cx, cy);
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
    };
    void rotate(float factor){
        float cx = (c.at(0)->x() + c.at(1)->x())/2;
        float cy = (c.at(0)->y() + c.at(1)->y())/2;
        float mcx = -cx;
        float mcy = -cy;
        Coordinate * coorc = new Coordinate(cx, cy);
        Coordinate * coormc = new Coordinate(mcx, mcy);

        std::vector<std::vector<float> > rotateM = generateRotateMatrix(factor);
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
    };
};

class Polygon: public GeometricObject {
public:
    Polygon(){
        type = "polygon";
    };
    void addPoint(Coordinate * coor){
        c.push_back(coor);
    };
    void addPoint(Coordinate& refcoor){
        Coordinate* coor = new Coordinate(refcoor.x(), refcoor.y(), refcoor.z());
        c.push_back(coor);
    };
    void move(Coordinate *coor){
        std::vector<std::vector<float> > baseM;
        std::vector<std::vector<float> > newPoint;
        std::vector<std::vector<float> > moveM = coor->generateMoveMatrix();
        for(int i =0; i < c.size(); i++){
            baseM = c.at(i)->generateBaseMatrix();
            newPoint = Matrix::mult(baseM, moveM);
            Coordinate * newcoor = new Coordinate(newPoint.at(0).at(0), newPoint.at(0).at(1));
            c.at(i) = newcoor;
        }
    };
    void scale(Coordinate *coor){
        float cx = 0.0;
        float cy = 0.0;
        for(int i =0; i < c.size(); i++){
            cx = cx + c.at(i)->x();
            cy = cy + c.at(i)->y();
        }
        cx = cx/c.size();
        cy = cy/c.size();
        float mcx = -cx;
        float mcy = -cy;
        Coordinate * coorc = new Coordinate(cx, cy);
        Coordinate * coormc = new Coordinate(mcx, mcy);

        std::vector<std::vector<float> > scaleM = coor->generateScaleMatrix();
        std::vector<std::vector<float> > movecM = coorc->generateMoveMatrix();
        std::vector<std::vector<float> > movemcM = coormc->generateMoveMatrix();

        std::vector<std::vector<float> > moveScale1 = Matrix::mult(movemcM, scaleM);
        std::vector<std::vector<float> > finalM = Matrix::mult(moveScale1, movecM);

        std::vector<std::vector<float> > baseM;
        std::vector<std::vector<float> > newPoint;
        for(int i =0; i < c.size(); i++){
            baseM = c.at(i)->generateBaseMatrix();
            newPoint = Matrix::mult(baseM, finalM);
            Coordinate * newcoor = new Coordinate(newPoint.at(0).at(0), newPoint.at(0).at(1));
            c.at(i) = newcoor;
        }
    };
    void rotate(float factor){
        float cx = 0.0;
        float cy = 0.0;
        for(int i =0; i < c.size(); i++){
            cx = cx + c.at(i)->x();
            cy = cy + c.at(i)->y();
        }
        cx = cx/c.size();
        cy = cy/c.size();
        float mcx = -cx;
        float mcy = -cy;
        Coordinate * coorc = new Coordinate(cx, cy);
        Coordinate * coormc = new Coordinate(mcx, mcy);

        std::vector<std::vector<float> > rotateM = generateRotateMatrix(factor);
        std::vector<std::vector<float> > movecM = coorc->generateMoveMatrix();
        std::vector<std::vector<float> > movemcM = coormc->generateMoveMatrix();

        std::vector<std::vector<float> > moveScale1 = Matrix::mult(movemcM, rotateM);
        std::vector<std::vector<float> > finalM = Matrix::mult(moveScale1, movecM);

        std::vector<std::vector<float> > baseM;
        std::vector<std::vector<float> > newPoint;
        for(int i =0; i < c.size(); i++){
            baseM = c.at(i)->generateBaseMatrix();
            newPoint = Matrix::mult(baseM, finalM);
            Coordinate * newcoor = new Coordinate(newPoint.at(0).at(0), newPoint.at(0).at(1));
            c.at(i) = newcoor;
        }
    };
};

#endif // GEOMETRICOBJECT
