#include <cstring>
#include "../Message/Message.h"

class User {
    char* name;
    char *password;
    char *email;

    void copyFrom(const User& user);
    void free();

public:
    User();
    ~User();
    User(const User& user);
    User& operator=(const User& user);
};