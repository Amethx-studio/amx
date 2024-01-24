#pragma once

#include "../pch.h"
#include "../core.h"

namespace amx {

    class Game;
    class RendererInternal;

    class AMX_API Renderer {
        public:
            /// @brief Draw something to the screen
            void draw();
            /// @brief Friend class reference to the game
            friend class Game;

        private:
            /// @brief Internal implementation of the renderer class
            std::shared_ptr<RendererInternal> _internal;
    };
}