#pragma once

#include "../pch.h"
#include "../core.h"
#include "math/vec.h"
#include "math/vec2.h"
#include "math/vec3.h"
#include "math/vec4.h"

#ifndef AMX_MATH
    /// Pi value
    #define PI 3.14159265358979323846
#endif

namespace amx {
    
    /// @brief Get the length of the vector
    /// @tparam T Type of data to handle
    /// @tparam N Length of the vector
    /// @param v Vector to get the length of
    /// @return Length of the vector in float
    template <uint8_t N, typename T>
    inline float vLen(const vec<N, T>& v) {
        static_assert(std::is_same<T, float>::value || std::is_same<T, int>::value || std::is_same<T, double>::value, "T needs to be of type float, int or double");
        float result = 0;
        for (uint8_t i = 0; i < N; i++) {
            result += std::pow(v[i], 2);
        }

        return std::sqrt(result);
    }

    /// @brief Get the direction from one point to another
    /// @tparam T Type of data to handle
    /// @tparam N Length of the vector
    /// @param from Initial position
    /// @param to Targeted position
    /// @return Direction from the initial position to the targeted position
    template <uint8_t N, typename T>
    inline vec<N, T> direction(const vec<N, T>& from, const vec<N, T>& to) {
        static_assert(std::is_same<T, float>::value || std::is_same<T, int>::value || std::is_same<T, double>::value, "T needs to be of type float, int or double");
        vec<N, T> retV;
        for (int i = 0; i < N; i++) {
            retV[i] = to[i] - from[i];
        }

        return retV;
    }

    /// @brief Dot product of two vectors
    /// @tparam T Type of data to handle
    /// @tparam N Length of the vector
    /// @param v1 First vector
    /// @param v2 Second vector
    /// @return Dot product of the two vectors
    template <uint8_t N, typename T>
    inline float dot(const vec<N, T>& v1, const vec<N, T>& v2) {
        static_assert(std::is_same<T, float>::value || std::is_same<T, int>::value || std::is_same<T, double>::value, "T needs to be of type float, int or double");
        float result = 0;
        for (uint8_t i = 0; i < N; i++) {
            result += v1[i] * v2[i];
        }

        return result;
    }

    /// @brief Cross product of two vec3
    /// @tparam T Type of data to handle
    /// @param v1 First vector
    /// @param v2 Second vector
    /// @return Cross product of the two vectors
    template <typename T>
    inline vec3 cross(const vec3&v1, const vec3& v2) {
        static_assert(std::is_same<T, float>::value || std::is_same<T, int>::value || std::is_same<T, double>::value, "T needs to be of type float, int or double");
        vec3 retV;
        retV[0] = v1.y * v2.z - v1.z * v2.y;
        retV[1] = v1.z * v2.x - v1.x * v2.z;
        retV[2] = v1.x * v2.y - v1.y * v2.x;

        return retV;
    }

    /// @brief Normalize a vector
    /// @tparam T Type of data to handle
    /// @tparam N Length of the vector
    /// @param v Vector to normalize
    /// @return Normalized vector
    template <uint8_t N, typename T>
    inline vec<N, T> normalize(const vec<N, T>& v) {
        static_assert(std::is_same<T, float>::value || std::is_same<T, int>::value || std::is_same<T, double>::value, "T needs to be of type float, int or double");
        vec<N, T> retV;
        auto len = vLen(v);
        for (int i = 0; i < N; i++) {
            retV[i] = v[i] / len;
        }

        return retV;
    }

    /// @brief Angle between two vectors
    /// @tparam T Type of data to handle
    /// @tparam N Length of the vector
    /// @param v1 First vector
    /// @param v2 Second vector
    /// @return Angle between the two vectors in radians
    template <uint8_t N, typename T>
    float angle(const vec<N, T>& v1, const vec<N, T>& v2) {
        float dotProd = dot(v1, v2);
        float mag1 = magnitude(v1);
        float mag2 = magnitude(v2);
        float cosAngle = dotProd / (mag1 * mag2);
        return std::acos(cosAngle);
    }

    /// @brief Creates a reflection vector given a vector and a normal
    /// @tparam T Type of data to handle
    /// @tparam N Length of the vector
    /// @param v Source vector
    /// @param normal Normal vector
    /// @return Reflected vector
    template <uint8_t N, typename T>
    inline vec<N, T> reflect(const vec<N, T>& v, const vec<N, T>& normal) {
        static_assert(std::is_same<T, float>::value || std::is_same<T, int>::value || std::is_same<T, double>::value, "T needs to be of type float, int or double");
        vec<N, T> retV;
        float val = 2.0f * dotProd(v, normal);
        for (int i = 0; i < N; i++) {
            retV[i] = v[i] - (normal[i] * val);
        }

        return retV;
    }

    /// @brief Magnitude of two vectors
    /// @tparam T Type of data to handle
    /// @tparam N Length of the vector
    /// @param v1 First vector
    /// @param v2 Second vector
    /// @return Magnitude of the vectors
    template <uint8_t N, typename T>
    inline float magnitude(const vec<N, T>& v1, const vec<N, T>& v2) {
        static_assert(std::is_same<T, float>::value || std::is_same<T, int>::value || std::is_same<T, double>::value, "T needs to be of type float, int or double");
        return std::sqrt(dotProd(v1, v2));
    }

    /// @brief Convert degrees to radiants
    /// @param degrees Angle in degrees
    /// @return Angle in radians
    inline float degToRad(float degrees) {
        return degrees * (PI / 180.0f);
    }

    /// @brief Convert radians to degrees
    /// @param rad Angle in radians
    /// @return Angle in degrees
    inline float radToDeg(float rad) {
        return rad * (180 / PI);
    }
}
