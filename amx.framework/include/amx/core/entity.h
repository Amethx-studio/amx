#pragma once

#include "../core.h"
#include "../pch.h"
#include "../core/component.h"
#include "../data/uuid.h"
#include "../interfaces/ITransform.h"

namespace amx {

    class Scene;

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

            /// @brief Add a component to an entity
            /// @tparam T 
            /// @param component 
            template <typename T>
            void addComponent(T component) {
                static_assert(std::is_same<T, Component>::value, "T needs to be a component");
                auto key = typeid(T);
                auto it = _components.find(key);
                if (it == _components.end()) {
                    _components[key] = component;
                }
            }

            /// @brief Get a component from the entity
            /// @tparam T Type of the component to retrieve
            /// @return Component object
            template <typename T>
            std::shared_ptr<T> getComponent() {
                static_assert(std::is_same<T, Component>::value, "T needs to be a component");
                auto key = typeid(T);
                auto it = _components.find(key);
                if (it != _components.end()) {
                    return _components[key];
                }

                return nullptr;
            }

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
            /// @brief Id of the entity
            UUID _id;
            /// @brief Component map
            std::unordered_map<std::type_index, std::shared_ptr<Component>> _components;
    };
}