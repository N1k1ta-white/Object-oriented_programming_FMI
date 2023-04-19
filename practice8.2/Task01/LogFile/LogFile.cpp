#include "LogFile.h"

const int BUFF_SIZE = 1024;

LogFile::LogFile(const char *path) {
    std::fstream file(path, std::ios::in);
    if (!file.is_open())
        throw "Error";
    char reader[BUFF_SIZE];
    file.getline(reader, BUFF_SIZE);
    std::stringstream ss(reader);
    ss >> count;
    if (count > 100 || count < 0)
        throw "Error";
    for (int i = 0; i < count; ++i) {
        file.getline(reader, BUFF_SIZE);
        time[i].getInfo(reader);
    }
    file.close();
}

int LogFile::countLogin() const {
    int res = 0;
    for (int i = 0; i < count; ++i)
        if (time[i].getType())
            res++;
    return res;
}

int LogFile::countOut() const {
    return count - countLogin();
}

int LogFile::maxTime() const {
    int max = INT_MIN, start;
    for (int i = 0; i < count; ++i) {
        if (time[i].getType())
            start = time[i].toSeconds();
        else if (!time[i].getType() && i != 0)
            if (max < time[i].toSeconds() - start)
                max = time[i].toSeconds() - start;
    }
    return max;
}

bool LogFile::isInSystem(const Time &curTime) {
    for (int i = 0; i < count - 1; ++i) {
        if (time[i].getType())
            if (time[i] < curTime)
                if (time[i + 1] >= curTime)
                    return true;
    }
    return false;
}