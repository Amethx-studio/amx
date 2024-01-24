#pragma once

#include "../pch.h"
#include "../core/game.h"
#include "../core/scene.h"
#include "../data/config/gameInitConfig.h"

using scene_list = std::vector<std::shared_ptr<amx::Scene>>;

namespace amx {
    inline std::shared_ptr<Game> createGameInstance(GameInitConfig config) {
        auto game = std::make_shared<Game>(config);

        return game;
    }
}