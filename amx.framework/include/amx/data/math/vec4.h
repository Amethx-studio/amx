#pragma once

#include "vec.h"

namespace amx {
    /// @brief Base class defining a vector 4
    /// @tparam T Type of data to handle
    template <typename T>
    struct vec<4, T> {
        T x;
        T y;
        T z;
        T w;
        T& operator[](uint8_t index) {
            if (index == 0) return x;
            if (index == 1) return y;
            if (index == 2) return z;
            if (index == 3) return w;

            throw std::out_of_range("Index is out of range");
            return x; // Default, in case of out-of-bounds access
        }

        const T& operator[](uint8_t index) const {
            if (index == 0) return x;
            if (index == 1) return y;
            if (index == 2) return z;
            if (index == 3) return w;

            throw std::out_of_range("Index is out of range");
            return x; // Default, in case of out-of-bounds access
        }

        // Addition
        vec<4, T> operator+(const vec<4, T>& other) const {
            return {x + other.x, y + other.y, z + other.z, w + other.w};
        }

        // Subtraction
        vec<4, T> operator-(const vec<4, T>& other) const {
            return {x - other.x, y - other.y, z - other.z, w - other.w};
        }

        // Multiplication by scalar
        vec<4, T> operator*(const T& scalar) const {
            return {x * scalar, y * scalar, z * scalar, w * scalar};
        }

        // Multiplication by vec3
        vec<4, T> operator*(const vec<4, T>& other) const {
            return {x * other.x, y * other.y, z * other.z, w * other.w};
        }

        // Division by scalar
        vec<4, T> operator/(const T& scalar) const {
            if (scalar != 0) {
                return {x / scalar, y / scalar, z / scalar, w / scalar};
            } else {
                throw std::runtime_error("Division by zero");
            }
        }

        // Division by vec2
        vec<4, T> operator/(const vec<4, T>& other) const {
            if (other.x != 0 && other.y != 0, other.z != 0 && other.w != 0) {
                return {x / other.x, y / other.y, z / other.z, w / other.w};
            } else {
                throw std::runtime_error("Division by zero");
            }
        }
    };

    /// @brief Vector 4 of float
    typedef vec<4, float> vec4;
}