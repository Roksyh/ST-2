// Copyright 2022 UNN-CS
#include "circle.h"

#include <cmath>
#include <stdexcept>

static const double PI = 3.14159265358979323846;

Circle::Circle(double r) {
    if (r < 0.0)
        throw std::invalid_argument("radius must be non-negative");
    radius = r;
    ference = 2.0 * PI * r;
    area = PI * r * r;
}

void Circle::setRadius(double r) {
    if (r < 0.0)
        throw std::invalid_argument("radius must be non-negative");
    radius = r;
    ference = 2.0 * PI * r;
    area = PI * r * r;
}

void Circle::setFerence(double f) {
    if (f < 0.0)
        throw std::invalid_argument("ference must be non-negative");
    ference = f;
    radius = f / (2.0 * PI);
    area = PI * radius * radius;
}

void Circle::setArea(double a) {
    if (a < 0.0)
        throw std::invalid_argument("area must be non-negative");
    area = a;
    radius = std::sqrt(a / PI);
    ference = 2.0 * PI * radius;
}

double Circle::getRadius() const {
    return radius;
}

double Circle::getFerence() const {
    return ference;
}

double Circle::getArea() const {
    return area;
}
