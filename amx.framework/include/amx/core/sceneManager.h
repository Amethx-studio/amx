#pragma once

#include "../core.h"
#include "../pch.h"
#include "../core/scene.h"

namespace amx {
    class AMX_API SceneManager {
        public:
            /// @brief Default constructor for the scene manager
            SceneManager();
            /// @brief Dispose function for the scene manager
            void dispose();

        private:
            /// @brief Map of the different scenes available for the game
            std::unordered_map <std::type_index, std::shared_ptr<Scene>> _scenes;
    };
}