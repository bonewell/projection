#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "vector.h"

using ::testing::Eq;
using ::testing::DoubleNear;
using namespace projection;

TEST(VectorTest, Modulo) {
    Vector v{{}, {1.0, 1.0, 1.0}};

    EXPECT_THAT(v.modulo(), DoubleNear(1.7320508, 1e-7));
}

TEST(VectorTest, ScalarMultiplication) {
    Vector v1{{}, {1.0, 1.0, 1.0}};
    Vector v2{{}, {2.0, 2.0, 2.0}};

    EXPECT_THAT(v1 * v2, DoubleNear(6.0, 1e-7));
}

TEST(VectorTest, CosAngleFrom0To90) {
    Vector v1{{}, {1.0, 0.0, 0.0}};
    Vector v2{{}, {2.0, 2.0, 0.0}};

    EXPECT_THAT(cosAngle(v1, v2), DoubleNear(0.7071067, 1e-7));
}

TEST(VectorTest, CosAngleFrom90To180) {
    Vector v1{{}, {1.0, 0.0, 0.0}};
    Vector v2{{}, {-2.0, 2.0, 0.0}};

    EXPECT_THAT(cosAngle(v1, v2), DoubleNear(-0.7071067, 1e-7));
}

TEST(VectorTest, CosAngle0) {
    Vector v1{{}, {1.0, 0.0, 0.0}};
    Vector v2{{}, {2.0, 0.0, 0.0}};

    EXPECT_THAT(cosAngle(v1, v2), DoubleNear(1, 1e-7));
}

TEST(VectorTest, CosAngle90) {
    Vector v1{{}, {1.0, 0.0, 0.0}};
    Vector v2{{}, {0.0, 2.0, 0.0}};

    EXPECT_THAT(cosAngle(v1, v2), DoubleNear(0, 1e-7));
}

TEST(VectorTest, CosAngle180) {
    Vector v1{{}, {1.0, 0.0, 0.0}};
    Vector v2{{}, {-2.0, 0.0, 0.0}};

    EXPECT_THAT(cosAngle(v1, v2), DoubleNear(-1, 1e-7));
}

TEST(VectorTest, CosAngleX) {
    Vector v1{{1.0, 1.0, 1.0}, {4.0, 5.0, 1.0}};
    Vector v2{{-1.0, -1.0, -1.0}, {3.0, 3.0, 1.0}};

    EXPECT_THAT(cosAngle(v1, v2), DoubleNear(0.9333333, 1e-7));
}

TEST(VectorTest, NMultiplication) {
    Vector v{{1.0, 1.0, 1.0}, {5.0, 5.0, 5.0}};
    v *= 0.5;

    EXPECT_THAT(v.b, Eq(Point{1.0, 1.0, 1.0}));
    EXPECT_THAT(v.e, Eq(Point{3.0, 3.0, 3.0}));
}
