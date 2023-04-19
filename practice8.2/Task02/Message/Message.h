#include <cstring>
#include <iostream>

class Message {
    char* text;
    int sender;
    int receiver;

    void copyFrom(const Message& Message);
    void free();
    
public:
    Message();
    ~Message();
    Message(const Message& Message);
    Message& operator=(const Message& Message);
};