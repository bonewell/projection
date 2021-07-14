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

double get_distance(double cosa, Vector slope) {
    double sina = std::sqrt(1 - (cosa * cosa));
    return sina * slope.modulo();
}

double get_parameter(double cosa, Vector slope, Vector bottom) {
    return (cosa * slope.modulo())/ bottom.modulo();
}

Point get_point(Vector v, double parameter) {
    return (v * parameter).e;
}

ProjectionInfo calculate(Point first, Point second, Point p) {
    Vector bottomA{first, second};
    Vector a{first, p};
    double cosa = cosAngle(bottomA, a);
    Vector bottomB{second, first};
    Vector b{second, p};
    double cosb = cosAngle(bottomB, b);

    ProjectionInfo info;
    if (cosa <= 0) {
        info.distance = a.modulo();
        info.parameter = 0.0;
        info.point = first;
    }
    else if (cosb <= 0) {
        info.distance = b.modulo();
        info.parameter = 1.0;
        info.point = second;
    }
    else {
        info.distance = get_distance(cosa, a);
        info.parameter = get_parameter(cosa, a, bottomA);
        info.point = get_point(bottomA, info.parameter);
    }

    return info;
}

Calculations::const_iterator tail(Calculations const& calculations) {
    if (calculations.empty()) return end(calculations);
    auto value = *begin(calculations);
    value.distance += 1e-7;
    return std::upper_bound(begin(calculations), end(calculations), value);
}

Projections find(Polyline polyline, Point p) {
    Calculations calculations;
    for (size_t i = 1; i < polyline.size(); ++i) {
        auto info = calculate(polyline[i-1], polyline[i], p);
        info.segment = static_cast<int>(i);
        calculations.insert(std::move(info));
    }
    Projections projections{begin(calculations), tail(calculations)};
    sort(projections);
    return projections;
}
} // namespace projection
