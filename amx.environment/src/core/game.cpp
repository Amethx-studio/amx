#include "game.h"
#include "../scenes/mainScene.h"

namespace game {
    void Game::registerScenes() {
        _sceneManager->registerScene<MainScene>(std::make_shared<MainScene>());
    }
}