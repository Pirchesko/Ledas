#include <iostream>
#include <string>

#include "Segment3D.h"

using namespace std;

//Проекции области определения по любой координате должны иметь каку-нибудь общую область
bool intersectionAreas(double c1, double c2, double c3, double c4) {
    if (c1 >= c2) {
        swap(c1, c2);
    }
    if (((c1 >= c3) && (c1 <= c4)) || ((c2 >= c3) && (c2 <= c4)) || ((c1 <= c3) && (c2 >= c4))) {
        return true;
    }
    else {
        return false;
    }
}

Vector3D Intersect(Segment3D seg1, Segment3D seg2) {
    //Проверить, что точка может вообще существовать
    //...

    Vector3D vec1 = seg1.getStart();
    Vector3D vec2 = seg1.getEnd();
    Vector3D vec3 = seg2.getStart();
    Vector3D vec4 = seg2.getEnd();
    
    double x1 = vec1.getX();
    double y1 = vec1.getY();
    double z1 = vec1.getZ();

    double x2 = vec2.getX();
    double y2 = vec2.getY();
    double z2 = vec2.getZ();

    double x3 = vec3.getX();
    double y3 = vec3.getY();
    double z3 = vec3.getZ();

    double x4 = vec4.getX();
    double y4 = vec4.getY();
    double z4 = vec4.getZ();

    //Проверяем, чтобы потенциальная точка пересечения существовала в области определения отрезков
    if (!(intersectionAreas(x1, x2, x3, x4) && intersectionAreas(y1, y2, y3, y4) && intersectionAreas(z1, z2, z3, z4))) {
        throw runtime_error("Отрезки не пересекаются (по области определения)");
    }

    double s = ((y1 - y3) * (x2 - x1) - (y2 - y1) * (x1 - x3)) / ((y4 - y3) * (x2 - x1) - (y2 - y1) * (x4 - x3));
    double t = ((x4 - x3) * s - (x1 - x3)) / (x2 - x1); //можно было больше вариантов повыводить формулы, чтобы избежать ошибки от деления на 0...

    double x12 = (x2 - x1) * t + x1;
    double x34 = (x4 - x3) * s + x3;
    double y12 = (y2 - y1) * t + y1;
    double y34 = (y4 - y3) * s + y3;
    double z12 = (z2 - z1) * t + z1;
    double z34 = (z4 - z3) * s + z3;

    if ((z12 == z34) && (x12==x34) && (y12 == y34)) {
        return Vector3D(x12, y12, z12);
    }
    else {
        throw runtime_error("Отрезки не пересекаются");
    }
}

//int main(int argc, char** argv)
//{
//    setlocale(LC_ALL, "Russian");
//
//    try {
//        Segment3D seg1 = Segment3D(Vector3D(3, -3, 2), Vector3D(2, -2, 4));
//        Segment3D seg2 = Segment3D(Vector3D(-1, 4, -26), Vector3D(2, 0, -20));
//        Vector3D point = Intersect(seg1, seg2);
//        point.printVector();
//    } 
//    catch (exception e) {
//        cout << e.what() << endl;
//    }
//
//    try {
//        Segment3D seg1 = Segment3D(Vector3D(-10, 10, 28), Vector3D(13, -13, -18));
//        Segment3D seg2 = Segment3D(Vector3D(-1, 4, -26), Vector3D(2, 0, -20));
//        Vector3D point = Intersect(seg1, seg2);
//        point.printVector();
//    }
//    catch (exception e) {
//        cout << e.what() << endl;
//    }
//    
//    try {
//        Segment3D seg1 = Segment3D(Vector3D(-11, 10, 28), Vector3D(13, -13, -18));
//        Segment3D seg2 = Segment3D(Vector3D(11, -12, -2), Vector3D(-1, 4, -26));
//        Vector3D point = Intersect(seg1, seg2);
//        point.printVector();
//    }
//    catch (exception e) {
//        cout << e.what() << endl;
//    }
// 
//    try {
//        Segment3D seg1 = Segment3D(Vector3D(-10, 10, 28), Vector3D(13, -13, -18));
//        Segment3D seg2 = Segment3D(Vector3D(11, -12, -2), Vector3D(-1, 4, -26));
//        Vector3D point = Intersect(seg1, seg2);
//        point.printVector();
//    }
//    catch (exception e) {
//        cout << e.what() << endl;
//    }
//}