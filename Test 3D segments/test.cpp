#include "pch.h"

#include "../3D segments/3D segments.cpp"
#include "../3D segments/Segment3D.h"
#include "../3D segments/Segment3D.cpp"
#include "../3D segments/Vector3D.h"
#include "../3D segments/Vector3D.cpp"

using namespace std;

TEST(IntersectTest, SegmentsDoNotIntersectionAreas1) {
    Segment3D seg1 = Segment3D(Vector3D(3, -3, 2), Vector3D(2, -2, 4));
    Segment3D seg2 = Segment3D(Vector3D(-1, 4, -26), Vector3D(2, 0, -20));
    EXPECT_THROW(Intersect(seg1, seg2), runtime_error);
}

TEST(IntersectTest, SegmentsDoNotIntersectionAreas2) {
    Segment3D seg1 = Segment3D(Vector3D(-10, 10, 28), Vector3D(13, -13, -18));
    Segment3D seg2 = Segment3D(Vector3D(-1, 4, -26), Vector3D(2, 0, -20));
    EXPECT_THROW(Intersect(seg1, seg2), runtime_error);
}

TEST(IntersectTest, SegmentsDoNotIntersect) {
    Segment3D seg1 = Segment3D(Vector3D(-11, 10, 28), Vector3D(13, -13, -18));
    Segment3D seg2 = Segment3D(Vector3D(11, -12, -2), Vector3D(-1, 4, -26));
    EXPECT_THROW(Intersect(seg1, seg2), runtime_error);
}

TEST(IntersectTest, ThirdCase) {
    Segment3D seg1 = Segment3D(Vector3D(-10, 10, 28), Vector3D(13, -13, -18));
    Segment3D seg2 = Segment3D(Vector3D(11, -12, -2), Vector3D(-1, 4, -26));
    Vector3D point = Intersect(seg1, seg2);
    EXPECT_EQ(point.stringVector(), "Vector3D(8,000000, -8,000000, -8,000000)");
}

int main(int argc, char** argv) {
    setlocale(LC_ALL, "Russian");
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}