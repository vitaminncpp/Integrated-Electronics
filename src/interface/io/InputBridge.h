#pragma once

#include "Event.h"

namespace interface {
    namespace io {
        class InputBridge {
        public:
            inline InputBridge() {}

            inline virtual ~InputBridge() {}

        public:
            virtual void SendEvent(const Event &event) = 0;
        };
    }
}