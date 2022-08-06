#pragma once
#define EVENT_TYPE_KEYBOARD 10
#define EVENT_TYPE_MOUSE 11
#define EVENT_TYPE_WHEEL 12

#define FLAG_KEY_UP 1
#define FLAG_KEY_DOWN 2
#define FLAG_KEY_TYPED 4

#define FLAG_MOUSE_L_DOWN 8
#define FLAG_MOUSE_R_DOWN 16
#define FLAG_MOUSE_L_UP 32
#define FLAG_MOUSE_R_UP 64
#define FLAG_MOUSE_MOVED 128


namespace interface ::io {

    class Event {
    private:
        const int type;
        unsigned const int flag;
    public:
        inline explicit Event(int type, unsigned const int flag)
                : type(type), flag(flag) {
        }

        virtual ~Event() = default;

    public:
        inline const int GetType() const {
            return this->type;
        }

        inline const unsigned int GetFlag() const {
            return this->flag;
        }

    };

    class KeyEvent : public Event {
    private:
        const int keyCode;

    public:
        inline explicit KeyEvent(int keyCode, int flag)
                : Event(EVENT_TYPE_KEYBOARD, flag), keyCode(keyCode) {

        }

        inline ~KeyEvent() override = default;

        inline const int GetKeyCode() const {
            return this->keyCode;
        }

        inline const unsigned int GetKeyEventType() const {
            return this->GetFlag();
        }

    };

    class MouseEvent : public Event {
    private:
        const int x;
        const int y;
    public:
        inline explicit MouseEvent(int x, int y, unsigned int flag)
                : Event(EVENT_TYPE_MOUSE, flag), x(x), y(y) {

        }

        ~MouseEvent() override = default;

    public:
        inline const int GetX() const {
            return this->x;
        }

        inline const int GetY() const {
            return this->y;
        }

        inline const unsigned int GetMouseEventType() const {
            return this->GetFlag();
        }
    };

    class WheelEvent : public Event {
    private:
        const int delta;
    public:
        inline explicit WheelEvent(int delta, unsigned int flag)
                : Event(EVENT_TYPE_WHEEL, flag), delta(delta) {

        }

        inline ~WheelEvent() override = default;

        inline const int GetDelta() const {
            return this->delta;
        }

        inline const unsigned int GetWheelEventType() const {
            return this->GetFlag();
        }
    };
}

