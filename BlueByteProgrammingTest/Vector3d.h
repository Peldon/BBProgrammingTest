#pragma once

#include <string>

class Vector3d {
public:
    float x = 0;
    float y = 0;
    float z = 0;

    Vector3d() = default;
    Vector3d(float const x, float const y, float const z) : x(x), y(y), z(z) {}

    Vector3d operator + (const Vector3d &v) const;
    Vector3d operator - (const Vector3d &v) const;
    Vector3d operator * (float const scalar) const;
    Vector3d operator / (float const scalar) const;

    float magnitude() const;
    float magnitudeSquared() const;
    Vector3d normalize() const;
    float dot(const Vector3d &v) const;

    std::string toString(int precision = 1) const;
};
