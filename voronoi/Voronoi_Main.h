#ifndef VORONOI_MAIN_H
#define VORONOI_MAIN_H

#include <vector>
#include "Datastruct/Beachline.h"

namespace bl = beachline;

class Voronoi_Main
{
public:
    Voronoi_Main();

    std::vector<std::vector<std::vector<float>>> main();
    std::vector<std::vector<float>> generateSecondaryRoads(std::vector<std::vector<float>> face_points, int dist);
    std::vector<std::vector<std::vector<float>>> getBuildyPoints();
    std::vector<std::vector<std::vector<float>>> getGreens();

    std::vector<std::vector<std::vector<float>>> m_allRoads;
    std::vector<std::vector<float>> m_primaryRoads;
    std::vector<std::vector<std::vector<float>>> m_secondaryRoads;

    std::vector<bl::HalfEdgePtr> m_primaryHalfedges, m_primaryFaces;
    std::vector<bl::VertexPtr> m_primaryVertices;

    std::vector<std::vector<std::vector<float>>> m_buildy_points;
    std::vector<std::vector<std::vector<float>>> m_greens;
};

#endif // VORONOI_MAIN_H
