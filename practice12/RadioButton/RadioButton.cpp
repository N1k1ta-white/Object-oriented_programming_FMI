#include "RadioButton.h"

void RadioButton::free() {
    delete[] options;
    count = active = 0;
}

void RadioButton::copyFrom(const RadioButton &radioButton) {
    count = radioButton.count;
    options = new MyString[count];
    for (int i = 0; i < count; ++i)
        options[i] = radioButton.options[i];
    active = radioButton.active;
}

RadioButton::RadioButton() {
    options = nullptr;
    count = active = 0;
}

RadioButton::RadioButton(int width, int height, int x, int y, const MyString *_options, int count, int active) : Tool(width, height, x, y), count(count), active(active) {
    for (int i = 0; i < count; ++i)
        options[i] = _options[i];
}

RadioButton &RadioButton::operator=(const RadioButton &radioButton) {
    if (this != &radioButton) {
        free();
        copyFrom(radioButton);
    }
    return *this;
}

RadioButton::RadioButton(const RadioButton &radioButton) {
    copyFrom(radioButton);
}

RadioButton::~RadioButton() {
    free();
}

void RadioButton::setDataDialog() {
    std::cout << "New active: ";
    std::cin >> active;
    if (active >= count)
        throw std::logic_error("Position's number bigger than count of options");
    if (active < 0)
        throw std::logic_error("Invalid input");
}