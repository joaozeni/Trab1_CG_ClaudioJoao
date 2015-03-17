#include "displayFile.h"

void DisplayFile::addObject(DisplayFileObject * obj){
    objects.push_back(obj);
}

std::vector<DisplayFileObject*> DisplayFile::getObjects(){
	return objects;
}
