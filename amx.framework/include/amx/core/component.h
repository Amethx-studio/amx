#pragma once

#include "../core.h"

namespace amx {
    class AMX_API Component {
        public:
            virtual void update(double deltaT) = 0;
            virtual void draw() = 0;
    };
}