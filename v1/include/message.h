#ifndef MESSAGE_H
#define MESSAGE_H

#include <string>

class User;

struct Message {
    const User* sender;
    const User* receiver;

    std::string content;
};

#endif // MESSAGE_H
