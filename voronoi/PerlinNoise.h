#ifndef PERLINNOISE_H
#define PERLINNOISE_H
#include <vector>
#include <glm/glm.hpp>

class PerlinNoise
{
public:
    PerlinNoise();
    float perlin(float x, float y, float z);

private:
    float fade(float t);

    float lerp(float t, float a, float b);
    float grad(int hash, float x, float y, float z);
    std::vector<int> permutation;
};

#endif // PERLINNOISE_H
