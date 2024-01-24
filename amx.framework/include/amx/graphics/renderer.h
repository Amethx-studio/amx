#pragma once

#include "../pch.h"

namespace amx {

    class Game;
    class RendererInternal;

    class Renderer {
        public:
            void draw();
            friend class Game;

        private:
            /// @brief Internal implementation of the renderer class
            std::shared_ptr<RendererInternal> _internal;
    };
}