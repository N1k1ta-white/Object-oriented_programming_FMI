#include "User.h"


User::User() {
    name = new char[1];
    name[0] = '\0';
    email = new char[1];
    email[0] = '\0';
    password = new char[1];
    password[0] = '\0';
}

void User::free() {
    delete[] name;
    delete[] email;
    delete[] password;
}

void User::copyFrom(const User &user) {
    name = new char[strlen(user.name) + 1];
    strcpy(name, user.name);
    email = new char[strlen(user.email) + 1];
    strcpy(email, user.email);
    password = new char[strlen(user.password) + 1];
    strcpy(password, user.password);
}

User::User(const User &user) {
    copyFrom(user);
}

User &User::operator=(const User &user) {
    if (this != &user) {
        free();
        copyFrom(user);
    }
    return *this;
}

User::~User() {
    free();
}