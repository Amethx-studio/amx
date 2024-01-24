#pragma once

#include <amx/amx.h>

namespace game {
    class LogComponent : public amx::Component {
        public:
            LogComponent();
            void update(double deltaT) override;
            void draw() override;

        private:
            amx::Mesh _primitive;
    };
}