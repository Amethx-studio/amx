#include "core/game.h"
#include <iostream>

int main() {
    auto game = new TestEnv::Game();
    if (game->init({.title="AMX", .viewportW=1280, .viewportH=720})) {
        game->run();
    }

    delete game;

    return 0;
}
