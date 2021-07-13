#ifndef VECTOR_H
#define VECTOR_H

#include "polyline.h"

namespace projection {
class Vector {
public:
    Vector(Point b, Point e);
    double x() const { return x_; }
    double y() const { return y_; }
    double z() const { return z_; }
    double modulo() const;
    Vector& operator*=(double n);

    Point b;
    Point e;

protected:
    double x_;
    double y_;
    double z_;
};
double operator*(Vector a, Vector b);
Vector operator*(double n, Vector v);
Vector operator*(Vector v, double n);
double cosAngle(Vector a, Vector b);
} // namespace projection

#endif // VECTOR_H
