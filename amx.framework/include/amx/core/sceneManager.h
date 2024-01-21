#pragma once

#include "../core.h"
#include "../pch.h"
#include "./scene.h"
#include "./game.h"

namespace amx {
    class AMX_API SceneManager {
        public:
            /// @brief Default constructor for the scene manager
            SceneManager();
            /// @brief Dispose function for the scene manager
            void dispose();

            // Friend class of the Game
            friend Game;

        private:
            /// @brief Update function for the current scene
            /// @param deltaT Time between each frame
            void update(double deltaT);
            /// @brief Draw function for the current scene
            void draw();
            /// @brief Current scene used by the scene manager
            std::shared_ptr<Scene> _currentScene;
            /// @brief Map of the different scenes available for the game
            std::unordered_map <std::type_index, std::shared_ptr<Scene>> _scenes;
    };
}