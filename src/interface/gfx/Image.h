#pragma once

class Image {
    int x;
    int y;
    int w;
    int h;
public:
    inline Image();

    virtual ~Image() = 0;
};