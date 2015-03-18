#ifndef COORDINATE_H
#define COORDINATE_H


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
private:
    float coordinates[3];
};

#endif // COORDINATE_H
