#include "Vector3D.h"
#include <iostream>

Vector3D::Vector3D(double x, double y, double z) : X(x), Y(y), Z(z) {}

double Vector3D::getX() {
    return X;
}

double Vector3D::getY() {
    return Y;
}

double Vector3D::getZ() {
    return Z;
}

std::string Vector3D::stringVector() {
    return "Vector3D(" + std::to_string(X) + ", " + std::to_string(Y) + ", " + std::to_string(Z) + ")";
}

void Vector3D::printVector() {
    std::cout << stringVector() << std::endl;
}
