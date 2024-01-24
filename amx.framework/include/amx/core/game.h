#pragma once

#include "../core.h"
#include "../pch.h"
#include "./sceneManager.h"
#include "../graphics/graphicsDevice.h"
#include "../data/config/gameInitConfig.h"

namespace amx {
    class AMX_API Game {
        public:
            /// @brief Constructor for the game object
            Game();
            /// @brief Destructor for the game object
            ~Game();
            /// @brief Singleton should not be clonable
            Game(Game &other) = delete;
            /// @brief Cannot assign the instance
            void operator=(const Game &) = delete;
            /// @brief Starts the game loop
            void run();

            /// @brief Create an instance of a game
            /// @param config Initialization config for the game
            /// @return Newly created instance of the game
            static std::shared_ptr<Game> createInstance(GameInitConfig config) {
                if (!_instance) {
                    _instance = std::make_shared<Game>();
                    _instance->init(config);
                }

                return _instance;
            }

            /// @brief Get the current instance of the game
            /// @return Reference to the instance of the game
            static std::shared_ptr<Game> get() {
                return _instance;
            }

            /// @brief Getter for the SceneManager
            std::shared_ptr<SceneManager> sceneManager() const {
                return _sceneManager;
            }

            /// @brief getter for the GraphicsDevice
            std::shared_ptr<GraphicsDevice> graphicsDevice() const {
                return _graphicsDevice;
            }

        private:
            /// @brief Instance reference to the game object;
            static std::shared_ptr<Game> _instance;
            /// @brief Initialize the game object and its dependencies
            /// @param config Config object of for the game
            bool init(GameInitConfig config);
            /// @brief Callback to register the different scenes;
            /// @param scenes List of scenes for the game
            void registerScenes(std::vector<std::shared_ptr<Scene>> scenes);
            /// @brief Terminate function of the game
            void terminate();
            /// @brief Internal implementation of the Game class
            class Impl;
            /// @brief Reference to the internal implementation
            std::unique_ptr<Impl> _internal;
            /// @brief Game title
            std::string _title;
            /// @brief Reference to the scene manager
            std::shared_ptr<SceneManager> _sceneManager;
            /// @brief Reference to the graphics device
            std::shared_ptr<GraphicsDevice> _graphicsDevice;
    };
}