#pragma once

#include "../../core.h"
#include "vec.h"

namespace amx {
    /// @brief Base class defining a vector 3
    /// @tparam T Type of data to handle
    template <typename T>
    struct AMX_API vec<3, T> {
        T x;
        T y;
        T z;
        T& operator[](uint8_t index) {
            if (index == 0) return x;
            if (index == 1) return y;
            if (index == 2) return z;

            throw std::out_of_range("Index is out of range");
            return 0; // Default, in case of out-of-bounds access
        }

        const T& operator[](uint8_t index) const {
            if (index == 0) return x;
            if (index == 1) return y;
            if (index == 2) return z;

            throw std::out_of_range("Index is out of range");
            return x; // Default, in case of out-of-bounds access
        }

        // Addition
        vec<3, T> operator+(const vec<3, T>& other) const {
            return {x + other.x, y + other.y, z + other.z};
        }

        // Subtraction
        vec<3, T> operator-(const vec<3, T>& other) const {
            return {x - other.x, y - other.y, z - other.z};
        }

        // Multiplication by scalar
        vec<3, T> operator*(const T& scalar) const {
            return {x * scalar, y * scalar, z * scalar};
        }

        // Multiplication by vec3
        vec<3, T> operator*(const vec<3, T>& other) const {
            return {x * other.x, y * other.y, z * other.z};
        }

        // Division by scalar
        vec<3, T> operator/(const T& scalar) const {
            if (scalar != 0) {
                return {x / scalar, y / scalar, z / scalar};
            } else {
                throw std::runtime_error("Division by zero");
            }
        }

        // Division by vec2
        vec<3, T> operator/(const vec<3, T>& other) const {
            if (other.x != 0 && other.y != 0, other.z != 0) {
                return {x / other.x, y / other.y, z / other.z};
            } else {
                throw std::runtime_error("Division by zero");
            }
        }
    };

    /// @brief Vector 3 of float
    typedef vec<3, float> vec3;
}