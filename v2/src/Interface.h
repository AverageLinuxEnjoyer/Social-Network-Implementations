#ifndef INTERFACE_H
#define INTERFACE_H

#include "Network.h"

using namespace std;

class Interface {
public:
    Interface();
    ~Interface();

    void start();

private:
    Network network;

    void getUser();
    void getEvent();

    void addUser();
    void addEvent();
    void addMessage();
    void addFriendship();

    void removeUser();
    void removeEvent();
    void removeMessage();
    void removeFriendship();

    void modifyUser();
    void modifyEvent();

    void getAllUsers();
    void getAllEvents();
    void getAllMessages();
    void getMessagesOfUser();
    void getMessagesBetweenUsers();
    void getAllFriendships();
    void getFriendsOfUser();

    void subscribe();
    void unsubscribe();
    void showEventSubscriptions();
    void showUserSubscriptions();
};

#endif // INTERFACE_H
