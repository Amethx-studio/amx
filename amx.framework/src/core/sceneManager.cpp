#include "amx/core/sceneManager.h"

namespace amx {
    SceneManager::SceneManager() {

    }

    void SceneManager::dispose() {
        for (auto scene : _scenes) {
            scene.second->dispose();
        }
    }
}