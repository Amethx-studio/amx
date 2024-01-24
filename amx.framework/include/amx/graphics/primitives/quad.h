#pragma once

#include "../../core.h"
#include "../geometry.h"

namespace amx {
    struct AMX_API Quad : public Geometry {
        public:
            /// @brief Default constructor for a quad. Initializes the vertices and indices
            Quad();
    };
}