#ifdef DISPLAY_FILE_OBJECT_H
#define DISPLAY_FILE_OBJECT_H

#include "geometricObjects.h"

template<class X>
class DisplayFileObject{
    public:
        DisplayFileObject(X obj, string name, string type);
        getCoordinates();
        getName();
        getType();
    private:
    	X object;
    	string object_name;
        string object_type;
};

#endif
