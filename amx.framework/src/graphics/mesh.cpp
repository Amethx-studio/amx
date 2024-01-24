#include "amx/graphics/mesh.h"

#include "amx/graphics/primitives/quad.h"

namespace amx {
    Mesh Mesh::createSprite() {
        Quad geo;
        return Mesh({geo});
    }
}