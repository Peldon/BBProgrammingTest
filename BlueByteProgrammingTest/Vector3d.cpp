#include "Vector3d.h"

#include <cmath> // magnitude() sqrt
#include <sstream> // toString()
#include <iomanip> // toString() setprecision


Vector3d Vector3d::operator + (const Vector3d &v) const {
    return Vector3d(
        x + v.x,
        y + v.y,
        z + v.z
    );
}

Vector3d Vector3d::operator - (const Vector3d &v) const {
    return Vector3d(
        x - v.x,
        y - v.y,
        z - v.z
    );
}

Vector3d Vector3d::operator * (float const scalar) const {
    return Vector3d(
        x * scalar,
        y * scalar,
        z * scalar
    );
}

Vector3d Vector3d::operator / (float const scalar) const {
    return Vector3d(
        x / scalar,
        y / scalar,
        z / scalar
    );
}

float Vector3d::magnitude() const {
    return sqrt(magnitudeSquared());
}

float Vector3d::magnitudeSquared() const {
    return
        x * x +
        y * y +
        z * z
        ;
}

Vector3d Vector3d::normalize() const {
    float m = magnitude();
    return Vector3d(
        x / m,
        y / m,
        z / m
    );
}

float Vector3d::dot(const Vector3d &v) const {
    return
        x * v.x +
        y * v.y +
        z * v.z;
}

std::string Vector3d::toString(int precision) const {
    std::stringstream ss;
    ss << std::fixed << std::setprecision(precision);
    ss << "(" << x << ", " << y << ", " << z << ")";
    return ss.str();
}

