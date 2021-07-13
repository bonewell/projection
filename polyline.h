#ifndef POLYLINE_H
#define POLYLINE_H

#include <iostream>
#include <vector>

namespace projection {
struct Point {
    double x{};
    double y{};
    double z{};
};
bool operator==(Point p1, Point p2);
std::istream& operator>>(std::istream& is, Point& p);
std::ostream& operator<<(std::ostream& os, Point const& p);

using Polyline = std::vector<Point>;
std::ostream& operator<<(std::ostream& os, Polyline const& polyline);
} // namespace projection

#endif // POLYLINE_H
