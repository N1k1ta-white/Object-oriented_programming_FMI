#pragma once
#include "../MyString/MyString.h"
#include "../Tool/Tool.h"

class RadioButton : public Tool {
    MyString* options;
    int count;
    int active;

    void free();

    void copyFrom(const RadioButton& radioButton);

public:
    RadioButton();
    RadioButton(int width, int height, int x, int y, const MyString* _options, int count, int active);
    RadioButton& operator=(const RadioButton& radioButton);
    RadioButton(const RadioButton& radioButton);
    ~RadioButton();
    void setDataDialog() override;
};