#pragma once

#include "./geometry.h"
#include "./material.h"

namespace amx {
    struct Primitive {
        public:
            Geometry geometry;
            Material material;
    };
}