#include "displayFileObject.h"

DisplayFileObject::DisplayFileObject(X obj, string name, string type){
	object = obj;
	object_name = name;
    object_type = type;
}

Coordinate DisplayFileObject::getCoordinates(){
	return object.coodinates();
}

std::string DisplayFileObject::getName(){
    return object_name;
}

std::string DisplayFileObject::getType(){
    return object_type;
}
