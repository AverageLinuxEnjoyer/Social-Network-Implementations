#include "../include/UI.h"

void UI::startMenu() {
    int option;
    do {
        cout << "1. Afisati toti utilizatorii." << endl;
        cout << "2. Arata utilizatorul." << endl;
        cout << "3. Adaugati utilizator." << endl;
        cout << "4. Actualizati utilizatorul." << endl;
        cout << "5. Eliminati utilizatorul." << endl;
        cout << "6. Arata prieteni." << endl;
        cout << "7. Adauga prieten." << endl;
        cout << "8. Sterge prieten." << endl;
        cout << "9. Afiseaza evenimentele la care a participat." << endl;
        cout << "10. Adaugati evenimentele la care poate participa." << endl;
        cout << "11. Eliminati evenimentul din lista utilizatorului." << endl;
        cout << "12. Afisati mesajele." << endl;
        cout << "13. Trimite mesaj." << endl;
        cout << "14. Afiseaza toate evenimentele." << endl;
        cout << "15. Afiseaza evenimentul." << endl;
        cout << "16. Adaugati un eveniment." << endl;
        cout << "17. Actualizati evenimentul." << endl;
        cout << "18. Eliminati evenimentul." << endl;
        cout << "19. Exit" << endl;
        cout << "Introduceti numarul optiunii: ";
        cin >> option;
        cout << endl;

        if (option == 1) {
            this->showAllUsers();
        } else if (option == 2) {
            this->showUser();
        } else if (option == 3) {
            this->addUser();
        } else if (option == 4) {
            this->updateUser();
        } else if (option == 5) {
            this->removeUser();
        } else if (option == 6) {
            this->showFriends();
        } else if (option == 7) {
            this->addFriend();
        } else if (option == 8) {
            this->removeFriend();
        } else if (option == 9) {
            this->showAttendedEvents();
        } else if (option == 10) {
            this->addAttendedEvent();
        } else if (option == 11) {
            this->removeAttendedEvent();
        } else if (option == 12) {
            this->showMessages();
        } else if (option == 13) {
            this->sendMessage();
        } else if (option == 14) {
            this->showAllEvents();
        } else if (option == 15) {
            this->showEvent();
        } else if (option == 16) {
            this->addEvent();
        } else if (option == 17) {
            this->updateEvent();
        } else if (option == 18) {
            this->removeEvent();
        } else if (option == 19) {
            this->exit();
            return;
        } else {
            cout << "Optiune nevalida! Incearca din nou." << endl;
        }
        cout << endl;
    } while (true);
}

void UI::showAllUsers() {
    vector<User> users = this->userService.getUsers();
    for (User user : users) {
        cout << "ID: " << user.getId() << ", nume: " << user.getName() << ", email: " << user.getEmail() << ", parola: " << user.getPassword() << ", telefon: " << user.getPhone() << ", tara: " << user.getCity() << ", oras: " << user.getState() << endl;
    }
}

void UI::showUser() {
    int id;
    cout << "Introduceti ID-ul utilizatorului: ";
    cin >> id;
    cout << endl;

    try {
        User user = this->userService.getUser(id);
        cout << "ID: " << user.getId() << ", nume: " << user.getName() << ", email: " << user.getEmail() << ", parola: " << user.getPassword() << ", telefon: " << user.getPhone() << ", tara: " << user.getCity() << ", oras: " << user.getState() << endl;
    } catch (const char* msg) {
        cout << msg << endl;
        return;
    }
}

void UI::addUser() {
    int id;
    string name, email, password, phone, city, state;
    cout << "Introduceti ID-ul utilizatorului: ";
    cin >> id;
    cout << "Introduceti numele utilizatorului: ";
    cin >> name;
    cout << "Introduceti emailul utilizatorului: ";
    cin >> email;
    cout << "Introduceti parola utilizatorului: ";
    cin >> password;
    cout << "Introduceti telefonul utilizatorului: ";
    cin >> phone;
    cout << "Introduceti tara utilizatorului: ";
    cin >> city;
    cout << "Introduceti orasul utilizatorului: ";
    cin >> state;
    cout << endl;

    try {
        this->userService.addUser(User(id, name, email, password, phone, city, state));
        cout << "Utilizator adaugat cu succes!" << endl;
    } catch (const char* msg) {
        cout << msg << endl;
        return;
    }
}

void UI::updateUser() {
    int id;
    string name, email, password, phone, city, state;
    cout << "Introduceti ID-ul utilizatorului: ";
    cin >> id;
    cout << "Introduceti un nou nume de utilizator: ";
    cin >> name;
    cout << "Introduceti un nou email: ";
    cin >> email;
    cout << "Introduceti o noua parola: ";
    cin >> password;
    cout << "Introduceti un nou numar de telefon: ";
    cin >> phone;
    cout << "Introduceti o noua tara: ";
    cin >> city;
    cout << "Introduceti un nou oras: ";
    cin >> state;
    cout << endl;

    try {
        this->userService.updateUser(id, User(id, name, email, password, phone, city, state));
        cout << "Utilizatorul a fost actualizat cu succes!" << endl;
    } catch (const char* msg) {
        cout << msg << endl;
        return;
    }
}

void UI::removeUser() {
    int id;
    cout << "Introduceti ID-ul utilizatorului: ";
    cin >> id;
    cout << endl;

    try {
        this->userService.removeUser(id);
        cout << "Utilizatorul a fost sters cu succes!" << endl;
    } catch (const char* msg) {
        cout << msg << endl;
        return;
    }
}

void UI::showFriends() {
    int id;
    cout << "Introduceti ID-ul utilizatorului: ";
    cin >> id;
    cout << endl;

    try {
        List<int> friends = this->userService.getFriends(id);
        for (int i = 0; i < this->userService.getFriends(id).getSize(); i++) {
            User user = this->userService.getUser(friends.get(i));
            cout << "ID: " << user.getId() << ", nume: " << user.getName() << ", email: " << user.getEmail() << ", parola: " << user.getPassword() << ", telefon: " << user.getPhone() << ", tara: " << user.getCity() << ", oras: " << user.getState() << endl;
        }
    } catch (const char* msg) {
        cout << msg << endl;
        return;
    }
}

void UI::addFriend() {
    int id, friendId;
    cout << "Introduceti ID-ul utilizatorului: ";
    cin >> id;
    cout << "Introduceti ID-ul prietenului: ";
    cin >> friendId;
    cout << endl;

    try {
        this->userService.addFriend(id, friendId);
        cout << "Prieten adaugat cu succes!" << endl;
    } catch (const char* msg) {
        cout << msg << endl;
        return;
    }
}

void UI::removeFriend() {
    int id, friendId;
    cout << "Introduceti ID-ul utilizatorului: ";
    cin >> id;
    cout << "Introduceti ID-ul prietenului: ";
    cin >> friendId;
    cout << endl;

    try {
        this->userService.removeFriend(id, friendId);
        cout << "Prieten sters cu succes!" << endl;
    } catch (const char* msg) {
        cout << msg << endl;
        return;
    }
}

void UI::showAttendedEvents() {
    int id;
    cout << "Introduceti ID-ul utilizatorului: ";
    cin >> id;
    cout << endl;

    try {
        List<int> attendedEvents = this->userService.getEvents(id);
        for (int i = 0; i < attendedEvents.getSize(); i++) {
            Event event = this->eventService.getEvent(attendedEvents.get(i));
            cout << "ID: " << event.getId() << ", nume: " << event.getName() << ", descrire: " << event.getDescription() << ", data: " << event.getDate() << ", locatie: " << event.getLocation() << ", pret: " << endl;
        }
    } catch (const char* msg) {
        cout << msg << endl;
        return;
    }
}

void UI::showMessages() {
    int id1, id2;
    cout << "Introduceti ID-ul utilizatorului 1: ";
    cin >> id1;

    cout << "Introduceti ID-ul utilizatorului 2: ";
    cin >> id2;

    cout << endl;

    try {
        List<Message> messages = this->userService.getMessages(id1, id2);
        for (int i = 0; i < messages.getSize(); i++) {
            Message message = messages.get(i);
            User sender = this->userService.getUser(message.senderId);
            User receiver = this->userService.getUser(message.receiverId);

            cout << "Mesaj de la " << sender.getName() << " pentru " << receiver.getName() << ": " << message.message << endl;
        }
    } catch (const char* msg) {
        cout << msg << endl;
        return;
    }
    
}

void UI::sendMessage() {
    int id1, id2;
    string message;
    cout << "Introduceti ID-ul utilizatorului 1: ";
    cin >> id1;

    cout << "Introduceti ID-ul utilizatorului 2: ";
    cin >> id2;

    cout << "Introduceti mesajul: ";
    cin.ignore();
    getline(cin, message);
    cout << endl;

    try {
        this->userService.sendMessage({id1, id2, message});
        cout << "Mesaj trimis cu succes!" << endl;
    } catch (const char* msg) {
        cout << msg << endl;
        return;
    }
}

void UI::addAttendedEvent() {
    int id, eventId;
    cout << "Introduceti ID-ul utilizatorului: ";
    cin >> id;
    cout << "Introduceti ID-ul evenimentului: ";
    cin >> eventId;
    cout << endl;

    try {
        this->userService.addEvent(id, eventId);
        this->eventService.addAttendee(eventId, id);
        cout << "Eveniment adaugat cu succes!" << endl;
    } catch (const char* msg) {
        cout << msg << endl;
        return;
    }
}

void UI::removeAttendedEvent() {
    int id, eventId;
    cout << "Introduceti ID-ul utilizatorului: ";
    cin >> id;
    cout << "Introduceti ID-ul enenimentului: ";
    cin >> eventId;
    cout << endl;

    try {
        this->userService.removeEvent(id, eventId);
        this->eventService.removeAttendee(eventId, id);
        cout << "Eveniment sters cu succes!" << endl;
    } catch (const char* msg) {
        cout << msg << endl;
        return;
    }
}

void UI::showAllEvents() {
    vector<Event> events = this->eventService.getEvents();
    for (Event event : events) {
        cout << "ID: " << event.getId() << ", nume: " << event.getName() << ", descriere: " << event.getDescription() << ", data: " << event.getDate() << ", locatie: " << event.getLocation() << endl;
    }
}

void UI::showEvent() {
    int id;
    cout << "Introduceti ID-ul enenimentului: ";
    cin >> id;
    cout << endl;

    try {
        Event event = this->eventService.getEvent(id);
        cout << "ID: " << event.getId() << ", nume: " << event.getName() << ", descriere: " << event.getDescription() << ", data: " << event.getDate() << ", locatie: " << event.getLocation() << endl;
    } catch (const char* msg) {
        cout << msg << endl;
        return;
    }
}

void UI::addEvent() {
    int id;
    string name, description, date, location;
    cout << "Introduceti ID-ul enenimentului: ";
    cin >> id;
    cout << "Introduceti numele enenimentului: ";
    cin >> name;
    cout << "Introduceti descrierea enenimentului: ";
    cin >> description;
    cout << "Introduceti data enenimentului: ";
    cin >> date;
    cout << "Introduceti locatia enenimentului: ";
    cin >> location;
    cout << endl;

    try {
        this->eventService.addEvent(Event(id, name, description, date, location));
        cout << "Eveniment adaugat cu succes!" << endl;
    } catch (const char* msg) {
        cout << msg << endl;
        return;
    }
}

void UI::updateEvent() {
    int id;
    string name, description, date, location;
    cout << "Introduceti ID-ul enenimentului: ";
    cin >> id;
    cout << "Introduceti un nou nume de eveniment: ";
    cin >> name;
    cout << "Introduceti o noua descriere a evenimentului: ";
    cin >> description;
    cout << "Introduceti noua data pentru eveniment: ";
    cin >> date;
    cout << "Introduceti o noua locatie pentru eveniment: ";
    cin >> location;
    cout << endl;

    try {
        this->eventService.updateEvent(id, Event(id, name, description, date, location));
        cout << "Evenimentul a fost actualizat cu succes!" << endl;
    } catch (const char* msg) {
        cout << msg << endl;
        return;
    }
}

void UI::removeEvent() {
    int id;
    cout << "Introduceti ID-ul enenimentului: ";
    cin >> id;
    cout << endl;

    try {
        this->eventService.removeEvent(id);
        cout << "Evenimentul a fost eliminat cu succes!" << endl;
    } catch (const char* msg) {
        cout << msg << endl;
        return;
    }
}

void UI::showAttendees() {
    int id;
    cout << "Introduceti ID-ul enenimentului: ";
    cin >> id;
    cout << endl;

    try {
        List<int> attendees = this->eventService.getAttendees(id);
        for (int i = 0; i < this->eventService.getAttendees(id).getSize(); i++) {
            User user = this->userService.getUser(attendees.get(i));
            cout << "ID: " << user.getId() << ", nume: " << user.getName() << ", email: " << user.getEmail() << ", parola: " << user.getPassword() << ", telefon: " << user.getPhone() << ", tara: " << user.getCity() << ", oras: " << user.getState() << endl;
        }
    } catch (const char* msg) {
        cout << msg << endl;
        return;
    }
}

void UI::exit() {
    
}
