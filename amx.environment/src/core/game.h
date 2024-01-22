#pragma once

#include <amx/amx.h>
#include <string>

namespace game {
    class Game : public amx::Game {
        public:
            Game() : amx::Game() {}
            void registerScenes() override;
    };
}