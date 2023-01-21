#pragma once

namespace lib::math {

    class Vec2 {
    private:
        double x;
        double y;
        double r;
        double t;

    private:
        void AdjustXY();

        void AdjustRT();

    public:
        Vec2();

        Vec2(double x, double y);

        Vec2(double r, double t, bool f);

        ~Vec2();

        Vec2(const Vec2 &v);

        Vec2 &operator=(const Vec2 &v);

        Vec2 operator-() const;

        Vec2 operator+(const Vec2 &v) const;

        Vec2 operator+(const double r) const;

        Vec2 &operator+=(const Vec2 &v);

        Vec2 &operator+=(const double);

        Vec2 operator-(const Vec2 &v) const;

        Vec2 operator-(double d) const;

        Vec2 &operator-=(const Vec2 &v);

        Vec2 &operator-=(double r);

        Vec2 operator*(double s) const;

        Vec2 operator*(const Vec2 &) const;

        Vec2 &operator*=(double s);

        Vec2 &operator*=(const Vec2 &s);

        Vec2 operator/(double s) const;

        Vec2 operator/(const Vec2 &s) const;

        Vec2 &operator/=(double d);

        Vec2 &operator/=(const Vec2 &d);

        Vec2 &Norm();

        Vec2 GetNorm() const;

        Vec2 &Ortho();

        Vec2 GetOrtho() const;

        double Dot(const Vec2 &v) const;

        double Cross(const Vec2 &v) const;

        double Distance(const Vec2 &v) const;

        Vec2 &Rotate(double t);

        Vec2 GetRotate(double t) const;

        Vec2 &Rotate(double t, const Vec2 &v);

        Vec2 GetRotate(double t, const Vec2 &v);

        Vec2 &Floor();

        Vec2 GetFloor() const;

        inline double GetX() const {
            return this->x;
        }

        inline double GetY() const {
            return this->y;
        }

        inline double GetR() const {
            return this->r;
        }

        inline double GetT() const {
            return this->t;
        }

        inline void SetX(double x) {
            this->x = x;
            this->AdjustRT();
        }

        inline void SetY(double y) {
            this->y = y;
            AdjustRT();
        }

        inline void SetR(double r) {
            this->r = r;
            this->AdjustXY();
        }

        inline void SetT(double t) {
            this->t = t;
            this->AdjustXY();
        }

        inline void SetXY(double x, double y) {
            this->x = x;
            this->y = y;

            AdjustRT();
        }

        inline void SetRT(double r, double t) {
            this->r = r;
            this->t = t;
            AdjustXY();
        }

    };
}
