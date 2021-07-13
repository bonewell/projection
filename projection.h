#ifndef PROJECTION_H
#define PROJECTION_H

#include "polyline.h"

namespace projection {
struct ProjectionInfo {
    double distance{};
    int segment{};
    double parameter{};
    Point point{};
};
bool operator<(ProjectionInfo const& pi1, ProjectionInfo const& pi2);
std::ostream& operator<<(std::ostream& os, ProjectionInfo const& pi);

using Projections = std::vector<ProjectionInfo>;
Projections find(Polyline polyline, Point p);
} // namespace projection

#endif // PROJECTION_H
