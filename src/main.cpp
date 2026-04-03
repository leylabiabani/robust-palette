#include <iostream>
#include "robust_palette/point.h"

int main() {
    robust_palette::Point p({0.0, 0.0});
    robust_palette::Point q({3.0, 4.0}, 2.0);

    std::cout << "p dimension: " << p.dimension() << "\n";
    std::cout << "q weight: " << q.weight() << "\n";
    std::cout << "distance(p, q): " << robust_palette::distance(p, q) << "\n";

    return 0;
}