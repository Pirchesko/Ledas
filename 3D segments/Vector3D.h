#ifndef VECTOR3D_H
#define VECTOR3D_H

#include <string>

class Vector3D
{
    double X;
    double Y;
    double Z;

public:
    Vector3D(double x, double y, double z);

    double getX();
    double getY();
    double getZ();

    std::string stringVector();
    void printVector();
};

#endif