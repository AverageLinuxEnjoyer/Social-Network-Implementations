#ifndef FRIENDSHIP_H
#define FRIENDSHIP_H

class Friendship {
public:
    Friendship();
    Friendship(int userId, int friendId);
    Friendship(const Friendship &friendship);
    ~Friendship();

    int getUser1Id() const;
    void setUser1Id(const int &user1Id);

    int getUser2Id() const;
    void setUser2Id(const int &user2Id);

    bool operator==(const Friendship &friendship) const;
    bool operator!=(const Friendship &friendship) const;
    bool operator<(const Friendship &friendship) const;
    bool operator>(const Friendship &friendship) const;

private:
    int user1_id;
    int user2_id;
};

#endif // FRIENDSHIP_H
