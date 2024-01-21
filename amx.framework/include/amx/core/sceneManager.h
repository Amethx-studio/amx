#pragma once

#include "../core.h"
#include "../pch.h"
#include "./scene.h"

namespace amx {

    class Game;

    /// @brief Class handling the different scenes of the game.
    class AMX_API SceneManager {
        public:
            /// @brief Default constructor for the scene manager
            SceneManager();
            /// @brief Dispose function for the scene manager
            void dispose();

            /// @brief Register a scene to the scene manager
            /// @tparam T Type of scene to register. Only one scene of a type can be registered
            /// @param scene Scene to register
            template <typename T>
            void registerScene(T scene) {
                static_assert(std::is_same<T, Scene>::value, "T needs to be of type Scene");
                auto key = typeid(T);
                auto it = _scenes.find(key);
                if (it == _scenes.end()) {
                    _scenes[key] = scene;
                    if (_currentScene == nullptr)
                        setScene(scene);
                }
            }
            
            /// @brief Set the scene of the scene manager
            /// @tparam T Scene to set
            /// @param scene Scene object
            template <typename T>
            void setScene(T scene) {
                static_assert(std::is_same<T, Scene>::value, "T needs to be of type Scene");
                auto key = typeid(T);
                auto it = _scenes.find(key);
                if (it != _scenes.end()) {
                    _currentScene = _scenes[key];
                }
            }

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