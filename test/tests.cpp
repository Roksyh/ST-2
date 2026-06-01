// Copyright 2025 UNN-CS Team

#include <gtest/gtest.h>
#include <cmath>
#include <stdexcept>
#include "circle.h"
#include "tasks.h"

static const double PI = acos(-1.0);

TEST(CircleTest, ConstructorSetsRadius) {
    Circle c(5.0);
    EXPECT_DOUBLE_EQ(5.0, c.getRadius());
}

TEST(CircleTest, ConstructorCalculatesFerence) {
    Circle c(1.0);
    EXPECT_NEAR(2.0 * PI, c.getFerence(), 1e-9);
}

TEST(CircleTest, ConstructorCalculatesArea) {
    Circle c(1.0);
    EXPECT_NEAR(PI, c.getArea(), 1e-9);
}

TEST(CircleTest, ConstructorRadiusFive) {
    Circle c(5.0);
    EXPECT_NEAR(10.0 * PI, c.getFerence(), 1e-9);
    EXPECT_NEAR(25.0 * PI, c.getArea(), 1e-9);
}

TEST(CircleTest, SetRadiusUpdatesRadius) {
    Circle c(1.0);
    c.setRadius(3.0);
    EXPECT_DOUBLE_EQ(3.0, c.getRadius());
}

TEST(CircleTest, SetRadiusUpdatesFerence) {
    Circle c(1.0);
    c.setRadius(3.0);
    EXPECT_NEAR(6.0 * PI, c.getFerence(), 1e-9);
}

TEST(CircleTest, SetRadiusUpdatesArea) {
    Circle c(1.0);
    c.setRadius(3.0);
    EXPECT_NEAR(9.0 * PI, c.getArea(), 1e-9);
}

TEST(CircleTest, SetFerenceUpdatesFerence) {
    Circle c(1.0);
    c.setFerence(10.0);
    EXPECT_DOUBLE_EQ(10.0, c.getFerence());
}

TEST(CircleTest, SetFerenceUpdatesRadius) {
    Circle c(1.0);
    c.setFerence(2.0 * PI * 7.0);
    EXPECT_NEAR(7.0, c.getRadius(), 1e-9);
}

TEST(CircleTest, SetFerenceUpdatesArea) {
    Circle c(1.0);
    c.setFerence(2.0 * PI * 7.0);
    EXPECT_NEAR(49.0 * PI, c.getArea(), 1e-9);
}

TEST(CircleTest, SetAreaUpdatesArea) {
    Circle c(1.0);
    c.setArea(25.0 * PI);
    EXPECT_NEAR(25.0 * PI, c.getArea(), 1e-9);
}

TEST(CircleTest, SetAreaUpdatesRadius) {
    Circle c(1.0);
    c.setArea(25.0 * PI);
    EXPECT_NEAR(5.0, c.getRadius(), 1e-9);
}

TEST(CircleTest, SetAreaUpdatesFerence) {
    Circle c(1.0);
    c.setArea(25.0 * PI);
    EXPECT_NEAR(10.0 * PI, c.getFerence(), 1e-9);
}

TEST(CircleTest, ZeroRadius) {
    Circle c(0.0);
    EXPECT_DOUBLE_EQ(0.0, c.getRadius());
    EXPECT_DOUBLE_EQ(0.0, c.getFerence());
    EXPECT_DOUBLE_EQ(0.0, c.getArea());
}

TEST(CircleTest, ConsistencyAfterSetRadius) {
    Circle c(7.0);
    double r = c.getRadius();
    EXPECT_NEAR(2.0 * PI * r, c.getFerence(), 1e-9);
    EXPECT_NEAR(PI * r * r, c.getArea(), 1e-9);
}

TEST(CircleTest, ConsistencyAfterSetFerence) {
    Circle c(2.0);
    c.setFerence(30.0);
    double r = c.getRadius();
    EXPECT_NEAR(2.0 * PI * r, c.getFerence(), 1e-9);
    EXPECT_NEAR(PI * r * r, c.getArea(), 1e-9);
}

TEST(CircleTest, ConsistencyAfterSetArea) {
    Circle c(2.0);
    c.setArea(50.0);
    double r = c.getRadius();
    EXPECT_NEAR(2.0 * PI * r, c.getFerence(), 1e-9);
    EXPECT_NEAR(PI * r * r, c.getArea(), 1e-9);
}

TEST(CircleTest, LargeRadius) {
    Circle c(1e6);
    EXPECT_NEAR(2.0 * PI * 1e6, c.getFerence(), 1e-3);
    EXPECT_NEAR(PI * 1e12, c.getArea(), 1e3);
}

TEST(CircleTest, NegativeRadiusThrows) {
    EXPECT_THROW(Circle(-1.0), std::invalid_argument);
}

TEST(CircleTest, NegativeFerenceThrows) {
    Circle c(1.0);
    EXPECT_THROW(c.setFerence(-5.0), std::invalid_argument);
}

TEST(CircleTest, NegativeAreaThrows) {
    Circle c(1.0);
    EXPECT_THROW(c.setArea(-10.0), std::invalid_argument);
}

TEST(EarthRopeTest, GapIsPositive) {
    EXPECT_GT(earthRopeGap(), 0.0);
}

TEST(EarthRopeTest, GapApproximateValue) {
    EXPECT_NEAR(1.0 / (2.0 * PI), earthRopeGap(), 1e-6);
}

TEST(EarthRopeTest, GapIsLessThanOneMeter) {
    EXPECT_LT(earthRopeGap(), 1.0);
}

TEST(EarthRopeTest, GapIsIndependentOfEarthRadius) {
    double gap = earthRopeGap();
    EXPECT_NEAR(0.159, gap, 0.001);
}

TEST(PoolTest, ConcreteCostIsPositive) {
    EXPECT_GT(poolConcreteCost(), 0.0);
}

TEST(PoolTest, FenceCostIsPositive) {
    EXPECT_GT(poolFenceCost(), 0.0);
}

TEST(PoolTest, ConcreteCostValue) {
    EXPECT_NEAR(7.0 * PI * 1000.0, poolConcreteCost(), 1.0);
}

TEST(PoolTest, FenceCostValue) {
    EXPECT_NEAR(2.0 * PI * 4.0 * 2000.0, poolFenceCost(), 1.0);
}

TEST(PoolTest, FenceCostGreaterThanConcrete) {
    EXPECT_GT(poolFenceCost(), poolConcreteCost());
}
