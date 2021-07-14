#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "projection.h"

using ::testing::Eq;
using ::testing::DoubleNear;
using namespace projection;

TEST(ProjectionTest, LeftBevel) {
    auto res = find({{}, {5.0, 0.0, 0.0}}, {-3.0, 1.0, 0.0});

    ASSERT_THAT(res.size(), Eq(1));
    EXPECT_THAT(res[0].distance, DoubleNear(3.1622776, 1e-7));
    EXPECT_THAT(res[0].point, Eq(Point{}));
}

TEST(ProjectionTest, RightBevel) {
    auto res = find({{}, {5.0, 0.0, 0.0}}, {8.0, 1.0, 0.0});

    ASSERT_THAT(res.size(), Eq(1));
    EXPECT_THAT(res[0].distance, DoubleNear(3.1622776, 1e-7));
    EXPECT_THAT(res[0].point, Eq(Point{5.0}));
}

TEST(ProjectionTest, NoBevel) {
    auto res = find({{}, {5.0, 0.0, 0.0}}, {3.0, 1.0, 0.0});

    ASSERT_THAT(res.size(), Eq(1));
    EXPECT_THAT(res[0].distance, DoubleNear(1.0, 1e-7));
    EXPECT_THAT(res[0].point, Eq(Point{3.0, 0.0, 0.0}));
}

TEST(ProjectionTest, Sort) {
    auto res = find({{-5.0, -5.0, 0.0}, {-5.0, 5.0, 0.0},
                     {5.0, 5.0, 0.0}, {5.0, -5.0, 0.0}}, {});

    ASSERT_THAT(res.size(), Eq(3));
    EXPECT_THAT(res[0].segment, Eq(1));
    EXPECT_THAT(res[1].segment, Eq(2));
    EXPECT_THAT(res[2].segment, Eq(3));
}

TEST(ProjectionTest, Filter) {
    auto res = find({{-5.0, 5.0, 0.0}, {-1.0, 10.0, 0.0},
                     {1.0, 10.0, 0.0}, {5.0, 5.0, 0.0}}, {});

    ASSERT_THAT(res.size(), Eq(2));
    EXPECT_THAT(res[0].segment, Eq(1));
    EXPECT_THAT(res[1].segment, Eq(3));
}
