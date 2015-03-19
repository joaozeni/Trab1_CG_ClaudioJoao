#include "coordinate.h"

Coordinate::Coordinate(float x, float y, float z)
{
    coordinates[0] = x;
    coordinates[1] = y;
    coordinates[2] = z;
}

Coordinate::~Coordinate()
{

}

float Coordinate::x(){
    return coordinates[0];
}

void Coordinate::x(float newVal){
    coordinates[0] = newVal;
}

float Coordinate::y(){
    return coordinates[1];
}

void Coordinate::y(float newVal){
    coordinates[1] = newVal;
}

float Coordinate::z(){
    return coordinates[2];
}

void Coordinate::z(float newVal){
    coordinates[2] = newVal;
}

std::vector<std::vector<float> > Coordinate::generateBaseMatrix(){
    std::vector<std::vector<float> > baseMatrix;
    std::vector<float> l;
    l.push_back(coordinates[0]);
    l.push_back(coordinates[1]);
    l.push_back(1.0);
    baseMatrix.push_back(l);
    return baseMatrix;
}

std::vector<std::vector<float> > Coordinate::generateMoveMatrix(){
    std::vector<std::vector<float> > baseMatrix;
    std::vector<float> l1;
    std::vector<float> l2;
    std::vector<float> l3;

    baseMatrix.push_back(l1);
    baseMatrix.push_back(l2);
    baseMatrix.push_back(l3);

    baseMatrix.at(0).push_back(1.0);
    baseMatrix.at(0).push_back(0.0);
    baseMatrix.at(0).push_back(0.0);

    baseMatrix.at(1).push_back(0.0);
    baseMatrix.at(1).push_back(1.0);
    baseMatrix.at(1).push_back(0.0);

    baseMatrix.at(2).push_back(coordinates[0]);
    baseMatrix.at(2).push_back(coordinates[0]);
    baseMatrix.at(2).push_back(1.0);

    return baseMatrix;
}

std::vector<std::vector<float> > Coordinate::generateScaleMatrix(){
    std::vector<std::vector<float> > baseMatrix;
    std::vector<float> l1;
    std::vector<float> l2;
    std::vector<float> l3;

    baseMatrix.push_back(l1);
    baseMatrix.push_back(l2);
    baseMatrix.push_back(l3);

    baseMatrix.at(0).push_back(coordinates[0]);
    baseMatrix.at(0).push_back(0.0);
    baseMatrix.at(0).push_back(0.0);

    baseMatrix.at(1).push_back(0.0);
    baseMatrix.at(1).push_back(coordinates[1]);
    baseMatrix.at(1).push_back(0.0);

    baseMatrix.at(2).push_back(0.0);
    baseMatrix.at(2).push_back(0.0);
    baseMatrix.at(2).push_back(1.0);

    return baseMatrix;
}
