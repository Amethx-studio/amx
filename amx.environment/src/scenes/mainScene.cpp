#include "mainScene.h"

#include <iostream>
#include "../entities/testEntity.h"

namespace game {
    void MainScene::init() {
        std::cout << "Initializing the main scene" << std::endl;
        createEntity(0, 0, std::make_shared<TestEntity>());
    }
}