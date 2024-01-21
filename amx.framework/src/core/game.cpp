#include "amx/core/game.h"
#include "amx/pch.h"

#include "graphics/graphicsDeviceImplementation.h"

namespace amx {

     class Game::Impl {
        public:
            friend class GraphicsDevice;
    };

    Game::Game() : _internal(std::make_unique<Impl>()) {
        _graphicsDevice = std::make_shared<GraphicsDevice>();
        _sceneManager = std::make_shared<SceneManager>();
    }

    std::shared_ptr<GraphicsDevice> Game::graphicsDevice() { return _graphicsDevice; }

    bool Game::init(GameInitConfig config) {
        auto status = config.title != "" ? _graphicsDevice->_internal->init(config.title) : _graphicsDevice->_internal->init("AMX");
        if (status) {
            if (config.viewportW && config.viewportH) {
                _graphicsDevice->setViewport(config.viewportW, config.viewportH);
            }
        }

        return status;
    }

    void Game::run() {
        auto previousTime = _graphicsDevice->_internal->getTime();
        while (!_graphicsDevice->_internal->shouldClose()) {
            auto currentTime = _graphicsDevice->_internal->getTime();
            _graphicsDevice->_internal->beginFrame();
            _sceneManager->update(currentTime - previousTime);
            _sceneManager->draw();
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