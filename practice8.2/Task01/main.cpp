#include "LogFile/LogFile.h"

int main() {
    LogFile logFile("test.txt");
    std::cout  << logFile.maxTime() << std::endl;
    std::cout << logFile.isInSystem(Time(20, 20, 20, 1));
}