#pragma once

#include "./geometry.h"
#include "./material.h"

namespace amx {
    struct Mesh {
        public:
            Geometry geometry;
            Material material;
    };
}