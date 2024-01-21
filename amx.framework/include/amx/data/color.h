#pragma once

#include "../core.h"
#include "../pch.h"

namespace amx {
    /// @brief Color object used by the engine
    struct AMX_API Color {
        double r() const { return _r / MAX_VALUE; }
        double g() const { return _g / MAX_VALUE; }
        double b() const { return _b / MAX_VALUE; }
        double a() const { return _a / MAX_VALUE; }

        /// @brief Default constructor of a color
        Color() {
            _r = 0;
            _g = 0;
            _b = 0;
            _a = 255;
        }

        /// @brief Constructor of a color which sets the alpha to 255
        /// @param r Red value
        /// @param g Green value
        /// @param b Blue value
        Color(uint8_t r, uint8_t g, uint8_t b) {
            _r = r;
            _g = g;
            _b = b;
        }

        /// @brief Constructor of a color
        /// @param r Red value
        /// @param g Green value
        /// @param b Blue value
        /// @param a Alpha value
        Color(uint8_t r, uint8_t g, uint8_t b, uint8_t a) {
            _r = r;
            _g = g;
            _b = b;
            _a = a;
        }

        private:
            /// @brief Max value the RGBA can have
            const double MAX_VALUE = 255;
            /// @brief Red value
            uint8_t _r;
            /// @brief Green value
            uint8_t _g;
            /// @brief Blue value
            uint8_t _b;
            /// @brief Alpha value
            uint8_t _a;
    };
}