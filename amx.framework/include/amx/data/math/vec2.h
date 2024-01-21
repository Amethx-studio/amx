#pragma once

#include "../../core.h"
#include "vec.h"

namespace amx {
    /// @brief Base class defining a vector 2
    /// @tparam T Type of data to handle
    template <typename T>
    struct AMX_API vec<2, T>  {
        T x;
        T y;
        T& operator[](uint8_t index) {
            if (index == 0) return x;
            if (index == 1) return y;

            throw std::out_of_range("Index is out of range");
            return x; // Default, in case of out-of-bounds access
        }
        const T& operator[](uint8_t index) const {
            if (index == 0) return x;
            if (index == 1) return y;

            throw std::out_of_range("Index is out of range");
            return x; // Default, in case of out-of-bounds access
        }

        // Addition
        vec<2, T> operator+(const vec<2, T>& other) const {
            return {x + other.x, y + other.y};
        }

        // Subtraction
        vec<2, T> operator-(const vec<2, T>& other) const {
            return {x - other.x, y - other.y};
        }

        // Multiplication by scalar
        vec<2, T> operator*(const T& scalar) const {
            return {x * scalar, y * scalar};
        }

        // Multiplication by vec2
        vec<2, T> operator*(const vec<2, T>& other) const {
            return {x * other.x, y * other.y};
        }

        // Division by scalar
        vec<2, T> operator/(const T& scalar) const {
            if (scalar != 0) {
                return {x / scalar, y / scalar};
            } else {
                throw std::runtime_error("Division by zero");
            }
        }

        // Division by vec2
        vec<2, T> operator/(const vec<2, T>& other) const {
            if (other.x != 0 && other.y != 0) {
                return {x / other.x, y / other.y};
            } else {
                throw std::runtime_error("Division by zero");
            }
        }
    };

    /// @brief Vector 2 of float
    typedef vec<2, float> vec2;
}