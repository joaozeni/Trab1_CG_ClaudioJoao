#include "coordinate.h"

Coordinate::Coordinate(float x, float y, float z){
    coordinates[0] = x;
    coordinates[1] = y;
    coordinates[2] = z;
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

//float Coordinate::z(){
//}
//
//void Coordinate::z(float newVal){
//}
