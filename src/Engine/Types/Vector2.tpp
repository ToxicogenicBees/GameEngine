/*
    Vector2.tpp

    Template implementation for vector classes
*/

#include "Types/Vector2.hpp"

template <typename T>
Vector2_<T>::Vector2_(T x, T y) {
    this->x = x;
    this->y = y;
}

template <typename T>
Vector2_<T>::Vector2_(const Vector2_<T>& vector) {
    x = vector.x;
    y = vector.y;
}

template <typename T>
Vector2_<T>& Vector2_<T>::operator=(const Vector2_<T>& vector) {
    x = vector.x;
    y = vector.y;

    return *this;
}

template <typename T>
Vector2_<T> Vector2_<T>::operator+(const Vector2_<T>& vector) const {
    return Vector2_<T>(x + vector.x, y + vector.y);
}

template <typename T>
void Vector2_<T>::operator+=(const Vector2_<T>& vector) {
    x += vector.x;
    y += vector.y;
}

template <typename T>
Vector2_<T> Vector2_<T>::operator-(const Vector2_<T>& vector) const {
    return Vector2_(x - vector.x, y - vector.y);
}

template <typename T>
void Vector2_<T>::operator-=(const Vector2_<T>& vector) {
    x -= vector.x;
    y -= vector.y;
}

template <typename T>
Vector2_<T> Vector2_<T>::operator-() const {
    return Vector2_(-x, -y);
}

template <typename T>
Vector2_<T> Vector2_<T>::operator*(const Vector2_& vector) const {
    return Vector2_(x * vector.x, y * vector.y);
}

template <typename T>
Vector2_<T> operator*(T s, const Vector2_<T>& vector) {
    return vector * s;
}

template <typename T>
Vector2_<T> Vector2_<T>::operator*(T s) const {
    return Vector2_(x * s, y * s);
}

template <typename T>
void Vector2_<T>::operator*=(const Vector2_& vector) {
    x *= vector.x;
    y *= vector.y;
}

template <typename T>
void Vector2_<T>::operator*=(T s) {
    x *= s;
    y *= s;
}

template <typename T>
Vector2_<T> Vector2_<T>::operator/(const Vector2_& vector) const {
    return Vector2_(x / vector.x, y / vector.y);
}

template <typename T>
Vector2_<T> operator/(T s, const Vector2_<T>& vector) {
    return vector / s;
}

template <typename T>
Vector2_<T> Vector2_<T>::operator/(T s) const {
    return Vector2_(x / s, y / s);
}

template <typename T>
void Vector2_<T>::operator/=(const Vector2_& vector) {
    x /= vector.x;
    y /= vector.y;
}

template <typename T>
void Vector2_<T>::operator/=(T s) {
    x /= s;
    y /= s;
}

template <typename T>
T Vector2_<T>::dot(const Vector2_<T>& vector) const {
    return (x * vector.x) + (y * vector.y);
}

template <typename T>
Vector2_<T> Vector2_<T>::normal() const {
    double mag = magnitude();
    return (mag > 1e-8 ? (*this / mag) : Vector2_::zero());
}

template <typename T>
T Vector2_<T>::squaredMagnitude() const {
    return dot(*this);
}

template <typename T>
T Vector2_<T>::magnitude() const {
    return std::sqrt(squaredMagnitude());
}

template <typename T>
T Vector2_<T>::scalarProjection(const Vector2_<T> v) const {
    return dot(v.normal());
}

template <typename T>
Vector2_<T> Vector2_<T>::projection(const Vector2_<T> v) const {
    return scalarProjection(v) * v.normal();
}

template <typename T>
T Vector2_<T>::angle(const Vector2_<T> v) const {
    return std::acos(dot(v) / magnitude() / v.magnitude());
}

template <typename T>
std::ostream& operator<<(std::ostream& o, const Vector2_<T>& vector) {
    o << "(" << vector.x << ", " << vector.y << ")";
    return o;
}
