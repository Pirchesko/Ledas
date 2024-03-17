#include "Segment3D.h"
#include <iostream>

Segment3D::Segment3D(Vector3D s, Vector3D e) : start(s), end(e) {}

Vector3D Segment3D::getStart() {
    return start;
}

Vector3D Segment3D::getEnd() {
    return end;
}

void Segment3D::printSegment() {
    std::cout << "Segment3D(" << start.stringVector() << ", " << end.stringVector() << ")" << std::endl;
}
