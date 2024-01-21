#pragma once

#include "../core.h"
#include "../pch.h"
#include "../core/component.h"
#include "../data/uuid.h"
#include "../interfaces/ITransform.h"

namespace amx {
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
            /// @brief Update function for the entity
            /// @param deltaT Time between each frame in seconds
            virtual void update(double deltaT) {}
            /// @brief Draw function for the entity
            virtual void draw() {}

        protected:
            /// @brief Id of the entity
            UUID _id;
            /// @brief Component map
            std::unordered_map<std::type_index, std::shared_ptr<Component>> _components;
    };
}