#pragma once
#pragma once
#include <iostream>
#include <cmath>

class Vector3
{
public:
    float x, y, z;

    Vector3();  // Constructor por defecto
    Vector3(float x, float y, float z); // Constructor con parámetros

    Vector3 operator+(const Vector3& v) const;
    Vector3 operator-(const Vector3& v) const;
    Vector3 operator*(const Vector3& v) const;
    Vector3 operator*(float scalar) const;
    Vector3 operator/(float scalar) const;

    float magnitude() const;
    Vector3 normalize() const;

    void print() const;

    Vector3 cross(const Vector3& v) const;
};


