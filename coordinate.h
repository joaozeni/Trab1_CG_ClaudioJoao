#ifndef COORDINATE_H
#define COORDINATE_H

#include <vector>

class Coordinate
{
public:
    Coordinate(float x, float y, float z=0.0);
    ~Coordinate();
    float x();
    void x(float newVal);

    float y();
    void y(float newVal);

    float z();
    void z(float newVal);

    std::vector<std::vector<float> > generateBaseMatrix();
    std::vector<std::vector<float> > generateMoveMatrix();
    std::vector<std::vector<float> > generateScaleMatrix();
private:
    float coordinates[3];
};

#endif // COORDINATE_H
