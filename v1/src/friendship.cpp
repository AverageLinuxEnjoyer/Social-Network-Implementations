#include "../include/friendship.h"
#include <iostream>

Friendship::Friendship()
    : user1(nullptr),
      user2(nullptr)
{}

Friendship::Friendship(const Friendship &other)
    : user1(other.user1),
      user2(other.user2)
{}

Friendship::Friendship(const User *user1, const User *user2)
    : user1(user1),
      user2(user2)
{}

Friendship& Friendship::operator=(const Friendship &other) {
    user1 = other.user1;
    user2 = other.user2;
    
    return *this;
}

const User *Friendship::getUser1() const { return user1; }

const User *Friendship::getUser2() const { return user2; }

bool Friendship::operator==(const Friendship &other) const {
    return user1 == other.user1 && user2 == other.user2;
}

bool Friendship::operator!=(const Friendship &other) const {
    return !(*this == other);
}