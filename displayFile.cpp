#include "displayFile.h"

DisplayFile::addObject(DisplayFileObject obj){
    objects.push_back(obj);
}

DisplayFile::getObjects(){
	return objects;
}