#include "amx/core/sceneManager.h"

namespace amx {
    SceneManager::SceneManager() {

    }

    void SceneManager::update(double deltaT) {
        if (_currentScene != nullptr) {
            _currentScene->update(deltaT);
        }
    }

    void SceneManager::draw() {
        if (_currentScene != nullptr) {
            _currentScene->draw();
        }
    }

    void SceneManager::dispose() {
        for (auto scene : _scenes) {
            scene.second->dispose();
        }
    }
}