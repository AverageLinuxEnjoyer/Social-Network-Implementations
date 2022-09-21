#ifndef NETWORK_H
#define NETWORK_H

#include "Event.h"
#include "User.h"
#include "MultiDictionary.h"
#include "Set.h"
#include "Message.h"
#include <vector>


class Network {
private:
    Set<User> users;
    Set<Event> events;
    MultiDictionary<User*, User*> friends;
    MultiDictionary<User*, Event*> attended_events;
    std::vector<Message> messages;

    Network();

    void loadUsersFromFile(std::string filename);
    void saveUsersToFile(std::string filename);

public:
    static Network& getInstance();

    ~Network();

    Set<User>& getUsers();
    Set<Event>& getEvents();
    MultiDictionary<User*, User*>& getFriends();
    MultiDictionary<User*, Event*>& getAttendedEvents();

    User* findUser(std::string username);
    Event* findEvent(std::string event_name);
    void addUser(User* user);
    void addEvent(Event* event);
    void addFriendship(User* user1, User* user2);
    void addAttendance(User* user, Event* event);
    void addMessage(Message message);

    void updateUser(User* user, User new_user);
    void updateEvent(Event* event, Event new_event);

    void removeUser(User* user);
    void removeEvent(Event* event);
    void removeFriendship(User* user1, User* user2);
    void removeAttendance(User* user, Event* event);
      
    std::vector<User*> getFriendsOf(User* user);
    std::vector<User*> getCommonFriends(User* user1, User* user2);
    std::vector<Event*> getEventsAttendedBy(User* user);
    std::vector<User*> getUsersAttending(Event* event);
    std::vector<Message> getMessages(User* user);
    std::vector<Message> getMessages(User* user1, User* user2);
};

#endif // NETWORK_H
