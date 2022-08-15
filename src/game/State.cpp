#include "State.h"

using namespace game;

void State::Reset() {
    state = NORMAL_STATE;
    statePrev = -1;
    stateNext = -1;

    keyState.keyCode = -1;
    keyState.keyFlags = 0;
    keyStatePrev.keyCode = -1;
    keyStatePrev.keyFlags = 0;
    keyStateNext.keyCode = -1;
    keyStateNext.keyFlags = 0;


    mouseState.mouseButton = -1;
    mouseState.mouseX = -1;
    mouseState.mouseX = -1;
    mouseState.mouseYrel = 0;
    mouseState.mouseXrel = 0;
    mouseState.wheelX = 0;
    mouseState.wheelY = 0;
    mouseState.mouseFlags = 0;

    mouseStatePrev.mouseButton = -1;
    mouseStatePrev.mouseX = -1;
    mouseStatePrev.mouseX = -1;
    mouseStatePrev.mouseXrel = 0;
    mouseStatePrev.mouseXrel = 0;
    mouseStatePrev.wheelX = 0;
    mouseStatePrev.wheelY = 0;
    mouseStatePrev.mouseFlags = 0;

    mouseStateNext.mouseButton = -1;
    mouseStateNext.mouseX = -1;
    mouseStateNext.mouseX = -1;
    mouseStateNext.wheelX = 0;
    mouseStateNext.wheelY = 0;
    mouseStateNext.mouseFlags = 0;
}