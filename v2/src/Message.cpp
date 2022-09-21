#include "Message.h"

Message::Message()
{
}

Message::Message(int id , int senderId, int receiverId, const string &test)
    : user1_id(senderId),
      user2_id(receiverId),
      text(test),
      id(id)
{
    
}

Message::Message(const Message &message)
    : id(message.id),
      user1_id(message.user1_id),
      user2_id(message.user2_id),
      text(message.text)
{
    
}

Message::~Message()
{
    
}

string Message::getMessage() const {
    return text;
}


void Message::setMessage(const string &message) {
    text = message;
}

int Message::getId() const {
    return id;
}

void Message::setId(const int &id) {
    this->id = id;
}

int Message::getUser1Id() const {
    return user1_id;
}

void Message::setUser1Id(const int &userId) {
    user1_id = userId;
}

int Message::getUser2Id() const {
    return user2_id;
}

void Message::setUser2Id(const int &eventId) {
    user2_id = eventId;
}

bool Message::operator==(const Message &message) const {
    return id == message.id;
}

bool Message::operator!=(const Message &message) const {
    return !(*this == message);
}

bool Message::operator<(const Message &message) const {
    return id < message.id;
}
bool Message::operator>(const Message &message) const {
    return id > message.id;
}
