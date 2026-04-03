#include "robust_palette/point.h"

#include <cmath>
#include <iostream>
#include <stdexcept>

using robust_palette::Point;
using robust_palette::distance;

namespace {

bool almost_equal(double x, double y, double eps = 1e-9) {
    return std::fabs(x - y) < eps;
}

void test_default_weight() {
    Point p({1.0, 2.0});
    if (!almost_equal(p.weight(), 1.0)) {
        throw std::runtime_error("Default weight should be 1.0");
    }
}

void test_dimension() {
    Point p({1.0, 2.0, 3.0});
    if (p.dimension() != 3) {
        throw std::runtime_error("Dimension should be 3");
    }
}

void test_coordinates() {
    Point p({4.0, 5.0});
    if (!almost_equal(p[0], 4.0) || !almost_equal(p[1], 5.0)) {
        throw std::runtime_error("Coordinates are incorrect");
    }
}

void test_custom_weight() {
    Point p({1.0, 2.0}, 7.5);
    if (!almost_equal(p.weight(), 7.5)) {
        throw std::runtime_error("Custom weight is incorrect");
    }
}

void test_distance_2d() {
    Point p({0.0, 0.0});
    Point q({3.0, 4.0});
    if (!almost_equal(distance(p, q), 5.0)) {
        throw std::runtime_error("Distance should be 5.0");
    }
}

void test_distance_dimension_mismatch() {
    Point p({1.0, 2.0});
    Point q({1.0, 2.0, 3.0});

    bool threw = false;
    try {
        (void)distance(p, q);
    } catch (const std::runtime_error&) {
        threw = true;
    }

    if (!threw) {
        throw std::runtime_error("distance() should throw on dimension mismatch");
    }
}

}  // namespace

int main() {
    try {
        test_default_weight();
        test_dimension();
        test_coordinates();
        test_custom_weight();
        test_distance_2d();
        test_distance_dimension_mismatch();
    } catch (const std::exception& e) {
        std::cerr << "Test failed: " << e.what() << "\n";
        return 1;
    }

    std::cout << "All Point tests passed.\n";
    return 0;
}