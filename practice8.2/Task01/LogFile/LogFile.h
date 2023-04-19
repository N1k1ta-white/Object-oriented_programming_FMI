#include "../Time/Time.h"
#include <fstream>

const int MAX_SIZE = 100;

class LogFile {
    Time time[MAX_SIZE];
    int count = 0;

public:
    LogFile() = default;
    LogFile(const char* path);
    int countLogin() const;
    int countOut() const;
    int maxTime() const;
    bool isInSystem(const Time& curTime);
};
