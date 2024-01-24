#include "amx/graphics/primitives/quad.h"

namespace amx {
    Quad::Quad() {
        vertices = {
            -0.5f, 0.5f, 0,
            -0.5f, -0.5f, 0,
            0.5f, -0.5f, 0,
            0.5f, 0.5f, 0
        };

        indices = {
            0, 1, 3,
            3, 1, 2
        };
    }
}