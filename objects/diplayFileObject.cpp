#include "DisplayFileObject.h"

template<class X>
DisplayFileObject::DisplayFileObject(X obj, string name, string type){
	object = obj;
	object_name = name;
    object_type = type;
}

template<class X>
getCoordinates(){
	return object.coodinates();
}

template<class X>
getName(){
    return object_name;
}

template<class X>
getType(){
    return object_type;
}
