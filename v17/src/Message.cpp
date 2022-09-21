#include "../include/Message.h"

Message::Message(const std::string& text, User* sender, User* receiver)
    : text(text),
      sender(sender),
      receiver(receiver)
{}

Message::~Message()
{}

std::string Message::getText() const {
    return this->text;
}

User* Message::getSender() const {
    return this->sender;
}

User* Message::getReceiver() const {
    return this->receiver;
}
