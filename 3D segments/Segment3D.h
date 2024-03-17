#ifndef SEGMENT3D_H
#define SEGMENT3D_H

#include "Vector3D.h"

class Segment3D
{
    Vector3D start;
    Vector3D end;

public:
    Segment3D(Vector3D s, Vector3D e);

    Vector3D getStart();
    Vector3D getEnd();

    void printSegment();
};

#endif
