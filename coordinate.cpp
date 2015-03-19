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
    baseMatrix.at(0).at(0) = coordinates[0];
    baseMatrix.at(0).at(1) = coordinates[1];
    baseMatrix.at(0).at(2) = 1.0;
    return baseMatrix;
}

std::vector<std::vector<float> > Coordinate::generateMoveMatrix(){
    std::vector<std::vector<float> > baseMatrix;
    baseMatrix.at(0).at(0) = 1.0;
    baseMatrix.at(0).at(1) = 0.0;
    baseMatrix.at(0).at(2) = 0.0;

    baseMatrix.at(0).at(0) = 0.0;
    baseMatrix.at(0).at(1) = 1.0;
    baseMatrix.at(0).at(2) = 0.0;

    baseMatrix.at(0).at(0) = coordinates[0];
    baseMatrix.at(0).at(1) = coordinates[0];
    baseMatrix.at(0).at(2) = 1.0;
    return baseMatrix;
}

std::vector<std::vector<float> > Coordinate::generateScaleMatrix(){
    std::vector<std::vector<float> > baseMatrix;
    baseMatrix.at(0).at(0) = coordinates[0];
    baseMatrix.at(0).at(1) = 0.0;
    baseMatrix.at(0).at(2) = 0.0;

    baseMatrix.at(0).at(0) = 0.0;
    baseMatrix.at(0).at(1) = coordinates[1];
    baseMatrix.at(0).at(2) = 0.0;

    baseMatrix.at(0).at(0) = 0.0;
    baseMatrix.at(0).at(1) = 0.0;
    baseMatrix.at(0).at(2) = 1.0;
    return baseMatrix;
}
