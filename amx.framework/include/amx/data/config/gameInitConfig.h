#pragma once

#include "../../core.h"
#include "../../pch.h"
#include "../../core/scene.h"

using scene_list = std::vector<std::shared_ptr<amx::Scene>>;

namespace amx {
    /// @brief Game initialization config
    struct GameInitConfig {
        /// @brief Title for the game
        std::string title;
        /// @brief Initial viewport width of the game
        int viewportW;
        /// @brief Initial viewport height of the game
        int viewportH;
        /// @brief List of scenes that the game need to suppoort
        scene_list scenes;
    };
}