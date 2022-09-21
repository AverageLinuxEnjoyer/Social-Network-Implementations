#include "../include/service.h"

class UI {
public:
    UI(Service &user_service);
    ~UI() = default;

    void run();

    void user_menu();
    void event_menu();

    void printUsers();
    void add_user_menu();
    void update_user_menu();
    void remove_user_menu();
    void add_friendship_menu();
    void remove_friendship_menu();
    void print_friends();
    void send_message_menu();
    void print_messages();

    void print_events_menu();
    void add_event_menu();
    void update_event_menu();
    void remove_event_menu();
    void add_interested_user_menu();
    void print_interested_users();

private:
    Service& userService;
};