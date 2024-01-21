#pragma once

#include "amx/pch.h"
#include "amx/core/game.h"

namespace amx {
    class GraphicsDeviceImplementation {
        public:
            /// @brief Init function of the GraphicsDevice. This communicates with the
            /// @brief platform specific API and makes sure every thing is fine
            /// @return Success status of the initialization
            virtual bool init(std::string title) = 0;
            /// @brief Tells whether the app should close.
            /// @return Whether the application should close or not
            virtual bool shouldClose() = 0;
            /// @brief Called before every frame to initialize the draw call.
            virtual void beginFrame() = 0;
            /// @brief Called at the end of the frame to swap buffers and poll events.
            virtual void endFrame() = 0;
            /// @brief Dipose of the API data and close the app.
            virtual void dispose() = 0;
            /// @brief Platform specific implementation of setting the viewport
            /// @param width Width of the viewport
            /// @param height Height of the viewport
            virtual void setViewport(int width, int height) = 0;
            friend class Game;
    };
}