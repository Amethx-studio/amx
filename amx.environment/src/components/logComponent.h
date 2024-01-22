#pragma once

#include <amx/amx.h>

namespace game {
    class LogComponent : public amx::Component {
        public:
            void update(double deltaT) override;
    };
}