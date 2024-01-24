#include "logComponent.h"
#include <iostream>

namespace game {

    LogComponent::LogComponent() {
        _primitive = amx::Mesh({amx::Geometry(), amx::Material()});
    }

    void LogComponent::update(double deltaT) {
    }

    void LogComponent::draw() {
        amx::Game::get()->renderer()->draw(0, 0, _primitive);
    }

}