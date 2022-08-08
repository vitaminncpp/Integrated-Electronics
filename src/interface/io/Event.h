#pragma once
#define EVENT_TYPE_KEYBOARD 10
#define EVENT_TYPE_MOUSE 11
#define EVENT_TYPE_WHEEL 12

#define EVENT_TYPE_QUIT 13

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
        union EventData {
            int keyCode;
            struct {
                short x;
                short y;
            } mouse;
            int wheelDelta;
        };
    private:
        int type;
        unsigned int flag;
        EventData data;
    public:
        inline explicit Event() = default;

        inline explicit Event(int type, unsigned const int flag)
                : type(type), flag(flag) {
        }

        ~Event() = default;

    public:

        inline void Reset() {
            this->type = -1;
            this->flag = 0;
            this->data.keyCode = 0;
        }

        inline int GetType() const {
            return this->type;
        }

        inline unsigned int GetFlag() const {
            return this->flag;
        }

        inline EventData &GetData() {
            return this->data;
        }

        inline void SetFlag(unsigned int flag) {
            this->flag |= flag;
        }

        inline void SetData(EventData &data) {
            this->data = data;
        }

        //Useless, but I don't want to remove it.
        inline void SetData(EventData &&data) {
            this->data = std::move(data);
        }
    };
}