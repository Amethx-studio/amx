#pragma once

#include "../core.h"
#include "../pch.h"

namespace amx {
    class AMX_API UUID {
        public:
            static const std::string EMPTY;

            UUID() {
                generate();
            }

            std::string toString() const {
                std::stringstream ss;
                ss << std::hex << std::setfill('0')
                << std::setw(8) << rnd1 << "-"
                << std::setw(4) << (rnd2 >> 16) << "-"
                << std::setw(4) << ((rnd2 & 0xFFFF) | 0x4000) << "-"
                << std::setw(4) << ((rnd3 >> 16) | 0x8000) << "-"
                << std::setw(8) << (rnd3 & 0xFFFF) << std::setw(8) << rnd4;

                return ss.str();
            }

        private:
            uint32_t getRandomInt() const {
                std::random_device rd;
                std::mt19937 gen(rd());
                std::uniform_int_distribution<uint32_t> dis(0, UINT32_MAX);
                return dis(gen);
            }

            void generate() {
                rnd1 = getRandomInt();
                rnd2 = getRandomInt();
                rnd3 = getRandomInt();
                rnd4 = getRandomInt();
            }

            uint32_t rnd1, rnd2, rnd3, rnd4;
    };
}
