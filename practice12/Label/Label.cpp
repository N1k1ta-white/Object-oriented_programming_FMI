#include "Label.h"

void Label::setDataDialog() {
    std::cout << "New Text: ";
    std::cin >> text;
}

Label::Label(int width, int height, int x, int y, const MyString &str) : Tool(width, height, x, y), text(str) {}
