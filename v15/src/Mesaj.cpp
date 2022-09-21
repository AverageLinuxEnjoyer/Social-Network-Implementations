#include "../include/Mesaj.h"
#include <iomanip>

Mesaj::Mesaj()
    : sender_id(),
      receiver_id(),
      text()
{}

Mesaj::Mesaj(int sender_id, int receiver_id, std::string content)
    : sender_id(sender_id),
      receiver_id(receiver_id),
      text(content)
{}

Mesaj::Mesaj(const Mesaj& other)
    : sender_id(other.sender_id),
      receiver_id(other.receiver_id),
      text(other.text)
{}

Mesaj::~Mesaj()
{}

Mesaj& Mesaj::operator=(const Mesaj& other) {
    sender_id = other.sender_id;
    receiver_id = other.receiver_id;
    text = other.text;
    return *this;
}

int Mesaj::senderId() const { 
    return sender_id; 
}

int Mesaj::receiverId() const { 
    return receiver_id; 
}

std::string Mesaj::getText() const { 
    return text; 
}

void Mesaj::setText(const std::string &text_) { 
    text = text_; 
}

std::ostream& operator<<(std::ostream& os, const Mesaj& mesaj) {
    os << mesaj.sender_id << " " << mesaj.receiver_id << " " << std::quoted(mesaj.text);
    return os;
}

std::istream& operator>>(std::istream& is, Mesaj& mesaj) {
    is >> mesaj.sender_id >> mesaj.receiver_id >> std::quoted(mesaj.text);
    return is;
}