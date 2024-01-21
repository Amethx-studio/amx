#pragma once

#include "../../core.h"
#include "../../pch.h"

namespace amx {
    /// @brief Game initialization config
    struct GameInitConfig {
        /// @brief Title for the game
        std::string title;
        /// @brief Initial viewport width of the game
        int viewportW;
        /// @brief Initial viewport height of the game
        int viewportH;
    };
}