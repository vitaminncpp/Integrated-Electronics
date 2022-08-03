#pragma once

#include "Event.h"

class InputBridge {
public:
    inline InputBridge() {}

    inline virtual ~InputBridge() {}

public:
    virtual void SendEvent(const Event &event) = 0;
};