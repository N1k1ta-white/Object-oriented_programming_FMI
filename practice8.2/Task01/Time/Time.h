#include <iostream>
#include <sstream>

struct Time {
private:
    int hour = 0;
    int min = 0;
    int sec = 0;
    bool type = false;

public:
    Time() = default;
    Time(const int hour, const int min, const int sec, const bool type);
    void getInfo(const char* str);
    bool getType() const;
    int toSeconds() const;
    bool operator>=(const Time& time) const;
    bool operator<=(const Time& time) const;
    bool operator<(const Time& time) const;
    bool operator>(const Time& time) const;
};