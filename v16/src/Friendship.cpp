#include "../include/Friendship.h"

Friendship::Friendship()
{
    
}

Friendship::Friendship(int userId, int friendId)
{
    this->user1_id = userId;
    this->user2_id = friendId;
}


Friendship::Friendship(const Friendship &friendship)
{
    this->user1_id = friendship.user1_id;
    this->user2_id = friendship.user2_id;
}

Friendship::~Friendship()
{
    
}

int Friendship::getUser1Id() const
{
    return user1_id;
}

void Friendship::setUser1Id(const int &user1Id)
{
    this->user1_id = user1Id;
}

int Friendship::getUser2Id() const
{
    return user2_id;
}

void Friendship::setUser2Id(const int &user2Id)
{
    this->user2_id = user2Id;
}

bool Friendship::operator==(const Friendship &friendship) const
{
    return (user1_id == friendship.user1_id && user2_id == friendship.user2_id) ||
           (user1_id == friendship.user2_id && user2_id == friendship.user1_id);
}

bool Friendship::operator!=(const Friendship &friendship) const
{
    return !(*this == friendship);
}

bool Friendship::operator<(const Friendship &friendship) const
{
    return user1_id < friendship.user1_id ||
           (user1_id == friendship.user1_id && user2_id < friendship.user2_id);
}
bool Friendship::operator>(const Friendship &friendship) const {
    return !(*this < friendship) && !(*this == friendship);
}
