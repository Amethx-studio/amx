#pragma once

#include <amx/amx.h>
#include <string>

namespace TestEnv {
    class Game : public amx::Game {
        public:
            Game() : amx::Game() {}
            ~Game();
    };
}