#include "amx/core/game.h"
#include "amx/pch.h"

#include "graphics/graphicsDevice.internal.h"
#include "graphics/renderer.internal.h"

namespace amx {

    class Game::Impl {
        public:
            friend class GraphicsDevice;
    };

    std::shared_ptr<Game> Game::_instance = nullptr;

    Game::Game() : _internal(std::make_unique<Impl>()) {
        _graphicsDevice = std::make_shared<GraphicsDevice>();
        _sceneManager = std::make_shared<SceneManager>();
        _renderer = std::make_shared<Renderer>();
    }

    bool Game::init(GameInitConfig config) {
        auto status = config.title != "" ? _graphicsDevice->_internal->init(config.title) : _graphicsDevice->_internal->init("AMX");
        if (status) {
            if (config.viewportW && config.viewportH) {
                _graphicsDevice->setViewport(config.viewportW, config.viewportH);
            }
        }

        registerScenes(config.scenes);

        return status;
    }

    void Game::registerScenes(std::vector<std::shared_ptr<Scene>> scenes) {
        for (auto scene : scenes) {
            _sceneManager->registerScene(scene);
        }
    }

    void Game::run() {
        auto previousTime = _graphicsDevice->_internal->getTime();
        while (!_graphicsDevice->_internal->shouldClose()) {
            auto currentTime = _graphicsDevice->_internal->getTime();
            _graphicsDevice->_internal->beginFrame();
            _renderer->_internal->begin();
            _sceneManager->update(currentTime - previousTime);
            _sceneManager->draw();
            _renderer->_internal->end();
            _graphicsDevice->_internal->endFrame();
            previousTime = currentTime;
        }
        terminate();
    }

    // Need to be kept to destroy the private implementation
    Game::~Game() {}

    void Game::terminate() {
        _graphicsDevice->_internal->dispose();
    }
}