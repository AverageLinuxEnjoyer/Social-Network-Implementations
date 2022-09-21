#ifndef USERINTERFACE_H
#define USERINTERFACE_H

#include "Network.h"

class UserInterface {
public:
    UserInterface();
    ~UserInterface();

    void start();

private:
    Network& network;

    void userDetails();
    void listUsers();
    void addUser();
    void updateUser();
    void deleteUser();

    void eventDetails();
    void listEvents();
    void addEvent();
    void updateEvent();
    void deleteEvent();
    void listEventsAttendedByUser();
    void listUsersAttendingEvent();

    void addFriendship();
    void removeFriendship();
    void listFriends();
    void listCommonFriends();

    void addAttendance();
    void removeAttendance();

    void addMessage();
    void messagesOfUser();
    void messagesBetweenUsers();
};

#endif // USERINTERFACE_H
