#pragma once

#include "../core.h"
#include "../pch.h"

namespace amx {
    class Game;
    class GraphicsDeviceInternal;

    /// @brief Class representing the different graphics device and their respective API
    class AMX_API GraphicsDevice {
        public:
            /// @brief Default constructor of the GraphicsDevice
            GraphicsDevice();
            /// @brief Destructor of the GraphicsDevice
            ~GraphicsDevice();
             /// @brief Set the viewport of the context
            /// @param width Width of the viewport
            /// @param height Height of the viewport
            void setViewport(int width, int height);
            friend class Game;

        private:
            /// @brief Internal platform specific implementation of the GraphicsDevice class.
            std::unique_ptr<GraphicsDeviceInternal> _internal;
    };
}