#pragma once
#define EVENT_TYPE_KEYBOARD 10
#define EVENT_TYPE_MOUSE 11
#define EVENT_TYPE_WHEEL 12

#define EVENT_TYPE_QUIT 13

#define FLAG_NONE 0
#define FLAG_KEY_UP 1
#define FLAG_KEY_DOWN 2
#define FLAG_KEY_TYPED 4

#define FLAG_MOUSE_L_DOWN 8
#define FLAG_MOUSE_R_DOWN 16
#define FLAG_MOUSE_L_UP 32
#define FLAG_MOUSE_R_UP 64
#define FLAG_MOUSE_MOVED 128


#define KEYCODE_UNKNOWN   0,

#define KEYCODE_RETURN   '\r'
#define KEYCODE_ESCAPE   '\x1B'
#define KEYCODE_BACKSPACE   '\b'
#define KEYCODE_TAB   '\t'
#define KEYCODE_SPACE   ' '
#define KEYCODE_EXCLAIM   '!'
#define KEYCODE_QUOTEDBL   '"'
#define KEYCODE_HASH   '#'
#define KEYCODE_PERCENT   '%'
#define KEYCODE_DOLLAR   '$'
#define KEYCODE_AMPERSAND   '&'
#define KEYCODE_QUOTE   '\''
#define KEYCODE_LEFTPAREN   '('
#define KEYCODE_RIGHTPAREN   ')'
#define KEYCODE_ASTERISK   '*'
#define KEYCODE_PLUS   '+'
#define KEYCODE_COMMA   ','
#define KEYCODE_MINUS   '-'
#define KEYCODE_PERIOD   '.'
#define KEYCODE_SLASH   '/'
#define KEYCODE_0   '0'
#define KEYCODE_1   '1'
#define KEYCODE_2   '2'
#define KEYCODE_3   '3'
#define KEYCODE_4   '4'
#define KEYCODE_5   '5'
#define KEYCODE_6   '6'
#define KEYCODE_7   '7'
#define KEYCODE_8   '8'
#define KEYCODE_9   '9'
#define KEYCODE_COLON   ':'
#define KEYCODE_SEMICOLON   ';'
#define KEYCODE_LESS   '<'
#define KEYCODE_EQUALS   ' '
#define KEYCODE_GREATER   '>'
#define KEYCODE_QUESTION   '?'
#define KEYCODE_AT   '@'


#define KEYCODE_LEFTBRACKET   '['
#define KEYCODE_BACKSLASH   '\\'
#define KEYCODE_RIGHTBRACKET   ']'
#define KEYCODE_CARET   '^'
#define KEYCODE_UNDERSCORE   '_'
#define KEYCODE_BACKQUOTE   '`'
#define KEYCODE_a   'a'
#define KEYCODE_b   'b'
#define KEYCODE_c   'c'
#define KEYCODE_d   'd'
#define KEYCODE_e   'e'
#define KEYCODE_f   'f'
#define KEYCODE_g   'g'
#define KEYCODE_h   'h'
#define KEYCODE_i   'i'
#define KEYCODE_j   'j'
#define KEYCODE_k   'k'
#define KEYCODE_l   'l'
#define KEYCODE_m   'm'
#define KEYCODE_n   'n'
#define KEYCODE_o   'o'
#define KEYCODE_p   'p'
#define KEYCODE_q   'q'
#define KEYCODE_r   'r'
#define KEYCODE_s   's'
#define KEYCODE_t   't'
#define KEYCODE_u   'u'
#define KEYCODE_v   'v'
#define KEYCODE_w   'w'
#define KEYCODE_x   'x'
#define KEYCODE_y   'y'
#define KEYCODE_z   'z'

#define KEYCODE_LCTRL 1073742048
#define KEYCODE_RCTRL 1073742052
#define KEYCODE_LALT 1073742050
#define KEYCODE_RALT 1073742054
#define KEYCODE_LSHIFT 1073742049
#define KEYCODE_RSHIFT 1073742053


namespace interface ::io {
    class Event {
        union EventData {
            int keyCode;
            struct {
                short x;
                short y;
                short wheelDelta;
            } mouse;
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
            this->flag = FLAG_NONE;
            this->data.keyCode = 0;
        }

        inline int GetType() const {
            return this->type;
        }

        inline void SetType(int type) {
            this->type = type;
        }

        inline unsigned int GetFlag() const {
            return this->flag;
        }

        inline const EventData &GetData() const {
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
