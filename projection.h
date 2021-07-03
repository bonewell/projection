#include "polyline.h"

template <typename T>
struct ProjectionInfo {
    int segment;
    double parameter;
    Point<T> point;
};

template <typename T>
std::ostream& operator<<(std::ostream& os, ProjectionInfo<T> const& pi) {
    return os << "segment " << pi.segment <<
                 " parameter " << pi.parameter <<
                 " point" << pi.point;
}

template <typename T>
std::vector<ProjectionInfo<T>> find(Polyline<T> polyline, Point<T> p) {
    return {};
}
