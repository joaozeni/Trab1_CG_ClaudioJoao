#include "displayFileObject.h"

DisplayFileObject::DisplayFileObject(GeometricObject obj, std::string name, string type){
	object = obj;
	object_name = name;
    object_type = type;
}

DisplayFileObject::~DisplayFileObject() {
}

Coordinate DisplayFileObject::getCoordinates(){
	return object.coodinates();
}

std::string DisplayFileObject::getName(){
    return object_name;
}

std::string DisplayFileObject::getType(){
    return object.getType();
}
