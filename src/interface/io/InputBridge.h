#pragma once

#include "Event.h"

namespace interface::io {
    class InputBridge {
    public:
        inline InputBridge() = default;

        inline virtual ~InputBridge() = default;

    public:
        virtual void SendEvent(const Event &event) = 0;
    };
}