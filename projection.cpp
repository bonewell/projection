#include "projection.h"

#include <cmath>
#include <set>

#include "vector.h"

namespace projection {
using Calculations = std::multiset<ProjectionInfo>;

bool operator<(ProjectionInfo const& pi1, ProjectionInfo const& pi2) {
    return pi1.distance < pi2.distance;
}

std::ostream& operator<<(std::ostream &os, ProjectionInfo const& pi) {
    return os << "segment " << pi.segment <<
                 " parameter " << pi.parameter <<
                 " point " << pi.point;
}

void sort(Projections &projections) {
    sort(begin(projections), end(projections),
         [](auto const& p1, auto const& p2) {
        return p1.segment < p2.segment;
    });
}

std::pair<double, Point> calculateHeight(Point first, Point second, Point p) {
    Vector v1{first, second};
    Vector v2{first, p};
    double cosa = cosAngle(v1, v2);
    double sina = std::sqrt(1 - (cosa * cosa));
    double height = sina * v2.modulo();
    double parameter = (cosa * v2.modulo())/ v1.modulo();
    return std::make_pair(height, (v1 * parameter).e);
}

std::pair<double, Point> calculate(Point first, Point second, Point p) {
    Vector v1{first, second};
    Vector v2{first, p};
    double cosa = cosAngle(v1, v2);
    if (cosa <= 0) return std::make_pair(v2.modulo(), first);
    Vector v3{second, first};
    Vector v4{second, p};
    double cosb = cosAngle(v3, v4);
    if (cosb <= 0) return std::make_pair(v4.modulo(), second);
    return calculateHeight(first, second, p);
}

Projections find(Polyline polyline, Point p) {
    Calculations calculations;
    for (size_t i = 1; i < polyline.size(); ++i) {
        auto [distance, point] = calculate(polyline[i-1], polyline[i], p);
//        auto parameter = getParameter(polyline[i-1], polyline[i], point);
        double parameter = 0;
        calculations.insert({distance, static_cast<int>(i), parameter, point});
    }
    Projections projections{begin(calculations), end(calculations)};
    // filter by 1e-7
    sort(projections);
    return projections;
}
} // namespace projection
