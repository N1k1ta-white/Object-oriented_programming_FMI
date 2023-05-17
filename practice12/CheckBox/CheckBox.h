#pragma once
#include "../MyString/MyString.h"
#include "../Tool/Tool.h"

class CheckBox : public Tool {
    MyString text;
    bool status;
public:
    CheckBox() = default;
    CheckBox(int width, int height, int x, int y, const MyString& str, bool stat);
    void setDataDialog() override;
    void setText(const MyString& str);
    void setStatus(bool stat);
};
