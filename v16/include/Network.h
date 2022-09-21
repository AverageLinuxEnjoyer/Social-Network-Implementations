#ifndef NETWORK_H
#define NETWORK_H

#include "EventService.h"
#include "UserService.h"
#include "OrderedSet.h"
#include "Message.h"
#include "Friendship.h"
#include "EventSubscription.h"

class Network {
public:
    Network();
    ~Network();

    void addUser(const User &user);
    void addEvent(const Event &event);
    void addMessage(const Message &message);
    void addFriendship(const Friendship &friendship);

    void removeUser(int id);
    void removeEvent(int id);
    void removeMessage(int id);
    void removeFriendship(int id_user1, int id_user2);
    
    void modifyUser(int id, const User &user);
    void modifyEvent(int id, const Event &event);

    List<User> getUsers();
    List<Event> getEvents();
    List<Message> getMessages();
    List<Message> getMessages(int user_id);
    List<Message> getMessages(int user_id1, int user_id2);
    User getUser(int id);
    Event getEvent(int id);
    List<Friendship> getFriendships();
    List<Friendship> getFriends(int id_user);

    void subscribe(int user_id, int event_id);
    void unsubscribe(int user_id, int event_id);

    List<User> getSubscribers(int event_id);
    List<Event> getSubscriptions(int user_id);

private:
    EventService eventService;
    UserService userService;
    OrderedSet<Message> messages;
    OrderedSet<Friendship> friendships;
    List<EventSubscription> eventSubscriptions;
};

#endif // NETWORK_H
