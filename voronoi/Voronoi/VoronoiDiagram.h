#ifndef VORONOIDIAGRAM_H
#define VORONOIDIAGRAM_H

#include "voronoi/Types/Point2D.h"
#include "voronoi/Datastruct/Beachline.h"

namespace bl = beachline;

class VoronoiDiagram
{
public:
    VoronoiDiagram();

    static void build_voronoi(const std::vector<Point2D> &points,
                       std::vector<bl::HalfEdgePtr> &halfedges,
                       std::vector<bl::VertexPtr> &vertices,
                       std::vector<bl::HalfEdgePtr> &faces);
};

#endif // VORONOIDIAGRAM_H
