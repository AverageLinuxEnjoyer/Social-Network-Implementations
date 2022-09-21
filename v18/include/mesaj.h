#ifndef MESSAGE_H
#define MESSAGE_H

#include <string>

class Utilizator;

struct Mesaj {
    const Utilizator* user_expeditor;
    const Utilizator* user_destinatar;

    std::string continut;
};

#endif // MESSAGE_H
