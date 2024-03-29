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
        std::vector<Coordinate*> getNormalizedCoordinates();
        std::string getName();
        std::string getType();
        void move(Coordinate * c);
        void scale(Coordinate * c);
        void rotate(float factor);
        void normalize(std::vector<std::vector<float> > transformM);
    private:
        GeometricObject * object;
        std::string object_name;
};

#endif // DISPLAYFILEOBJECT

