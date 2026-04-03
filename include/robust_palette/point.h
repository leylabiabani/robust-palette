#pragma once

#include <vector>
#include <cstddef>

namespace robust_palette 
{

class Point {
public:
    Point() = default;

    Point(std::vector<double> coordinates, double weight = 1.0)
        : coordinates_(std::move(coordinates)), weight_(weight) {}

    std::size_t dimension() const { return coordinates_.size(); }

    double operator[](std::size_t i) const { return coordinates_[i]; }

    double weight() const { return weight_; }

private:
    std::vector<double> coordinates_;
    double weight_ = 1.0;
};

double distance(const Point& p, const Point& q);  

}  // namespace robust_palette