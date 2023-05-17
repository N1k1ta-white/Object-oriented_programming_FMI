#pragma once
#include "../MyString/MyString.h"
#include "../Size.h"

class Tool {
public:
    struct Pos {
        int x, y;
    };
private:
    Size size;
    Pos pos;
public:
    Tool() = default;
    Tool(int width, int height, int x, int y);
    virtual void setDataDialog() = 0;
    void setSize(int width, int height);
    void setPos(int x, int y);
};
