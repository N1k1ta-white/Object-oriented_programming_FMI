#include "Time.h"

void Time::getInfo(const char* str) {
    std::stringstream ss(str);
    char _type;
    ss >> _type;
    type = _type == '+';
    ss >> hour;
    ss >> min;
    ss >> sec;
}

bool Time::getType() const {
    return type;
}

int Time::toSeconds() const {
    return (hour * 3600 + min * 60 + sec);
}

bool Time::operator>=(const Time &time) const {
    if (toSeconds() >= time.toSeconds())
        return true;
    return false;
}

bool Time::operator<=(const Time &time) const {
    return !(*this > time);
}

bool Time::operator<(const Time &time) const {
    return !(*this >= time);
}

bool Time::operator>(const Time &time) const {
    if (toSeconds() > time.toSeconds())
        return true;
    return false;
}

Time::Time(const int hour, const int min, const int sec, const bool type) : hour(hour), min(min), sec(sec), type(type)  { }

