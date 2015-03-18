#include "displayFileObject.h"

DisplayFileObject::DisplayFileObject(GeometricObject *obj, std::string name){
    object = obj;
    object_name = name;
}

DisplayFileObject::~DisplayFileObject() {
}

std::vector<Coordinate *> DisplayFileObject::getCoordinates(){
    return object->getCoordinates();
}

std::string DisplayFileObject::getName(){
    return object_name;
}

std::string DisplayFileObject::getType(){
    return object->getType();
}
