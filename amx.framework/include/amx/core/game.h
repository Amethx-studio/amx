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
            Game(GameInitConfig config);
            /// @brief Destructor for the game object
            ~Game();
            /// @brief Starts the game loop
            void run();
            /// @brief Terminate function of the game
            void terminate();
            /// @brief Get a reference to the game's GraphicsDevice
            /// @return GraphicsDevice object used by the project
            std::shared_ptr<GraphicsDevice> graphicsDevice();

        protected:

        private:
            /// @brief Initialize the game object and its dependencies
            /// @param config Config object of for the game
            bool init(GameInitConfig config);
            /// @brief Callback to register the different scenes;
            /// @param scenes List of scenes for the game
            void registerScenes(std::vector<std::shared_ptr<Scene>> scenes);
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