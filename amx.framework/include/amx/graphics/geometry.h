#pragma once

#include "../core.h"
#include "../pch.h"

namespace amx {
    struct AMX_API Geometry {
        std::vector<float> vertices;
        std::vector<int> indices;
    };
}