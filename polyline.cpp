#include "polyline.h"

#include <cmath>

namespace projection {
bool compare(double x, double y) {
    return abs(x-y) < 1.e-7;
}

bool operator==(Point p1, Point p2) {
    return compare(p1.x, p2.x) && compare(p1.y, p2.y) && compare(p1.z, p2.z);
}

std::istream& operator>>(std::istream& is, Point &p) {
    return is >> p.x >> p.y >> p.z;
}

std::ostream& operator<<(std::ostream& os, const Point &p) {
    return os << p.x << ' ' << p.y << ' ' << p.z;
}

std::ostream& operator<<(std::ostream& os, const Polyline &polyline) {
    for (auto const& p: polyline) {
        os << p << '\n';
    }
    return os;
}
} // namespace projection
