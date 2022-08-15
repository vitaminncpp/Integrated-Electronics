#include "State.h"

using namespace core::util;

void State::Reset() {
    this->state = NORMAL;
    this->selected = NORMAL;
    this->currX = -1;
    this->currY = -1;
}