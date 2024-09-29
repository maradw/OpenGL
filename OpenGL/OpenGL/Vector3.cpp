#include "Vector3.h"

// Constructor por defecto
Vector3::Vector3() : x(0), y(0), z(0) {}

// Constructor con par�metros
Vector3::Vector3(float x, float y, float z) : x(x), y(y), z(z) {}

// Sobrecarga del operador +
Vector3 Vector3::operator+(const Vector3& v) const {
    return Vector3(x + v.x, y + v.y, z + v.z);
}

// Sobrecarga del operador -
Vector3 Vector3::operator-(const Vector3& v) const {
    return Vector3(x - v.x, y - v.y, z - v.z);
}

// Sobrecarga del operador * (Producto entre vectores)
Vector3 Vector3::operator*(const Vector3& v) const {
    return Vector3(x * v.x, y * v.y, z * v.z);
}

// Sobrecarga del operador * para multiplicaci�n por un escalar
Vector3 Vector3::operator*(float scalar) const {
    return Vector3(x * scalar, y * scalar, z * scalar);
}

// Sobrecarga del operador / para dividir por un escalar
Vector3 Vector3::operator/(float scalar) const {
    return Vector3(x / scalar, y / scalar, z / scalar);
}

// Funci�n para calcular la magnitud del vector
float Vector3::magnitude() const {
    return std::sqrt(x * x + y * y + z * z);
}

// Funci�n para normalizar el vector
Vector3 Vector3::normalize() const {
    float mag = magnitude();
    if (mag > 0) {
        return Vector3(x / mag, y / mag, z / mag);
    }
    return Vector3(0, 0, 0); // Devuelve un vector nulo si la magnitud es 0
}

// Imprimir el vector
void Vector3::print() const {
    std::cout << "Vector3(" << x << ", " << y << ", " << z << ")" << std::endl;
}

// Funci�n para calcular el producto cruzado entre dos vectores
Vector3 Vector3::cross(const Vector3& v) const {
    return Vector3(
        y * v.z - z * v.y,
        z * v.x - x * v.z,
        x * v.y - y * v.x
    );
}
