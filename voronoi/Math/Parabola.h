#ifndef PARABOLA_H
#define PARABOLA_H

#include "../Types/Point2D.h"

class Parabola
{
public:
    Parabola();

    static int intersectionPointsNum(const Point2D &f1, const Point2D &f2, double directrix);

    static std::vector<Point2D> findIntersectionPoints(const Point2D &f1, const Point2D &f2, double directrix);
};

#endif // PARABOLA_H
