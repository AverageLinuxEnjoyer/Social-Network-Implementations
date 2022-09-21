#include "../include/ui.h"
#include <iostream>

UI::UI(Service &service)
    : userService(service)
{}

void UI::run() {
    int option = 0;

    while(true) {
        std::cout << "1. User menu" << std::endl;
        std::cout << "2. Event menu" << std::endl;
        std::cout << "3. Exit" << std::endl;

        std::cin >> option;

        switch(option) {
            case 1:
                user_menu();
                break;
            case 2:
                event_menu();
                break;
            case 3:
                return;
            default:
                std::cout << "Optiune invalida." << std::endl;
        }
    }
}

void UI::user_menu() {
    int option;

    while(true) {
        std::cout << "0. Afisare utilizatori" << std::endl;
        std::cout << "1. Adaugare utilizator" << std::endl;
        std::cout << "2. Actualizare utilizator" << std::endl;
        std::cout << "3. Stergere utilizator" << std::endl;
        std::cout << "4. Adaugare prieten" << std::endl;
        std::cout << "5. Stergere prieten" << std::endl;
        std::cout << "6. Afisare prieteni" << std::endl;
        std::cout << "7. Trimitere mesaj" << std::endl;
        std::cout << "8. Afisare mesaje" << std::endl;
        std::cout << "9. Inapoi" << std::endl;
        std::cout << "Optiunea: ";
        std::cin >> option;
        std::cout << std::endl;

        switch(option) {
            case 0:
                printUsers();
                break;
            case 1:
                add_user_menu();
                break;
            case 2:
                update_user_menu();
                break;
            case 3:
                remove_user_menu();
                break;
            case 4:
                add_friendship_menu();
                break;
            case 5:
                remove_friendship_menu();
                break;
            case 6:
                print_friends();
                break;
            case 7:
                send_message_menu();
                break;
            case 8:
                print_messages();
                break;
            case 9:
                return;
            default:
                std::cout << "Optiune invalida." << std::endl;
                break;
        }
    }
}

void UI::event_menu() {
    int option;

    while(true) {
        std::cout << "0. Afisare evenimente" << std::endl;
        std::cout << "1. Adaugare eveniment" << std::endl;
        std::cout << "2. Actualizare eveniment" << std::endl;
        std::cout << "3. Stergere eveniment" << std::endl;
        std::cout << "4. Adaugare utilizator interesat" << std::endl;
        std::cout << "5. Afisare utilizatori interesati" << std::endl;
        std::cout << "6. Inapoi" << std::endl;
        std::cout << "Optiunea: ";
        std::cin >> option;

        switch(option) {
            case 0:
                print_events_menu();
                break;
            case 1:
                add_event_menu();
                break;
            case 2:
                update_event_menu();
                break;
            case 3:
                remove_event_menu();
                break;
            case 4:
                add_interested_user_menu();
                break;
            case 5:
                print_interested_users();
                break;
            case 6:
                return;
            default:
                std::cout << "Optiune invalida." << std::endl;
                break;
        }
    }
}


void UI::printUsers() {
    List<User*> users = userService.getUsers();
    for (int i = 0; i < users.size(); i++) {
        std::cout << users[i]->getUsername() << " " << users[i]->getAge() << " " << users[i]->getEmail() << std::endl;
    }
}

void UI::add_user_menu() {
    do {
        std::cout << "Nume de utilizator: ";
        std::string username;
        std::cin >> username;

        std::cout << "Varsta: ";
        int age;
        std::cin >> age;

        std::cout << "Email: ";
        std::string email;
        std::cin >> email;

        if (userService.addUser(username, age, email)) {
            std::cout << "Utilizator adaugat cu succes.\n";
            return;
        } else {
            std::cout << "Acest nume de utilizator e deja folosit. Incearca din nou\n";
        }
    } while(true);
}

void UI::update_user_menu() {
    do {
        std::cout << "Nume de utilizator: ";
        std::string username;
        std::cin >> username;

        std::cout << "Nume de utilizator nou: ";
        std::string newUsername;
        std::cin >> newUsername;

        std::cout << "Varsta noua: ";
        int newAge;
        std::cin >> newAge;

        std::cout << "Email nou: ";
        std::string newEmail;
        std::cin >> newEmail;

        if (userService.updateUser(username, newUsername, newAge, newEmail)) {
            std::cout << "Utilizatorul a fost actualizat cu succes.\n";
            return;
        } else {
            std::cout << "Utilizatorul nu exista. Incearca din nou\n";
        }
    } while(true);
}

void UI::remove_user_menu() {
    do {
        std::cout << "Nume de utilizator: ";
        std::string username;
        std::cin >> username;

        if (userService.removeUser(username)) {
            std::cout << "Utilizator sters cu succes.\n";
            return;
        } else {
            std::cout << "Utilizatorul nu exista.\n";
            return;
        }
    } while(true);
}

void UI::add_friendship_menu() {
    do {
        std::cout << "Nume de utilizator: ";
        std::string username;
        std::cin >> username;

        std::cout << "Nume de utilizator prieten: ";
        std::string friendUsername;
        std::cin >> friendUsername;

        if (userService.addFriendship(username, friendUsername)) {
            std::cout << "Prieten adaugat cu succes.\n";
            return;
        } else {
            std::cout << "Unul din utilizatori nu exista sau sunt prieteni deja. Incearca din nou.\n";
        }
    } while(true);
}

void UI::remove_friendship_menu() {
    do {
        std::cout << "Nume de utilizator: ";
        std::string username;
        std::cin >> username;

        std::cout << "Nume de utilizator prieten: ";
        std::string friendUsername;
        std::cin >> friendUsername;

        if (userService.removeFriendship(username, friendUsername)) {
            std::cout << "Prieten sters cu succes.\n";
            return;
        } else {
            std::cout << "Unul din utilizatori nu exista sau nu sunt prieteni. Incearca din nou.\n";
        }
    } while(true);
}

void UI::print_friends() {
    do {
        std::cout << "Nume de utilizator: ";
        std::string username;
        std::cin >> username;

        User* user = nullptr;
        auto users = userService.getUsers();
        // find the user
        for (int i = 0; i < users.size(); i++) {
            if (users[i]->getUsername() == username) {
                user = users[i];
                break;
            }
        }

        if (user == nullptr) {
            std::cout << "Utilizatorul nu exista. Incearca din nou.\n";
            continue;
        }

        auto friends = user->getFriends();

        for (int i = 0; i < friends.size(); i++) {
            std::cout << friends[i].getUser2()->getUsername() << std::endl;
        }

        return;
    } while(true);
}

void UI::send_message_menu() {
    do {
        std::cout << "Nume de utilizator: ";
        std::string sender;
        std::cin >> sender;

        std::cout << "Nume de utilizator al destinatarului: ";
        std::string receiver;
        std::cin >> receiver;

        std::cout << "Mesaj: ";
        std::string message;
        std::cin.ignore();
        std::getline(std::cin, message);

        if (userService.sendMessage(sender, receiver, message)) {
            std::cout << "Mesaj trimis cu succes.\n";
            return;
        } else {
            std::cout << "Unul din utilizatori nu exista. Incearca din nou.\n";
        }
    } while(true);
}

void UI::print_messages() {
    do {
        std::cout << "Nume de utilizator: ";
        std::string username;
        std::cin >> username;

        User* user = nullptr;
        for(int i = 0; i < userService.getUsers().size(); i++)
            if(userService.getUsers()[i]->getUsername() == username)
                user = userService.getUsers()[i];

        if (user == nullptr) {
            std::cout << "Utilizatorul nu exista. Incearca din nou.\n";
            continue;
        }

        std::cout << "Mesaje:\n";
        for (int i = 0; i < user->getMessages().size(); i++) {
            auto sender = user->getMessages()[i].sender;
            auto receiver = user->getMessages()[i].receiver;
            std::cout << sender->getUsername() << " -> " <<
                receiver->getUsername() << ": " <<
                user->getMessages()[i].content << std::endl;
        }

        std::cout << "\n";
        break;
    } while(true);
}

void UI::print_events_menu() {
    List<Event> events = userService.getEvents();
    
    for (int i = 0; i < events.size(); i++) {
        std::cout << events[i].getName()  <<
            ", data: " << events[i].getDate() <<
            ", locatie: " << events[i].getLocation() <<
            ", descriere: " << events[i].getDescription() <<
            ", useri interesati: " << events[i].getInterested().size() <<
        std::endl;
    }
}

void UI::add_event_menu() {
    do {
        std::cout << "Nume: ";
        std::string name;
        std::cin >> name;

        std::cout << "Data: ";
        std::string date;
        std::cin >> date;

        std::cout << "Locatie: ";
        std::string location;
        std::cin >> location;

        std::cin.ignore();
        std::cout << "Descriere: ";
        std::string description;
        std::getline(std::cin, description);

        if (userService.addEvent(name, location, description, date)) {
            std::cout << "Eveniment adaugat cu succes.\n";
            return;
        } else {
            std::cout << "Exista deja un eveniment cu acest nume. Incearca din nou.\n";
        }
    } while(true);
}

void UI::update_event_menu() {
    do {
        std::cout << "Numele evenimentului: ";
        std::string name;
        std::cin >> name;

        std::cout << "Numele nou al evenimentului: ";
        std::string newName;
        std::cin >> newName;

        std::cout << "Data noua: ";
        std::string newDate;
        std::cin >> newDate;

        std::cout << "Locatia noua: ";
        std::string newLocation;
        std::cin >> newLocation;

        std::cout << "Descrierea noua: ";
        std::string newDescription;
        std::getline(std::cin, newDescription);

        if (userService.updateEvent(name, newName, newDate, newLocation, newDescription)) {
            std::cout << "Eveniment actualizat cu succes.\n";
            return;
        } else {
            std::cout << "Nu exista un eveniment cu acest nume. Incearca din nou.\n";
        }
    } while(true);

}

void UI::remove_event_menu() {
    do {
        std::cout << "Numele evenimentului: ";
        std::string name;
        std::cin >> name;

        if (userService.removeEvent(name)) {
            std::cout << "Eveniment sters cu succes.\n";
            return;
        } else {
            std::cout << "Nu exista un eveniment cu acest nume. Incearca din nou.\n";
        }
    } while(true);
}

void UI::add_interested_user_menu() {
    do {
        std::cout << "Nume de utilizator: ";
        std::string username;
        std::cin >> username;

        std::cout << "Numele evenimentului: ";
        std::string eventName;
        std::cin.ignore();
        std::getline(std::cin, eventName);

        if (userService.addInterestedUser(eventName, username)) {
            std::cout << "Utilizatorul interesat adaugat cu succes.\n";
            return;
        } else {
            std::cout << "Evenimentul sau utilizatorul nu exista. Incearca din nou.\n";
        }
    } while(true);
}

void UI::print_interested_users() {
    do {
        std::cout << "Numele evenimentului: ";
        std::string eventName;
        std::cin.ignore();
        std::getline(std::cin, eventName);

        Event event;
        List<Event> events = userService.getEvents();
        for (int i = 0; i < userService.getEvents().size(); i++) {
            if (userService.getEvents()[i].getName() == eventName) {
                event = userService.getEvents()[i];
                break;
            }
        }

        if (event.getName() == "") {
            std::cout << "Nu exista un eveniment cu acest nume. Incearca din nou.\n";
            continue;
        }

        std::cout << "Utilizatorii interesati:\n";
        for (int i = 0; i < event.getInterested().size(); i++) {
            User* interested = event.getInterested()[i];
            std::cout << interested->getUsername() << "\n";
        }
        break;

    } while(true);
}


