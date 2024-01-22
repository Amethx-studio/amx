#include "logComponent.h"
#include <iostream>

namespace game {
    void LogComponent::update(double deltaT) {
        std::cout << deltaT << std::endl;
    }
}