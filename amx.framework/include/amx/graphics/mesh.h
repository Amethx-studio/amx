#pragma once

#include "../core.h"
#include "./geometry.h"
#include "./material.h"

namespace amx {
    struct AMX_API Mesh {
        public:
            Geometry geometry;
            Material material;
    };
}