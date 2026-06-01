// Copyright 2022 UNN-CS
#include "tasks.h"
#include "circle.h"

static const double EARTH_RADIUS_M = 6378100.0;
static const double POOL_RADIUS = 3.0;
static const double PATH_WIDTH = 1.0;
static const double CONCRETE_PRICE = 1000.0;
static const double FENCE_PRICE = 2000.0;

double earthRopeGap() {
    Circle earth(EARTH_RADIUS_M);
    double newFerence = earth.getFerence() + 1.0;
    Circle raised(0.0);
    raised.setFerence(newFerence);
    return raised.getRadius() - EARTH_RADIUS_M;
}

double poolConcreteCost() {
    Circle pool(POOL_RADIUS);
    Circle outer(POOL_RADIUS + PATH_WIDTH);
    double pathArea = outer.getArea() - pool.getArea();
    return pathArea * CONCRETE_PRICE;
}

double poolFenceCost() {
    Circle outer(POOL_RADIUS + PATH_WIDTH);
    return outer.getFerence() * FENCE_PRICE;
}
