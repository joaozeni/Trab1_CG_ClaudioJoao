#ifdef DISPLAY_FILE_OBJECT_H
#define DISPLAY_FILE_OBJECT_H

#include <string>
#include "geometricObjects.h"

class DisplayFileObject{
    public:
        DisplayFileObject(GeometricObject obj, string name, string type);
        getCoordinates();
        getName();
        getType();
    private:
    	GeometricObject object;
    	std::string object_name;
        std::string object_type;
};

#endif
