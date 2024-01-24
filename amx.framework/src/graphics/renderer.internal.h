#pragma once

namespace amx {
    class RendererInternal {
        public:
            /// @brief Setup function for the renderer. Needs to be called before every frame.
            void begin();
            /// @brief End function for the renderer. This sends the data tot he GraphicsDevice
            /// @brief and draws to the screen.
            void end();
    };
}