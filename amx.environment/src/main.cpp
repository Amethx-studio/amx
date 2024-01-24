#include "scenes/mainScene.h"

#include <amx/amx.h>
#include <amx/pch.h>
#include <iostream>

int main() {

    std::vector<std::shared_ptr<amx::Scene>> scenes = {
        std::make_shared<game::MainScene>()
    };

    amx::GameInitConfig config = amx::GameInitConfig({
        .title = "AMX",
        .viewportW = 1280,
        .viewportH = 720,
        .scenes = scenes
    });

    auto game = core::createInstance(config);
    game->run();

    return 0;
}
