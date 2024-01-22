#include "amx/core/entity.h"

namespace amx {
    void Entity::update(double deltaT) {
        for (auto component : _components) {
            component.second->update(deltaT);
        }
    }

    void Entity::draw() {
        for (auto component : _components) {
            component.second->draw();
        }
    }

    void Entity::dispose() {
        for (auto component : _components) {
            component.second->dispose();
        }
    }
}