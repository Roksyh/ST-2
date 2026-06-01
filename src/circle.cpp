// Copyright 2022 UNN-CS
#include <cmath>
#include "circle.h"

static const double PI = 3.14159265358979323846;

Circle::Circle(double r) {
    radius = r;
    ference = 2.0 * PI * r;
    area = PI * r * r;
}

void Circle::setRadius(double r) {
    radius = r;
    ference = 2.0 * PI * r;
    area = PI * r * r;
}

void Circle::setFerence(double f) {
    ference = f;
    radius = f / (2.0 * PI);
    area = PI * radius * radius;
}

void Circle::setArea(double a) {
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
