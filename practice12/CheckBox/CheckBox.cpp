#include "CheckBox.h"

CheckBox::CheckBox(int width, int height, int x, int y, const MyString &str, bool stat) : Tool(width, height, x, y), text(str), status(stat) {}

void CheckBox::setDataDialog() {
    std::cout << "New Text: ";
    std::cin >> text;
    std::cout << "New status: ";
    std::cin >> status;
}

void CheckBox::setStatus(bool stat) {
    status = stat;
}

void CheckBox::setText(const MyString &str) {
    text = str;
}