#ifndef GEOMETRICOBJECT
#define GEOMETRICOBJECT

#include <vector>
#include <string>
#include "coordinate.h"

class Matrix{
public:
    static std::vector<std::vector<float> > mult(std::vector<std::vector<float> > m1, std::vector<std::vector<float> > m2){
        std::vector<std::vector<float> > nm;
        float sum = 0.0;
        for(int i=0; i<m1.size() ;i++){
            for(int j=0; j<m1.at(0).size() ;j++){
                for(int k=0;m1.at(0).size();k++){
                    sum = sum+(m1.at(i).at(k)*m2.at(k).at(j));
                }
                nm.at(i).at(j) = sum;
                sum = 0.0;
            }
        }
        return nm;
    }
};

class GeometricObject {
public:
    virtual void move(Coordinate * coor) = 0;
    std::vector<Coordinate*> getCoordinates(){
        return c;
    }
    std::string getType(){
        return type;
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
    void move(Coordinate *coor){
        std::vector<std::vector<float> > moveM = coor->generateMoveMatrix();
        std::vector<std::vector<float> > baseM = c.at(0)->generateBaseMatrix();
        std::vector<std::vector<float> > newPoint = Matrix::mult(baseM, moveM);
        //Coordinate * newcoor = new Coordinate(newPoint.at(0).at(0), newPoint.at(0).at(1));
        //c.at(0) = newcoor;
    };
};

class Line: public GeometricObject {
public:
    Line(Coordinate * coor1, Coordinate * coor2){
        type = "line";
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
};

class Polygon: public GeometricObject {
public:
    Polygon(){
        type = "polygon";
    };
    void addPoint(Coordinate * coor){
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
};

#endif // GEOMETRICOBJECT
