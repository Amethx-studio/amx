#pragma once

#include "../core.h"
#include "./geometry.h"
#include "./material.h"

namespace amx {
    struct AMX_API Mesh {
        public:
            /// @brief Create a sprite mesh
            /// @return Sprite mesh
            static Mesh createSprite();
            Geometry geometry;
            Material material;
    };
}