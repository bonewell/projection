#ifndef POLYLINE_H
#define POLYLINE_H

#include <iostream>
#include <utility>
#include <vector>

template <typename T>
struct Point {
    using type_value = T;
    type_value x{};
    type_value y{};
    type_value z{};
};

template <typename T>
std::istream& operator>>(std::istream& is, Point<T>& p) {
    return is >> p.x >> p.y >> p.z;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, Point<T> const& p) {
    return os << p.x << ' ' << p.y << ' ' << p.z;
}

template <typename T>
using Segment = std::pair<Point<T>, Point<T>>;

template <typename T>
using Polyline = std::vector<Point<T>>;

template <typename T>
std::ostream& operator<<(std::ostream& os, Polyline<T> const& polyline) {
    for (auto const& p: polyline) {
        os << p << '\n';
    }
    return os;
}

#endif // POLYLINE_H
