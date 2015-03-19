#ifndef DISPLAYFILEOBJECT
#define DISPLAYFILEOBJECT

#include <string>
#include <vector>
#include "coordinate.h"
#include "geometricobject.h"

class DisplayFileObject{
    public:
        DisplayFileObject(GeometricObject * obj, std::string name);
        ~DisplayFileObject();
        std::vector<Coordinate*> getCoordinates();
        std::string getName();
        std::string getType();
    private:
        GeometricObject * object;
        std::string object_name;
};

#endif // DISPLAYFILEOBJECT
