#ifndef UI_H
#define UI_H

#include "User.h"
#include "UserService.h"
#include "EventService.h"

class UI {
public:
    void startMenu();

    void showAllUsers();
    void showUser();
    void addUser();
    void updateUser();
    void removeUser();
    void showFriends();
    void addFriend();
    void removeFriend();
    void showAttendedEvents();

    void showMessages();
    void sendMessage();

    void addAttendedEvent();
    void removeAttendedEvent();

    void showAllEvents();
    void showEvent();
    void addEvent();
    void updateEvent();
    void removeEvent();
    void showAttendees();

    void exit();

private:
    UserService userService;
    EventSerice eventService;
};

#endif // UI_H
