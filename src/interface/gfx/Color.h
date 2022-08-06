#pragma once

namespace interface::gfx {
    class Color {
    private:
        int r;
        int g;
        int b;
        int a;
    public:
        inline Color(int r, int g, int b)
                : r(r), g(g), b(b), a(255) {

        }

        inline Color(int r)
                : r(r), g(r), b(r), a(255) {
        }

        inline Color(int r, int g, int b, int a)
                : r(r), g(g), b(b), a(a) {

        }

        ~Color() = default;

        inline int GetR() const {
            return this->r;
        }

        inline int GetG() const {
            return this->g;
        }

        inline int GetB() const {
            return this->b;
        }

        inline int GetA() const {
            return this->a;
        }

        inline void SetR(int r) {
            this->r = r;
        }

        inline void SetG(int g) {
            this->g = g;
        }

        inline void SetB(int b) {
            this->b = b;
        }

        inline void SetA(int a) {
            this->a = a;
        }
    };
}