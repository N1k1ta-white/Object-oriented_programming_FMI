#include "Message.h"


Message::Message() {
    text = new char[1];
    text[0] = '\0';
    sender = receiver = 0;
}

void Message::free() {
    delete[] text;
    sender = receiver = 0;
}

void Message::copyFrom(const Message &Message) {
    text = new char[strlen(Message.text) + 1];
    strcpy(text, Message.text);
    sender = Message.sender;
    receiver = Message.receiver;
}

Message::Message(const Message &Message) {
    copyFrom(Message);
}

Message &Message::operator=(const Message &Message) {
    if (this != &Message) {
        free();
        copyFrom(Message);
    }
    return *this;
}

Message::~Message() {
    free();
}