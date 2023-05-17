#include "Tool.h"

Tool::Tool(int width, int height, int x, int y) {
    size.width = width;
    size.height = height;
    pos.x = x;
    pos.y = y;
}

void Tool::setSize(int width, int height) {
    size.width = width;
    size.height = height;
}

void Tool::setPos(int x, int y) {
    pos.x = x;
    pos.y = y;
}