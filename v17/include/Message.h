#ifndef MESSAGE_H
#define MESSAGE_H

#include "User.h"

class Message {
private:
    std::string text;
    User* sender;
    User* receiver;
    
public:
    Message() = default;
    Message(const std::string& text, User* sender, User* receiver);
    Message(const Message& message) = default;

    ~Message();

    std::string getText() const;
    User* getSender() const;
    User* getReceiver() const;
};

#endif // MESSAGE_H
