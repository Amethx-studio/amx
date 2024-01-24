#include "scenes/mainScene.h"

#include <amx/amx.h>
#include <amx/pch.h>
#include <iostream>

int main() {

    std::vector<std::shared_ptr<amx::Scene>> scenes = {
        std::make_shared<game::MainScene>()
    };
    auto game = amx::createGameInstance("AMX", 1280, 720, scenes);
    game->run();

    return 0;
}
