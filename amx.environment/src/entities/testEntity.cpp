#include "testEntity.h"

#include "../components/logComponent.h"

namespace game {
    TestEntity::TestEntity() {
        addComponent(std::make_shared<LogComponent>());
    }
}