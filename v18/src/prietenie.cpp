#include "../include/prietenie.h"
#include <iostream>

Prietenie::Prietenie()
    : user1(nullptr),
      user2(nullptr)
{}

Prietenie::Prietenie(const Prietenie &other)
    : user1(other.user1),
      user2(other.user2)
{}

Prietenie::Prietenie(const Utilizator *user1, const Utilizator *user2)
    : user1(user1),
      user2(user2)
{}

Prietenie& Prietenie::operator=(const Prietenie &other) {
    user1 = other.user1;
    user2 = other.user2;
    
    return *this;
}

const Utilizator *Prietenie::getUser1() const { return user1; }

const Utilizator *Prietenie::getUser2() const { return user2; }

bool Prietenie::operator==(const Prietenie &other) const {
    return user1 == other.user1 && user2 == other.user2;
}

bool Prietenie::operator!=(const Prietenie &other) const {
    return !(*this == other);
}