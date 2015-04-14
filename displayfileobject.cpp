#include "displayfileobject.h"

DisplayFileObject::DisplayFileObject(GeometricObject *obj, std::string name){
    object = obj;
    object_name = name;
}

DisplayFileObject::~DisplayFileObject() {
}

std::vector<Coordinate *> DisplayFileObject::getCoordinates(){
    if(object->getType() == "curve")
        return dynamic_cast<Curve2D*>(object)->getCurveCoordinates();
    return object->getCoordinates();
}

std::vector<Coordinate*> DisplayFileObject::getNormalizedCoordinates(){
    return object->getNormalizedCoordinates();
}

std::string DisplayFileObject::getName(){
    return object_name;
}

std::string DisplayFileObject::getType(){
    return object->getType();
}

void DisplayFileObject::move(Coordinate * c){
    object->move(c);
}

void DisplayFileObject::scale(Coordinate * c){
    object->scale(c);
}

void DisplayFileObject::rotate(float factor){
    object->rotate(factor);
}

void DisplayFileObject::normalize(std::vector<std::vector<float> > transformM){
    object->normalize(transformM);
}
