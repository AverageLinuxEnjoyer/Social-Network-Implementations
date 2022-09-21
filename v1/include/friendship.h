#ifndef FRIENDSHIP_HPP
#define FRIENDSHIP_HPP

#include <vector>

class User;

class Friendship {
public:
    Friendship();
    Friendship(const Friendship &other);
    Friendship(const User *user1, const User *user2);
    Friendship& operator=(const Friendship &other);
    ~Friendship() = default;

    const User *getUser1() const;
    const User *getUser2() const;

    bool operator==(const Friendship &other) const;
    bool operator!=(const Friendship &other) const;

private:
    const User *user1;
    const User *user2;
};

#endif // FRIENDSHIP_HPP
