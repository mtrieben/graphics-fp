#ifndef CIRCLE_H
#define CIRCLE_H

#include "../Types/Point2D.h"

#define CIRCLE_CENTER_EPSILON 1.0e-7

class Circle
{
public:
    Circle();
    static bool findCircleCenter(const Point2D &p1, const Point2D &p2, const Point2D &p3, Point2D &center);
};

#endif // CIRCLE_H
