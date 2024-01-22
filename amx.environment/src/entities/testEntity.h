#pragma once

#include <amx/amx.h>

namespace game {
    class TestEntity : public amx::Entity {
        public:
            TestEntity();
            ~TestEntity() override {}
    };
}