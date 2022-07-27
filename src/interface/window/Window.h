#pragma once

#include <string>

class Window {
    int width;
public:
    inline int GetWidth() const {
        return width;
    }

    inline void SetWidth(int width) {
        this->width = width;
    }

    inline int GetHeight() const {
        return this->height;
    }

    inline void SetHeight(int height) {
        this->height = height;
    }

    inline const std::string &GetTitle() const {
        return this->title;
    }

    inline void SetTitle(const std::string &title) {
        this->title = title;
    }

private:
    int height;
    std::string title;
public:
    inline Window(const std::string &title, int width, int height)
            : title(title), width(width), height(height) {}

    virtual void Init() = 0;

    virtual void Update() = 0;

    virtual void Render() = 0;

    virtual void Reset() = 0;

    virtual void EndFrame() = 0;

    virtual void BeginFrame() = 0;

    virtual void Close() = 0;

    virtual void Show() = 0;

};