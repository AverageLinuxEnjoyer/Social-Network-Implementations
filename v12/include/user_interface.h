#ifndef USER_INTERFACE_H
#define USER_INTERFACE_H

#include "user_service.h"
#include "event_service.h"

class UserInterface {
public:
    void run();

private:
    void show_all_users_menu();
    void show_user_menu();
    void add_user_menu();
    void update_user_menu();
    void remove_user_menu();

    void add_friend_menu();
    void remove_friend_menu();
    void show_friends_menu();

    void add_message_menu();
    void show_messages_menu();
    void delete_chat_menu();


    void show_all_events_menu();
    void show_event_menu();
    void add_event_menu();
    void update_event_menu();
    void remove_event_menu();

    void add_participant_menu();
    void remove_participant_menu();
    void show_participants_menu();

private:
    UserService user_service;
    EventService event_service;
};

#endif // USER_INTERFACE_H
