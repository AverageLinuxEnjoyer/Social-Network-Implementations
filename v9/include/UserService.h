#ifndef USERSERVICE_H
#define USERSERVICE_H

#include "List.h"
#include "Ordered Set.h"
#include "User.h"
#include <vector>

using namespace std;

class UserService {
public:
    UserService();
    ~UserService();

    void addUser(User user);
    void updateUser(int id, User user);
    void removeUser(int id);
    User getUser(int id);
    vector<User> getUsers();
    void addFriend(int userId, int friendId);
    void removeFriend(int userId, int friendId);
    List<int> getFriends(int userId);
    void addEvent(int userId, int eventId);
    void removeEvent(int userId, int eventId);
    List<int> getEvents(int userId);

    List<Message> getMessages() const;
    List<Message> getMessages(int user1Id, int user2Id);
    void setMessages(const List<Message> &messages_);
    void sendMessage(Message message);

private:
    OrderedSet<User> users;
    List<Message> messages;

    void readUsersFromFile();
    void writeUsersToFile();

    void addFriendToUser(int userId, int friendId);
    void removeFriendFromUser(int userId, int friendId);
};

#endif // USERSERVICE_H
