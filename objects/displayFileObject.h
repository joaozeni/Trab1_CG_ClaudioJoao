#ifndef DISPLAY_FILE_OBJECT_H
#define DISPLAY_FILE_OBJECT_H

#include <string>
#include "geometricObjects.h"
#include "coordinate.h"

class DisplayFileObject{
    public:
        DisplayFileObject(GeometricObject obj, std::string name, std::string type);
        ~DisplayFileObject();
	Coordinate getCoordinates();
        std::string getName();
        std::string getType();
    private:
    	GeometricObject object;
    	std::string object_name;
};

#endif
