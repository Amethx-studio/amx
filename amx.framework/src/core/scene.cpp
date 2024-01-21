#include "amx/core/scene.h"

namespace amx {

    void Scene::dispose() {
        for (auto it : _entities) {
            it.second->dispose();
        }
    }

    void Scene::update(double deltaT) {
        for (auto entity : _entities) {
            entity.second->update(deltaT);
        }
        mergeEntities();
    }

    void Scene::draw() {
        for (auto entity : _entities) {
            entity.second->draw();
        }
    }

    void Scene::createEntity(int x, int y, std::shared_ptr<Entity> entity) {
        entity->setPosition(x, y);
        toCreateEntities.push_back(entity);
    }

    void Scene::deleteEntity(UUID id) {
        toDeleteEntities.push_back(id.toString());
    }

    void Scene::mergeEntities() {
        // Create new entites
        for (auto entity : toCreateEntities) {
            _entities[entity->id()] = entity;
        }
        // Delete entities
        for (auto entityId : toDeleteEntities) {
            auto it = _entities.find(entityId);
            if (it != _entities.end()) {
                _entities.erase(entityId);
            }
        }
    }
}