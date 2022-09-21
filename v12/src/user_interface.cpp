#include "../include/user_interface.h"
#include <iostream>
#include <stdexcept>

void UserInterface::run() {
    while (true) {
        std::cout << "1. Show all users" << std::endl;
        std::cout << "2. Show user" << std::endl;
        std::cout << "3. Add user" << std::endl;
        std::cout << "4. Update user" << std::endl;
        std::cout << "5. Remove user" << std::endl;
        std::cout << "6. Add friend" << std::endl;
        std::cout << "7. Remove friend" << std::endl;
        std::cout << "8. Show friends" << std::endl;
        std::cout << "9. Add message" << std::endl;
        std::cout << "10. Show messages" << std::endl;
        std::cout << "11. Delete chat" << std::endl;
        std::cout << "12. Show all events" << std::endl;
        std::cout << "13. Show event" << std::endl;
        std::cout << "14. Add event" << std::endl;
        std::cout << "15. Update event" << std::endl;
        std::cout << "16. Remove event" << std::endl;
        std::cout << "17. Add participant" << std::endl;
        std::cout << "18. Remove participant" << std::endl;
        std::cout << "19. Show participants" << std::endl;
        std::cout << "0. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        int choice;
        std::cin >> choice;

        switch (choice) {
            case 1:
                show_all_users_menu();
                break;
            case 2:
                show_user_menu();
                break;
            case 3:
                add_user_menu();
                break;
            case 4:
                update_user_menu();
                break;
            case 5:
                remove_user_menu();
                break;
            case 6:
                add_friend_menu();
                break;
            case 7:
                remove_friend_menu();
                break;
            case 8:
                show_friends_menu();
                break;
            case 9:
                add_message_menu();
                break;
            case 10:
                show_messages_menu();
                break;
            case 11:
                delete_chat_menu();
                break;
            case 12:
                show_all_events_menu();
                break;
            case 13:
                show_event_menu();
                break;
            case 14:
                add_event_menu();
                break;
            case 15:
                update_event_menu();
                break;
            case 16:
                remove_event_menu();
                break;
            case 17:
                add_participant_menu();
                break;
            case 18:
                remove_participant_menu();
                break;
            case 19:
                show_participants_menu();
                break;
            case 0:
                return;
            default:
                std::cout << "Invalid choice!" << std::endl;
                break;
        } 
    }
}

void UserInterface::show_all_users_menu() {
    std::cout << "All users: " << std::endl;
    List<User> all = user_service.getAll();
    
    for (int i = 0; i < all.getSize(); i++) {
        std::cout << all[i].getCode() << " " << all[i].getName() << " " << all[i].getAge() << " " << all[i].getGender()<< std::endl;
    }

    std::cout << std::endl;
}

void UserInterface::show_user_menu() {
    std::cout << "Enter user code: ";
    int code;
    std::cin >> code;

    try {
        User user = user_service.get(code);
        std::cout << user.getCode() << " " << user.getName() << " " << user.getAge() << " " << user.getGender() << std::endl;
    } catch (std::runtime_error& e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << std::endl;
}

void UserInterface::add_user_menu() {
    std::cout << "Enter user code: ";
    int code;
    std::cin >> code;

    std::cout << "Enter user name: ";
    std::string name;
    std::cin >> name;

    std::cout << "Enter user age: ";
    int age;
    std::cin >> age;

    std::cout << "Enter user gender: ";
    std::string gender;
    std::cin >> gender;

    try {
        User user(code, name, age, gender);
        user_service.add(user);

        std::cout << "User added succesfully.\n"; 
    } catch (std::runtime_error& e) {
        std::cout << e.what() << std::endl;
    }
}

void UserInterface::update_user_menu() {
    std::cout << "Enter user code: ";
    int code;
    std::cin >> code;

    std::cout << "Enter new user name: ";
    std::string name;
    std::cin >> name;

    std::cout << "Enter new user age: ";
    int age;
    std::cin >> age;

    std::cout << "Enter new user gender: ";
    std::string gender;
    std::cin >> gender;

    try {
        User user(code, name, age, gender);
        user_service.update(code, user);

        std::cout << "User updated succesfully.\n"; 
    } catch (std::runtime_error& e) {
        std::cout << e.what() << std::endl;
    }
}

void UserInterface::remove_user_menu() {
    std::cout << "Enter user code: ";
    int code;
    std::cin >> code;

    try {
        user_service.remove(code);

        std::cout << "User removed succesfully.\n"; 
    } catch (std::runtime_error& e) {
        std::cout << e.what() << std::endl;
    }
}

void UserInterface::add_friend_menu() {
    std::cout << "Enter user code: ";
    int code;
    std::cin >> code;

    std::cout << "Enter friend code: ";
    int friend_code;
    std::cin >> friend_code;

    try {
        user_service.addFriend(code, friend_code);

        std::cout << "Friend added succesfully.\n"; 
    } catch (std::runtime_error& e) {
        std::cout << e.what() << std::endl;
    }
}

void UserInterface::remove_friend_menu() {
    std::cout << "Enter user code: ";
    int code;
    std::cin >> code;

    std::cout << "Enter friend code: ";
    int friend_code;
    std::cin >> friend_code;

    try {
        user_service.removeFriend(code, friend_code);

        std::cout << "Friend removed succesfully.\n"; 
    } catch (std::runtime_error& e) {
        std::cout << e.what() << std::endl;
    }
}

void UserInterface::show_friends_menu() {
    std::cout << "Enter user code: ";
    int code;
    std::cin >> code;

    try {
        List<User> friends = user_service.getFriends(code);

        for (int i = 0; i < friends.getSize(); i++) {
            std::cout << friends[i].getCode() << " " << friends[i].getName() << " " << friends[i].getAge() << " " << friends[i].getGender() << std::endl;
        }
    } catch (std::runtime_error& e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << std::endl;
}

void UserInterface::add_message_menu() {
    std::cout << "Enter user code: ";
    int code;
    std::cin >> code;

    std::cout << "Enter friend code: ";
    int friend_code;
    std::cin >> friend_code;

    std::cout << "Enter message: ";
    std::string message;
    std::cin.ignore();
    std::getline(std::cin, message);

    try {
        user_service.add_message(code, friend_code, message);

        std::cout << "Message added succesfully.\n"; 
    } catch (std::runtime_error& e) {
        std::cout << e.what() << std::endl;
    }
}

void UserInterface::show_messages_menu() {
    std::cout << "Enter user code: ";
    int code;
    std::cin >> code;

    std::cout << "Friend code: ";
    int friend_code;
    std::cin >> friend_code;

    try {
        auto messages = user_service.get_messages(code, friend_code);

        for (int i = 0; i < messages.getSize(); i++) {
            User u1 = user_service.get(std::get<0>(messages[i]));
            User u2 = user_service.get(std::get<1>(messages[i]));

            std::cout << u1.getName() << " " << u2.getName() << " " << std::get<2>(messages[i]) << std::endl;
        }
    } catch (std::runtime_error& e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << std::endl;
}

void UserInterface::delete_chat_menu() {
    std::cout << "Enter user code: ";
    int code;
    std::cin >> code;

    std::cout << "Enter friend code: ";
    int friend_code;
    std::cin >> friend_code;

    try {
        user_service.delete_chat(code, friend_code);

        std::cout << "Chat deleted succesfully.\n"; 
    } catch (std::runtime_error& e) {
        std::cout << e.what() << std::endl;
    }
}

void UserInterface::show_all_events_menu() {
    std::cout << "All events:\n";

    List<Event> events = event_service.getAll();

    for (int i = 0; i < events.getSize(); i++) {
        std::cout << events[i].getCode() << " " << events[i].getName() << " " << events[i].organizerId() << " " << events[i].getType() << std::endl;
    }
}

void UserInterface::show_event_menu() {
    std::cout << "Enter event code: ";
    int code;
    std::cin >> code;

    try {
        Event event = event_service.get(code);

        std::cout << event.getCode() << " " << event.getName() << " " << event.organizerId() << " " << event.getType() << std::endl;
    } catch (std::runtime_error& e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << std::endl;
}

void UserInterface::add_event_menu() {
    std::cout << "Enter event code: ";
    int code;
    std::cin >> code;

    std::cout << "Enter event name: ";
    std::string name;
    std::cin.ignore();
    std::getline(std::cin, name);

    std::cout << "Enter event organizer code: ";
    int organizer_code;
    std::cin >> organizer_code;

    try {
        user_service.get(organizer_code);
    } catch (std::runtime_error& e) {
        std::cout << e.what() << std::endl;
        return;
    }

    std::cout << "Enter event type: ";
    std::string type;
    std::cin.ignore();
    std::getline(std::cin, type);

    try {
        Event event(code, name, organizer_code, type);
        event_service.add(event);

        std::cout << "Event added succesfully.\n"; 
    } catch (std::runtime_error& e) {
        std::cout << e.what() << std::endl;
    }
}

void UserInterface::update_event_menu() {
    std::cout << "Enter event code: ";
    int code;
    std::cin >> code;

    std::cout << "Enter new event name: ";
    std::string name;
    std::cin.ignore();
    std::getline(std::cin, name);

    std::cout << "Enter new event organizer code: ";
    int organizer_code;
    std::cin >> organizer_code;

    std::cout << "Enter new event type: ";
    std::string type;
    std::cin.ignore();
    std::getline(std::cin, type);

    try {
        Event event(code, name, organizer_code, type);
        event_service.update(code, event);

        std::cout << "Event updated succesfully.\n"; 
    } catch (std::runtime_error& e) {
        std::cout << e.what() << std::endl;
    }
}

void UserInterface::remove_event_menu() {
    std::cout << "Enter event code: ";
    int code;
    std::cin >> code;

    try {
        event_service.remove(code);

        std::cout << "Event removed succesfully.\n"; 
    } catch (std::runtime_error& e) {
        std::cout << e.what() << std::endl;
    }
}

void UserInterface::add_participant_menu() {
    std::cout << "Enter event code: ";
    int code;
    std::cin >> code;

    std::cout << "Enter participant code: ";
    int participant_code;
    std::cin >> participant_code;

    try {
        user_service.get(participant_code);
    } catch (std::runtime_error& e) {
        std::cout << e.what() << std::endl;
        return;
    }

    try {
        event_service.addParticipant(code, participant_code);

        std::cout << "Participant added succesfully.\n"; 
    } catch (std::runtime_error& e) {
        std::cout << e.what() << std::endl;
    }
}

void UserInterface::remove_participant_menu() {
    std::cout << "Enter event code: ";
    int code;
    std::cin >> code;

    std::cout << "Enter participant code: ";
    int participant_code;
    std::cin >> participant_code;

    try {
        event_service.removeParticipant(code, participant_code);

        std::cout << "Participant removed succesfully.\n"; 
    } catch (std::runtime_error& e) {
        std::cout << e.what() << std::endl;
    }
}

void UserInterface::show_participants_menu() {
    std::cout << "Enter event code: ";
    int code;
    std::cin >> code;

    try {
        List<int> participants = event_service.getParticipants(code);

        for (int i = 0; i < participants.getSize(); i++) {
            User user = user_service.get(participants[i]);
            std::cout << user.getCode() << " " << user.getName() << " " << user.getAge() << " " << user.getGender() << "\n";
        }
    } catch (std::runtime_error& e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << std::endl;
}






