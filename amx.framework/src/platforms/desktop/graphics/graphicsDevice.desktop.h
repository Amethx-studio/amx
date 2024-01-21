#pragma once

#include "graphics/graphicsDeviceImplementation.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace amx {
    /// @brief Desktop specific implementation of the GraphicsDevice
    class DesktopGraphicsDevice : public GraphicsDeviceImplementation {
        public:
            /// @brief Destructor of the Desktop GraphicsDevice
            ~DesktopGraphicsDevice();
            /// @brief Dipose of the API data and close the app.
            void dispose() override;
            /// @brief Init function of the GraphicsDevice. This communicates with the
            /// @brief platform specific API and makes sure every thing is fine
            /// @return Success status of the initialization
            bool init(std::string title) override;
            /// @brief Tells whether the app should close.
            /// @return Whether the application should close or not
            bool shouldClose() override;
            /// @brief Called before every frame to initialize the draw call.
            void beginFrame() override;
            /// @brief Called at the end of the frame to swap buffers and poll events.
            void endFrame() override;
            /// @brief Set the viewport of the context on desktop
            /// @param width Width of the viewport
            /// @param height Height of the viewport
            void setViewport(int width, int height) override;
            /// @brief Get the time between each frame
            double getTime() override;

        private:
            /// @brief Center the window in the monitor
            /// @return Success status
            bool centerWindow();
            /// @brief Reference to the window object provided by GLFW
            GLFWwindow *window;
    };
}