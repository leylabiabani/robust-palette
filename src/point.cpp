#include "robust_palette/point.h"

#include <cmath>
#include <stdexcept>

namespace robust_palette 
{

double distance(const Point& p, const Point& q) 
{
    if (p.dimension() != q.dimension()) 
    {
        throw std::runtime_error("Points must have the same dimension");
    }

    double sum = 0.0;
    for (std::size_t i = 0; i < p.dimension(); ++i) 
    {
        const double diff = p[i] - q[i];
        sum += diff * diff;
    }

    return std::sqrt(sum);
}

}  // namespace robust_palette