#pragma once

#include "../core.h"
#include "../pch.h"
#include "../core/entity.h"
#include "../data/uuid.h"

namespace amx {
    /// @brief Scene object in the AMX framework. This class handles the lifecycle
    /// @brief of its entities.
    class AMX_API Scene {
        public:
            virtual void init() = 0;
            void dispose();
            /// @brief Update function for the project
            /// @param detlaT Time between frames in seconds
            void update(double detlaT);
            /// @brief Draw function for the project
            void draw();
            /// @brief Adds an entity to the list of entities that will be created next frame
            /// @param x X coordinated at creation
            /// @param y Y coordinate at creation
            /// @param entity Entitity that will be created
            void createEntity(int x, int y, std::shared_ptr<Entity> entity);
            /// @brief Adds an entity to list of entities that will be deleted next frame
            /// @param id ID of the entity
            void deleteEntity(UUID id);

        private:
            void mergeEntities();
            /// @brief List of the entities that will be created next frame
            std::vector<std::shared_ptr<Entity>> toCreateEntities;
            /// @brief List of the entities that will be deleted next frame
            std::vector<std::string> toDeleteEntities;
            /// @brief Map of the different entities loaded in the scene
            std::unordered_map<std::string, std::shared_ptr<Entity>> _entities; 
    };
}