#pragma once

#include "../core.h"

namespace amx {
    class AMX_API Component {
        public:
            /// @brief Update function of the component
            /// @param deltaT Time between each frame
            virtual void update(double deltaT) = 0;
            /// @brief Draw function of the component
            virtual void draw() {}
            /// @brief Dispose function of the component
            virtual void dispose() {}
    };
}