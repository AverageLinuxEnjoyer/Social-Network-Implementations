#include "../include/UserInterface.h"

inline void Clear()
{
#if defined _WIN32
    system("cls");
#elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
    system("clear");
#elif defined (__APPLE__)
    system("clear");
#endif
}

UserInterface::UserInterface()
    : network(Network::getInstance())
{}

UserInterface::~UserInterface()
{}

void UserInterface::start() {
    int command = -1;
    
    while(true) {
        std::cout << "0. User details" << std::endl;
        std::cout << "1. List users" << std::endl;
        std::cout << "2. Add user" << std::endl;
        std::cout << "3. Update existing user" << std::endl;
        std::cout << "4. Delete user" << std::endl;

        std::cout << "5. Event details" << std::endl;
        std::cout << "6. List events" << std::endl;
        std::cout << "7. Add event" << std::endl;
        std::cout << "8. Update existing event" << std::endl;
        std::cout << "9. Delete event" << std::endl;
        std::cout << "10. List events attended by a user" << std::endl;
        std::cout << "11. List users attending an event" << std::endl;

        std::cout << "12. Add friendship" << std::endl;
        std::cout << "13. Remove friendship" << std::endl;
        std::cout << "14. List friends" << std::endl;
        std::cout << "15. List common friends" << std::endl;

        std::cout << "16. Add attendance" << std::endl;
        std::cout << "17. Remove attendance" << std::endl;

        std::cout << "18. Add message" << std::endl;
        std::cout << "19. List messages of user" << std::endl;
        std::cout << "20. List messages of 2 users" << std::endl;

        std::cout << "21. Exit" << std::endl;

        std::cout << "Enter option: ";
        std::cin >> command;

        Clear();

        switch(command) {
            case 0:
                userDetails();
                break;
            case 1:
                listUsers();
                break;
            case 2:
                addUser();
                break;
            case 3:
                updateUser();
                break;
            case 4:
                deleteUser();
                break;
            case 5:
                eventDetails();
                break;
            case 6:
                listEvents();
                break;
            case 7:
                addEvent();
                break;
            case 8:
                updateEvent();
                break;
            case 9:
                deleteEvent();
                break;
            case 10:
                listEventsAttendedByUser();
                break;
            case 11:
                listUsersAttendingEvent();
                break;
            case 12:
                addFriendship();
                break;
            case 13:
                removeFriendship();
                break;
            case 14:
                listFriends();
                break;
            case 15:
                listCommonFriends();
                break;
            case 16:
                addAttendance();
                break;
            case 17:
                removeAttendance();
                break;
            case 18:
                addMessage();
                break;
            case 19:
                messagesOfUser();
                break;
            case 20:
                messagesBetweenUsers();
                break;
            case 21:
                return;
            default:
                std::cout << "Invalid option. Try again." << std::endl;
        }
        std::cout << "Press enter to continue...";
        std::cin.ignore();
        std::cin.get();

        Clear();
    }
}

void UserInterface::userDetails() {
    std::string username;
    std::cout << "Enter username: ";
    std::cin >> username;

    User* user = network.findUser(username);
    if(user == nullptr) {
        std::cout << "User not found." << std::endl;
        return;
    }

    std::cout << *user << std::endl;
}

void UserInterface::listUsers() {
    auto users_vec = network.getUsers().getAll();

    std::cout << "Users:" << std::endl;
    for (auto& user_ptr : users_vec) {
        std::cout << user_ptr->getUsername() << std::endl;
    }
}

void UserInterface::addUser() {
    std::cin.ignore();

    User* user = new User();
    std::cin >> *user;

    network.addUser(user);

    std::cout << "User added." << std::endl;
}

void UserInterface::updateUser() {
    std::string username;
    std::cout << "Enter username: ";
    std::cin >> username;

    User* user = network.findUser(username);

    if (user == nullptr) {
        std::cout << "User not found" << std::endl;
        return;
    }

    User new_user;
    std::cin >> new_user;

    network.updateUser(user, new_user);

    std::cout << "User updated." << std::endl;
}

void UserInterface::deleteUser() {
    std::string username;
    std::cout << "Enter username: ";
    std::cin >> username;

    User* user = network.findUser(username);

    if (user == nullptr) {
        std::cout << "User not found" << std::endl;
        return;
    }

    network.removeUser(user);

    std::cout << "User deleted." << std::endl;
}

void UserInterface::eventDetails() {
    std::string event_name;
    std::cout << "Enter event name: ";
    std::cin >> event_name;

    Event* event = network.findEvent(event_name);
    if(event == nullptr) {
        std::cout << "Event not found." << std::endl;
        return;
    }

    std::cout << *event << std::endl;
}

void UserInterface::listEvents() {
    auto events_vec = network.getEvents().getAll();

    std::cout << "Events:" << std::endl;
    for (auto& event_ptr : events_vec) {
        std::cout << event_ptr->getName() << std::endl;
    }
}

void UserInterface::addEvent() {
    Event* event = new Event();
    std::cin >> *event;

    network.addEvent(event);

    std::cout << "Event added." << std::endl;
}

void UserInterface::updateEvent() {
    std::string event_name;
    std::cout << "Enter event name: ";
    std::cin >> event_name;

    Event* event = network.findEvent(event_name);

    if (event == nullptr) {
        std::cout << "Event not found" << std::endl;
        return;
    }

    Event new_event;
    std::cin >> new_event;

    network.updateEvent(event, new_event);

    std::cout << "Event updated." << std::endl;
}

void UserInterface::deleteEvent() {
    std::string event_name;
    std::cout << "Enter event name: ";
    std::cin >> event_name;

    Event* event = network.findEvent(event_name);

    if (event == nullptr) {
        std::cout << "Event not found" << std::endl;
        return;
    }

    network.removeEvent(event);

    std::cout << "Event deleted." << std::endl;
}

void UserInterface::listEventsAttendedByUser() {
    std::string username;
    std::cout << "Enter username: ";
    std::cin >> username;

    User* user = network.findUser(username);

    if (user == nullptr) {
        std::cout << "User not found" << std::endl;
        return;
    }

    auto events_vec = network.getAttendedEvents().get(user);

    std::cout << "Events attended by " << user->getUsername() << ":" << std::endl;
    for (auto& event_ptr : events_vec) {
        std::cout << event_ptr->getName() << std::endl;
    }
}

void UserInterface::listUsersAttendingEvent() {
    std::string event_name;
    std::cout << "Enter event name: ";
    std::cin >> event_name;

    Event* event = network.findEvent(event_name);

    if (event == nullptr) {
        std::cout << "Event not found" << std::endl;
        return;
    }

    auto users_vec = network.getUsers().getAll();

    std::cout << "Users attending " << event->getName() << ":" << std::endl;
    for (auto& user_ptr : users_vec) {
        auto events_vec = network.getEventsAttendedBy(user_ptr);
        for (auto& event_ptr : events_vec) {
            if (event_ptr == event)
            {
                std::cout << user_ptr->getUsername() << std::endl;
                break;
            }
        }

    }
}

void UserInterface::addFriendship() {
    std::string username1;
    std::string username2;
    std::cout << "Enter username 1: ";
    std::cin >> username1;
    std::cout << "Enter username 2: ";
    std::cin >> username2;

    User* user1 = network.findUser(username1);
    User* user2 = network.findUser(username2);

    if (user1 == nullptr || user2 == nullptr) {
        std::cout << "User not found" << std::endl;
        return;
    }

    network.addFriendship(user1, user2);

    std::cout << "Friendship added." << std::endl;
}

void UserInterface::removeFriendship() {
    std::string username1;
    std::string username2;
    std::cout << "Enter username 1: ";
    std::cin >> username1;
    std::cout << "Enter username 2: ";
    std::cin >> username2;

    User* user1 = network.findUser(username1);
    User* user2 = network.findUser(username2);

    if (user1 == nullptr || user2 == nullptr) {
        std::cout << "User not found" << std::endl;
        return;
    }

    network.removeFriendship(user1, user2);

    std::cout << "Friendship removed." << std::endl;
}

void UserInterface::listFriends() {
    std::string username;
    std::cout << "Enter username: ";
    std::cin >> username;

    User* user = network.findUser(username);

    if (user == nullptr) {
        std::cout << "User not found" << std::endl;
        return;
    }

    auto friends_vec = network.getFriends().get(user);

    std::cout << "Friends of " << user->getUsername() << ":" << std::endl;
    for (auto& friend_ptr : friends_vec) {
        std::cout << friend_ptr->getUsername() << std::endl;
    }
}

void UserInterface::listCommonFriends() {
    std::string username1;
    std::string username2;
    std::cout << "Enter username 1: ";
    std::cin >> username1;
    std::cout << "Enter username 2: ";
    std::cin >> username2;

    User* user1 = network.findUser(username1);
    User* user2 = network.findUser(username2);

    if (user1 == nullptr || user2 == nullptr) {
        std::cout << "User not found" << std::endl;
        return;
    }

    auto friends_vec = network.getCommonFriends(user1, user2);

    std::cout << "Common friends of " << user1->getUsername() << " and " << user2->getUsername() << ":" << std::endl;
    for (auto& friend_ptr : friends_vec) {
        std::cout << friend_ptr->getUsername() << std::endl;
    }
}

void UserInterface::addAttendance() {
    std::string event_name;
    std::string username;
    std::cout << "Enter event name: ";
    std::cin >> event_name;
    std::cout << "Enter username: ";
    std::cin >> username;

    Event* event = network.findEvent(event_name);
    User* user = network.findUser(username);

    if (event == nullptr || user == nullptr) {
        std::cout << "Event or user not found" << std::endl;
        return;
    }

    network.addAttendance(user, event);

    std::cout << "Attendance added." << std::endl;
}

void UserInterface::removeAttendance() {
    std::string event_name;
    std::string username;
    std::cout << "Enter event name: ";
    std::cin >> event_name;
    std::cout << "Enter username: ";
    std::cin >> username;

    Event* event = network.findEvent(event_name);
    User* user = network.findUser(username);

    if (event == nullptr || user == nullptr) {
        std::cout << "Event or user not found" << std::endl;
        return;
    }

    network.removeAttendance(user, event);

    std::cout << "Attendance removed." << std::endl;
}

void UserInterface::addMessage() {
    std::string sender_username;
    std::string receiver_username;
    std::string message;
    std::cout << "Enter sender username: ";
    std::cin >> sender_username;
    std::cout << "Enter receiver username: ";
    std::cin >> receiver_username;
    std::cout << "Enter message: ";
    std::cin >> message;

    User* sender = network.findUser(sender_username);
    User* receiver = network.findUser(receiver_username);

    if (sender == nullptr || receiver == nullptr) {
        std::cout << "User not found" << std::endl;
        return;
    }

    network.addMessage(Message(message, sender, receiver));

    std::cout << "Message sent." << std::endl;
}

void UserInterface::messagesOfUser() {
    std::string username;
    std::cout << "Enter username: ";
    std::cin >> username;

    User* user = network.findUser(username);

    if (user == nullptr) {
        std::cout << "User not found" << std::endl;
        return;
    }

    auto messages = network.getMessages(user);

    std::cout << "Messages of " << user->getUsername() << ":" << std::endl;
    for (auto& message : messages) {
        std::cout << message.getSender()->getUsername() << " -> " << message.getReceiver()->getUsername() << ": " << message.getText() << std::endl; 
    }
}

void UserInterface::messagesBetweenUsers() {
    std::string username1;
    std::string username2;
    std::cout << "Enter username 1: ";
    std::cin >> username1;
    std::cout << "Enter username 2: ";
    std::cin >> username2;

    User* user1 = network.findUser(username1);
    User* user2 = network.findUser(username2);

    if (user1 == nullptr || user2 == nullptr) {
        std::cout << "User not found" << std::endl;
        return;
    }

    auto messages = network.getMessages(user1, user2);

    std::cout << "Messages between " << user1->getUsername() << " and " << user2->getUsername() << ":" << std::endl;
    for (auto& message : messages) {
        std::cout << message.getSender()->getUsername() << " -> " << message.getReceiver()->getUsername() << ": " << message.getText() << std::endl; 
    }
}

