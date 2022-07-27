#include <cmath>
#include "util.h"
#include "Vec2.h"

Vec2::Vec2() {
    this->x = 0;
    this->y = 0;
    this->r = 0;
    this->t = 0;
}

Vec2::Vec2(double x, double y) {
    this->x = x;
    this->y = y;
    AdjustRT();
}

Vec2::Vec2(const Vec2 &v) {
    this->x = v.x;
    this->y = v.y;
    this->r = v.r;
    this->t = v.t;
}

Vec2 &Vec2::operator=(const Vec2 &v) {
    this->x = v.x;
    this->y = v.y;
    this->r = v.r;
    this->t = v.t;
    return *this;
}

Vec2::Vec2(double r, double t, bool f) {
    this->r = r;
    this->t = wrapAngle(t);
    this->AdjustXY();
}

Vec2::~Vec2() {}

void Vec2::AdjustXY() {
    this->x = this->r * cos(this->t);
    this->y = this->r * sin(this->t);
}

void Vec2::AdjustRT() {

    if (this->x == 0 && this->y == y) {
        this->r = 0;
        this->t = 0;
        return;
    }

    if (this->x == 0) {
        if (this->y > 0) {
            this->
                    r = this->y;
            this->
                    t = PI / 2;
        } else {
            this->
                    r = -this->y;
            this->
                    t = 3 * PI / 2;
        }
        return;
    }

    if (this->y == 0) {
        if (this->x > 0) {
            this->
                    r = this->x;
            this->
                    t = 0;
        } else {
            this->
                    r = -this->x;
            this->
                    t = PI;
        }
        return;
    }

    this->
            r = sqrt(this->x * this->x + this->y * this->y);
    if (this->x >= 0) {
        if (this->y >= 0) {
            this->
                    t = asin(this->y / this->r);
        } else {
            this->
                    t = 2 * PI + asin(this->y / this->r);
        }
    } else {
        if (this->y >= 0) {
            this->
                    t = PI - asin(this->y / this->r);
        } else {
            this->
                    t = PI - asin(this->y / this->r);
        }
    }
}

Vec2 Vec2::operator+(const Vec2 &v) const {
    return Vec2(this->x + v.x, this->y + v.y);
}

Vec2 Vec2::operator+(const double r) const {
    return Vec2(this->r + r, this->t, true);
}

Vec2 Vec2::operator-() const {
    return Vec2(-x, -y);
}

Vec2 Vec2::operator-(const Vec2 &v) const {
    return Vec2(this->x - v.x, this->y - v.y);
}

Vec2 &Vec2::operator+=(const Vec2 &v) {
    this->x += v.x;
    this->y += v.y;
    AdjustRT();
    return *this;
}

Vec2 &Vec2::operator+=(const double r) {
    this->r += r;
    this->AdjustXY();
    return *this;
}

Vec2 &Vec2::operator-=(const Vec2 &v) {
    this->x -= v.x;
    this->y -= v.y;
    this->AdjustRT();
    return *this;
}

Vec2 &Vec2::operator-=(double r) {
    this->r -= r;
    this->AdjustXY();
    return *this;
}

Vec2 Vec2::operator*(double s) const {
    return Vec2(this->x * s, this->y * s);
}

Vec2 &Vec2::operator*=(double s) {
    this->r *= s;
    AdjustXY();
    return *this;
}

Vec2 &Vec2::Norm() {
    this->r = 1;
    this->AdjustXY();
    return *this;
}

Vec2 Vec2::operator/(double d) const {
    return Vec2(this->r / d, this->t, true);
}

Vec2 &Vec2::operator/=(double d) {
    this->r /= d;
    this->AdjustXY();
    return *this;
}

Vec2 Vec2::GetNorm() const {
    return Vec2(this->x / this->r, this->y / this->r);
}

Vec2 &Vec2::Ortho() {
    double temp = this->x;
    this->x = this->y;
    this->x = -temp;
    this->AdjustRT();
    return *this;
}

Vec2 Vec2::GetOrtho() const {
    return Vec2(this->y, -this->x);
}

double Vec2::Dot(const Vec2 &v) {
    return this->x * v.x + this->y * v.y;
}

double Vec2::Cross(const Vec2 &v) {
    return this->x * v.y - this->y * v.x;
}

double Vec2::Distance(const Vec2 &v) {
    return (*this - v).GetR();
}

Vec2 &Vec2::Rotate(double t) {
    this->t = wrapAngle(this->t + t);
    AdjustXY();
    return *this;
}

Vec2 &Vec2::Rotate(double t, const Vec2 &v) {
    *this -= v;
    this->t = wrapAngle(this->t + t);
    AdjustXY();
    *this += v;
    return *this;
}

Vec2 Vec2::GetRotate(double t) {
    return Vec2(this->r, this->t + t, true);
}

Vec2 Vec2::GetRotate(double t, const Vec2 &v) {
    Vec2 tmp(*this);
    tmp.Rotate(t, v);
    return tmp;
}