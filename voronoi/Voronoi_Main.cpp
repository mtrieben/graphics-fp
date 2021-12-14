#include "Voronoi_Main.h"

Voronoi_Main::Voronoi_Main()
{

}

#include <ctime>
#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>

#include "Types/Point2D.h"
#include "Voronoi/VoronoiDiagram.h"
#include "Datastruct/Beachline.h"


//#include "matplotlibcpp.h"

namespace bl = beachline;
//namespace plt = matplotlibcpp;

std::vector<double> get_coordinate(const std::vector<Point2D> &points, int coord_id) {
    std::vector<double> c(points.size(), 0.0);
    if (coord_id == 0) {
        for (size_t i = 0; i < points.size(); ++i) {
            c[i] = points[i].x;
        }
    } else {
        for (size_t i = 0; i < points.size(); ++i) {
            c[i] = points[i].y;
        }
    }
    return c;
}

std::vector<double> get_coordinate(const std::vector<bl::VertexPtr> &points, int coord_id) {
    std::vector<double> c(points.size(), 0.0);
    if (coord_id == 0) {
        for (size_t i = 0; i < points.size(); ++i) {
            c[i] = points[i]->point.x;
        }
    } else {
        for (size_t i = 0; i < points.size(); ++i) {
            c[i] = points[i]->point.y;
        }
    }
    return c;
}


void plot_circle(const Point2D &c, double r) {
    std::vector<double> x, y;
    for (double t = 0.0; t < 2 * M_PI + 0.05; t += 0.05) {
        x.push_back(sin(t) * r + c.x);
        y.push_back(cos(t) * r + c.y);
    }
//    plt::plot(x, y, "m-");
}

std::vector<Point2D> readPoints(const std::string &fileName, int step=1) {

    std::vector<Point2D> points;
    std::ifstream in(fileName);

    double x, y;
    int points_n = 0, i =0;

    if (in) {
        in >> points_n;
        for (int p_i = 0; p_i < points_n; ++p_i) {
            in >> x >> y;
            if (p_i == i) {
                points.push_back(Point2D(x, y));
                i += step;
            }
        }
    }
    return points;
}


double random_number() {
    return double(rand()) / double(RAND_MAX);
}


std::vector<Point2D> randomPoint(int number) {
    srand(static_cast<unsigned int>(time(0)));
    std::vector<Point2D> points;
    for (int i = 0; i < number; ++i) {
        double x = random_number(), y = random_number();
        points.push_back(Point2D(x*200.f, y*200.f));
    }
    std::sort(points.begin(), points.end(), [](const Point2D &p1, const Point2D &p2) {
        return (fabs(p1.y - p2.y) < POINT_EPSILON && p1.x < p2.x) || (fabs(p1.y - p2.y) >= POINT_EPSILON && p1.y < p2.y);
    });
    for (int i = 1; i < number; ++i) {
        if ((points[i-1] - points[i]).norm() < POINT_EPSILON) {
            points[i-1].x = random_number();
        }
    }
    for (int i = number-1; i >= 0; --i) {
        int j = rand() % (i+1);
        std::swap(points[i], points[j]);
    }
    return points;
}


void initEdgePointsVis(bl::HalfEdgePtr h, std::vector<double> &x, std::vector<double> &y,
                       const std::vector<Point2D> &points) {

    if (h->vertex != nullptr && h->twin->vertex != nullptr) {

        x[0] = h->vertex->point.x;
        x[1] = h->twin->vertex->point.x;

        y[0] = h->vertex->point.y;
        y[1] = h->twin->vertex->point.y;

    } else if (h->vertex != nullptr) {

        x[0] = h->vertex->point.x;
        y[0] = h->vertex->point.y;

        Point2D norm = (points[h->l_index] - points[h->r_index]).normalized().getRotated90CCW();
        x[1] = x[0] + norm.x * 1000;
        y[1] = y[0] + norm.y * 1000;

    } else if (h->twin->vertex != nullptr) {

        x[0] = h->twin->vertex->point.x;
        y[0] = h->twin->vertex->point.y;

        Point2D norm = (points[h->twin->l_index] - points[h->twin->r_index]).normalized().getRotated90CCW();
        x[1] = x[0] + norm.x * 1000;
        y[1] = y[0] + norm.y * 1000;

    } else {

        Point2D p1 = points[h->l_index], p2 = points[h->r_index];

        Point2D norm = (p1 - p2).normalized().getRotated90CCW();
        Point2D c = 0.5 * (p1 + p2);

        x[0] = c.x + norm.x * 1000;
        x[1] = c.x - norm.x * 1000;

        y[0] = c.y + norm.y * 1000;
        y[1] = c.y - norm.y * 1000;
    }
}

std::vector<float> getBounds(std::vector<std::vector<float>> face_points) {
    float minX = INFINITY;
    float maxX = -INFINITY;
    float minY = INFINITY;
    float maxY = -INFINITY;

    for(int i = 0; i < face_points.size(); i++) {
        if (face_points[i][0] < minX) {
            minX = face_points[i][0];
        }
        if (face_points[i][0] > maxX) {
            maxX = face_points[i][0];
        }
        if (face_points[i][1] < minY) {
            minY = face_points[i][1];
        }
        if (face_points[i][1] > maxY) {
            maxY = face_points[i][1];
        }
    }

    return {minX, minY, maxX, maxY};
}

bool collinearAndOnSegment(std::vector<float> start, std::vector<float> queryPoint, std::vector<float> end) {
    return (queryPoint[0] <= std::max(start[0], end[0]) && queryPoint[0] >= std::min(start[0], end[0])
            && queryPoint[1] <= std::max(start[1], end[1]) && queryPoint[1] >= std::min(start[1], end[1]));
}

int orientationOrCollinear(std::vector<float> p1, std::vector<float> p2, std::vector<float> p3)
{
    int res = (p2[1] - p1[1]) * (p3[0] - p2[0]) -
            (p2[0] - p1[0]) * (p3[1] - p2[1]);

    if (res == 0) return res; // collinear
    return (res > 0) ? 1 : 2; // clock or counterclock wise
}

bool linesIntersect(std::vector<float> start1, std::vector<float> end1, std::vector<float> start2, std::vector<float> end2)
{
    int o1 = orientationOrCollinear(start1, end1, start2);
    int o2 = orientationOrCollinear(start1, end1, end2);
    int o3 = orientationOrCollinear(start2, end2, start1);
    int o4 = orientationOrCollinear(start2, end2, end1);

    if (o1 != o2 && o3 != o4)
        return true;

    if (o1 == 0 && collinearAndOnSegment(start1, start2, end1)) return true;

    if (o2 == 0 && collinearAndOnSegment(start1, end2, end1)) return true;

    if (o3 == 0 && collinearAndOnSegment(start2, start1, end2)) return true;

    if (o4 == 0 && collinearAndOnSegment(start2, end1, end2)) return true;

    return false;
}

bool pointInPolygon(float x, float y, std::vector<std::vector<float>> face_points) {
    std::vector<float> endPoint = {50000, y};

    int counter = 0, i = 0;

    do {
        int next = (i+1) % face_points.size();

//        std::cout << "p1: " << face_points[i][0] << ", " << face_points[i][1]
//                  << " q1: " << face_points[next][0] << ", " << face_points[next][1]
//                  << " p2: " << x << ", " << y
//                  << " q2: " << endPoint[0] << ", " << endPoint[1]<< std::endl;
//        std::cout << linesIntersect(face_points[i], face_points[next], {x, y}, endPoint) << std::endl;

        if (linesIntersect(face_points[i], face_points[next], {x, y}, endPoint)) {
            if (orientationOrCollinear(face_points[i], {x, y}, face_points[next]) == 0) {
                return collinearAndOnSegment(face_points[i], {x, y}, face_points[next]);
            }

            counter++;
        }
        i = next;
    } while (i != 0);

    return counter % 2 == 1;
}

std::vector<float> bindPoint(std::vector<float> source, std::vector<float> target, std::vector<std::vector<float>> face_points) {
    std::vector<float> boundPoint = source;
    std::vector<float> u = {target[0] - source[0], target[1] - source[1]};
    float uLength = sqrt(u[0] * u[0] + u[1] * u[1]);
    u[0] /= uLength;
    u[1] /= uLength;

    while (pointInPolygon(boundPoint[0], boundPoint[1], face_points)) {
        boundPoint[0] += u[0];
        boundPoint[1] += u[1];
    }

    return boundPoint;
}

std::vector<float> bindPointSpecialCase(std::vector<float> source, std::vector<float> target, std::vector<std::vector<float>> face_points) {
    std::vector<float> boundPoint = source;
    std::vector<float> u = {target[0] - source[0], target[1] - source[1]};
    float uLength = sqrt(u[0] * u[0] + u[1] * u[1]);
    u[0] /= uLength;
    u[1] /= uLength;

    while (!pointInPolygon(boundPoint[0], boundPoint[1], face_points)) {
        if (abs(target[0] - boundPoint[0]) < 2) return {};
        boundPoint[0] += u[0];
        boundPoint[1] += u[1];
    }

    return boundPoint;
}

std::vector<std::vector<float>> boundRoad(std::vector<float> p1, std::vector<float> p2, std::vector<std::vector<float>> face_points) {
    std::vector<float> insidePoint;
    std::vector<float> boundedPoint;

    if(pointInPolygon(p1[0], p1[1], face_points)) {
        if(pointInPolygon(p2[0], p2[1], face_points)) {
            return {p1, p2};
        } else {
            insidePoint = p1;
            boundedPoint = bindPoint(insidePoint, p2, face_points);
        }
    } else {
        if(pointInPolygon(p2[0], p2[1], face_points)) {
            insidePoint = p2;
            boundedPoint = bindPoint(insidePoint, p1, face_points);
        }
        else {
            insidePoint = bindPointSpecialCase(p1, p2, face_points);
            if (insidePoint.size() != 2) return {};
            boundedPoint = bindPoint(insidePoint, p2, face_points);
        }
    }

    return {insidePoint, boundedPoint};
}

std::vector<std::vector<float>> boundToCanvas(std::vector<std::vector<float>> points, std::vector<std::vector<float>> corners) {
    std::vector<std::vector<float>> boundResult;

    for (int i = 0; i < points.size(); i+=2) {
        std::vector<std::vector<float>> boundedRoad = boundRoad(points[i], points[i+1], corners);
        if(boundedRoad.size() == 2) {
            boundResult.push_back(boundedRoad[0]);
            boundResult.push_back(boundedRoad[1]);
        }
    }

    return boundResult;
}

std::vector<std::vector<float>> generateSecondaryRoads(std::vector<std::vector<float>> face_points) {
    std::vector<Point2D> pointSet;
    std::vector<std::vector<float>> res = {};
    std::vector<float> topLeftBottomRight = getBounds(face_points);

    for (float x = std::max(topLeftBottomRight[0] + 5.f, 0.f); x < std::min(topLeftBottomRight[2] - 5.f, 200.f); x += 15) {
        for (float y = std::max(topLeftBottomRight[1] + 5.f, 0.f); y < std::min(topLeftBottomRight[3] - 5.f, 200.f); y += 15) {
            if (pointInPolygon(x, y, face_points)) {
                pointSet.push_back(Point2D(x, y));
            }
        }
    }

    std::vector<bl::HalfEdgePtr> halfedges, faces;
    std::vector<bl::VertexPtr> vertices;

    // Construct Voronoi diagram
    VoronoiDiagram::build_voronoi(pointSet, halfedges, vertices, faces);

    for (size_t i = 0; i < halfedges.size(); ++i) {
        bl::HalfEdgePtr h = halfedges[i];
        std::vector<double> x(2, 0.0), y(2, 0.0);
        initEdgePointsVis(h, x, y, pointSet);

        std::vector<float> p1;
        p1.push_back(x[0]);
        p1.push_back(y[0]);
        std::vector<float> p2;
        p2.push_back(x[1]);
        p2.push_back(y[1]);
        std::vector<std::vector<float>> boundedPoints = boundRoad(p1, p2, face_points);
        if(boundedPoints.size() == 2) {
            res.push_back(boundedPoints[0]);
            res.push_back(boundedPoints[1]);
        }
    }

    return res;
}


std::vector<std::vector<std::vector<float>>> Voronoi_Main::main() {
    std::vector<std::vector<std::vector<float>>> res;
    std::vector<std::vector<float>> primary;

    // Generate random points
    std::vector<Point2D> points = randomPoint(7);

//    std::vector<Point2D> points = {Point2D(100, 100), Point2D(200, 350), Point2D(350, 100)};
    //std::vector<Point2D> points = readPoints("/Users/dkotsur/Projects/KNU/FortuneAlgo/Data/fail_1.txt");

    std::vector<bl::HalfEdgePtr> halfedges, faces;
    std::vector<bl::VertexPtr> vertices;

    for(size_t i = 0; i < points.size(); ++i) {
        std::vector<double> _x, _y;
        _x.push_back(points[i].x); _y.push_back(points[i].y);
    }

    // Construct Voronoi diagram
    VoronoiDiagram::build_voronoi(points, halfedges, vertices, faces);

    for (size_t i = 0; i < halfedges.size(); ++i) {
        bl::HalfEdgePtr h = halfedges[i];
        std::vector<double> x(2, 0.0), y(2, 0.0);
        initEdgePointsVis(h, x, y, points);

//        res.push_back(x[0]);
//        res.push_back(y[0]);
//        res.push_back(x[1]);
//        res.push_back(y[1]);

//        plt::plot(x, y, "lightgray");
    }

    // Check if iterator works fine
    for (size_t i = 0; i < halfedges.size(); ++i) {
        bl::HalfEdgePtr h = halfedges[i];
        do {
            assert(halfedges[i]->l_index == h->l_index);
            h = h->next;
        } while (h != nullptr && h != halfedges[i]);
    }

    /**
     Iterate around the vertex CCW
     */
    bl::HalfEdgePtr he_end = halfedges[6], he = he_end;
//    if (he->vertex != nullptr) {
//        do {
//            std::vector<double> x(2, 0.0), y(2, 0.0);
//            initEdgePointsVis(he, x, y, points);
//            plt::plot(x, y, "m-");
//            he = he->vertexNextCCW();
//        } while (he != he_end && he != nullptr);
//    }
//    printf("\n\n");

    std::vector<std::vector<float>> canvas_corners = {{0.f, 0.f}, {0.f, 200.f}, {200.f, 200.f}, {200.f, 0.f}};

    /**
     Iterate around the point CCW
     */
    for (int counter = 0; counter < faces.size(); counter++) {
        std::vector<std::vector<float>> face_points;
        he_end = faces[counter]; he = he_end;
        if (he != nullptr) {
            do {
                std::vector<double> x(2, 0.0), y(2, 0.0);
                initEdgePointsVis(he, x, y, points);

                bool p1seen = false;
                bool p2seen = false;
                for (int pIndex = 0; pIndex < face_points.size(); pIndex++) {
                    if (abs(face_points[pIndex][0] - x[0]) < 0.5 && abs(face_points[pIndex][1] - y[0]) < 0.5) {
                        p1seen = true;
                    }
                    if (abs(face_points[pIndex][0] - x[1]) < 0.5 && abs(face_points[pIndex][1] - y[1]) < 0.5) {
                        p2seen = true;
                    }
                }

                std::vector<float> p1;
                p1.push_back(x[0]);
                p1.push_back(y[0]);
                primary.push_back(p1);

                std::vector<float> p2;
                p2.push_back(x[1]);
                p2.push_back(y[1]);
                primary.push_back(p2);


                if (!p2seen) {
                    face_points.push_back(p2);
//                    std::cout << x[1] << ", " << y[1] << std::endl;
                }

                if (!p1seen) {
                    face_points.push_back(p1);
//                    std::cout << x[0] << ", " << y[0] << std::endl;
                }

//                std::cout << x[0] << ", " << y[0] << ", " << x[1] << ", " << y[1] << std::endl;

                he = he->next;
            } while (he != nullptr && he != he_end);
        }

        res.push_back(boundToCanvas(generateSecondaryRoads(face_points), canvas_corners));
    }

    res.push_back(boundToCanvas(primary, canvas_corners));

    return res;
}

