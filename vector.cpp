#include "vector.h"

#include <cmath>

namespace projection {
Vector::Vector(Point b, Point e) : b{std::move(b)}, e{std::move(e)} {
    x_ = e.x - b.x;
    y_ = e.y - b.y;
    z_ = e.z - b.z;
}

double Vector::modulo() const {
    return std::hypot(x_, y_, z_);
}

Vector& Vector::operator *=(double n)
{
    Point p{b.x + (x() * n),
            b.y + (y() * n),
            b.z + (z() * n)};
    e = p;
    return *this;
}

double operator*(Vector a, Vector b) {
    return a.x() * b.x() + a.y() * b.y() + a.z() * b.z();
}

Vector operator*(double n, Vector v) {
    return v *= n;
}

Vector operator*(Vector v, double n) {
    return v *= n;
}

double cosAngle(Vector a, Vector b) {
    return (a * b) / (a.modulo() * b.modulo());
}
} // namespace projection
