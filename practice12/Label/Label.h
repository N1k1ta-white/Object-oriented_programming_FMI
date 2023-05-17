#pragma once
#include "../MyString/MyString.h"
#include "../Tool/Tool.h"

class Label : public Tool {
    MyString text;
public:
    Label() = default;
    Label(int width, int height, int x, int y, const MyString& str);
    void setDataDialog() override;
}