#pragma once

#include "../core.h"
#include "../pch.h"
#include "../core/component.h"
#include "../data/uuid.h"
#include "../interfaces/ITransform.h"
#include "./scene.h"

namespace amx {

    class EntityImplementation;

    /// @brief Class representing an entity within the game. An entity is a game object
    /// @brief which has positional values and is componsed of different components.
    class AMX_API Entity : public ITransform {
        public:
            /// @brief Default constructor for the Entity class
            Entity();
            /// @brief Destructor for the Entity class
            ~Entity();
            /// @brief Gets the ID of the entity
            /// @return ID of the entity
            std::string id() const {
                return _id.toString();
            }
            /// @brief Dispose of the entity and its references
            void dispose();

            // Friend class of the scene manager. This is added so it can
            // call the update draw function.
            friend Scene;

        private:
            /// @brief Update function for the entity
            /// @param deltaT Time between each frame in seconds
            void update(double deltaT);
            /// @brief Draw function for the entity
            void draw();

        protected:
            /// @brief Internal implementation of the entities
            std::unique_ptr<EntityImplementation> _internal;
            /// @brief Id of the entity
            UUID _id;
            /// @brief Component map
            std::unordered_map<std::type_index, std::shared_ptr<Component>> _components;
    };
}