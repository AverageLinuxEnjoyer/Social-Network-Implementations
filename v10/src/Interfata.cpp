#include "../include/Interfata.h"
#include <iostream>
#include <stdexcept>

void Interfata::start() {
    while (true) {
        std::cout << "1. Show all users" << std::endl;
        std::cout << "2. Show user" << std::endl;
        std::cout << "3. Add user" << std::endl;
        std::cout << "4. Update user" << std::endl;
        std::cout << "5. stergere user" << std::endl;
        std::cout << "6. Add friend" << std::endl;
        std::cout << "7. stergere friend" << std::endl;
        std::cout << "8. Show prieteni" << std::endl;
        std::cout << "9. Add message" << std::endl;
        std::cout << "10. Show messages" << std::endl;
        std::cout << "11. Delete chat" << std::endl;
        std::cout << "12. Show all events" << std::endl;
        std::cout << "13. Show event" << std::endl;
        std::cout << "14. Add event" << std::endl;
        std::cout << "15. Update event" << std::endl;
        std::cout << "16. stergere event" << std::endl;
        std::cout << "17. Add participant" << std::endl;
        std::cout << "18. stergere participant" << std::endl;
        std::cout << "19. Show participanti" << std::endl;
        std::cout << "0. Exit" << std::endl;
        std::cout << "Enter your opt: ";
        int opt;
        std::cin >> opt;

        
        if (opt == 0) {
            return;
        } else if (opt == 1) {
            afisare_utilizatori();
        } else if (opt == 2) {
            afisare_utilizator();
        } else if (opt == 3) {
            adaugare_utilizator();
        } else if (opt == 4) {
            update_utilizator();
        } else if (opt == 5) {
            stergere_utilizator();
        } else if (opt == 6) {
            adaugare_prieten();
        } else if (opt == 7) {
            stergere_prieten();
        } else if (opt == 8) {
            afisare_prieteni();
        } else if (opt == 9) {
            adaugare_mesaj();
        } else if (opt == 10) {
            afisare_mesaj();
        } else if (opt == 11) {
            stergere_mesaje();
        } else if (opt == 12) {
            afisare_evenimente();
        } else if (opt == 13) {
            afisare_eveniment();
        } else if (opt == 14) {
            adaugare_eveniment();
        } else if (opt == 15) {
            modificare_eveniment();
        } else if (opt == 16) {
            stergere_eveniment();
        } else if (opt == 17) {
            adaugare_participant();
        } else if (opt == 18) {
            stergere_participant();
        } else if (opt == 19) {
            afisare_participanti();
        } else {
            std::cout << "Invalid opt!" << std::endl;
        }
    }
}

void Interfata::afisare_utilizatori() {
    std::cout << "All users: " << std::endl;
    Lista<Utilizator> all = serviceUtilizatori.getAll();
    
    for (int i = 0; i < all.getNrElems(); i++) {
        std::cout << all[i].getId() << " " << all[i].getNume() << " " << all[i].getVarsta() << " " << all[i].getStatus()<< std::endl;
    }

    std::cout << std::endl;
}

void Interfata::afisare_utilizator() {
    std::cout << "Enter user id: ";
    int id;
    std::cin >> id;

    try {
        Utilizator user = serviceUtilizatori.get(id);
        std::cout << user.getId() << " " << user.getNume() << " " << user.getVarsta() << " " << user.getStatus() << std::endl;
    } catch (std::runtime_error& e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << std::endl;
}

void Interfata::adaugare_utilizator() {
    std::cout << "Enter user id: ";
    int id;
    std::cin >> id;

    std::cout << "Enter user nume: ";
    std::string nume;
    std::cin >> nume;

    std::cout << "Enter user varsta: ";
    int varsta;
    std::cin >> varsta;

    std::cout << "Enter user status: ";
    std::string status;
    std::cin >> status;

    try {
        Utilizator user(id, nume, varsta, status);
        serviceUtilizatori.adaugare(user);

        std::cout << "Utilizator added succesfully.\n"; 
    } catch (std::runtime_error& e) {
        std::cout << e.what() << std::endl;
    }
}

void Interfata::update_utilizator() {
    std::cout << "Enter user id: ";
    int id;
    std::cin >> id;

    std::cout << "Enter new user nume: ";
    std::string nume;
    std::cin >> nume;

    std::cout << "Enter new user varsta: ";
    int varsta;
    std::cin >> varsta;

    std::cout << "Enter new user status: ";
    std::string status;
    std::cin >> status;

    try {
        Utilizator user(id, nume, varsta, status);
        serviceUtilizatori.modificare(id, user);

        std::cout << "Utilizator updated succesfully.\n"; 
    } catch (std::runtime_error& e) {
        std::cout << e.what() << std::endl;
    }
}

void Interfata::stergere_utilizator() {
    std::cout << "Enter user id: ";
    int id;
    std::cin >> id;

    try {
        serviceUtilizatori.stergere(id);

        std::cout << "Utilizator removed succesfully.\n"; 
    } catch (std::runtime_error& e) {
        std::cout << e.what() << std::endl;
    }
}

void Interfata::adaugare_prieten() {
    std::cout << "Enter user id: ";
    int id;
    std::cin >> id;

    std::cout << "Enter friend id: ";
    int id2;
    std::cin >> id2;

    try {
        serviceUtilizatori.adaugarePrieten(id, id2);

        std::cout << "Friend added succesfully.\n"; 
    } catch (std::runtime_error& e) {
        std::cout << e.what() << std::endl;
    }
}

void Interfata::stergere_prieten() {
    std::cout << "Enter user id: ";
    int id;
    std::cin >> id;

    std::cout << "Enter friend id: ";
    int id2;
    std::cin >> id2;

    try {
        serviceUtilizatori.stergerePrieten(id, id2);

        std::cout << "Friend removed succesfully.\n"; 
    } catch (std::runtime_error& e) {
        std::cout << e.what() << std::endl;
    }
}

void Interfata::afisare_prieteni() {
    std::cout << "Enter user id: ";
    int id;
    std::cin >> id;

    try {
        Lista<Utilizator> prieteni = serviceUtilizatori.getPrieteni(id);

        for (int i = 0; i < prieteni.getNrElems(); i++) {
            std::cout << prieteni[i].getId() << " " << prieteni[i].getNume() << " " << prieteni[i].getVarsta() << " " << prieteni[i].getStatus() << std::endl;
        }
    } catch (std::runtime_error& e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << std::endl;
}

void Interfata::adaugare_mesaj() {
    std::cout << "Enter user id: ";
    int id;
    std::cin >> id;

    std::cout << "Enter friend id: ";
    int id2;
    std::cin >> id2;

    std::cout << "Enter message: ";
    std::string message;
    std::cin.ignore();
    std::getline(std::cin, message);

    try {
        serviceUtilizatori.adaugareMesaj(id, id2, message);

        std::cout << "Message added succesfully.\n"; 
    } catch (std::runtime_error& e) {
        std::cout << e.what() << std::endl;
    }
}

void Interfata::afisare_mesaj() {
    std::cout << "Enter user id: ";
    int id;
    std::cin >> id;

    std::cout << "Friend id: ";
    int id2;
    std::cin >> id2;

    try {
        auto messages = serviceUtilizatori.getMesage(id, id2);

        for (int i = 0; i < messages.getNrElems(); i++) {
            Utilizator u1 = serviceUtilizatori.get(messages[i].getId1());
            Utilizator u2 = serviceUtilizatori.get(messages[i].getId2());

            std::cout << u1.getNume() << " " << u2.getNume() << " " << messages[i].getMesaj() << std::endl;
        }
    } catch (std::runtime_error& e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << std::endl;
}

void Interfata::stergere_mesaje() {
    std::cout << "Enter user id: ";
    int id;
    std::cin >> id;

    std::cout << "Enter friend id: ";
    int id2;
    std::cin >> id2;

    try {
        serviceUtilizatori.stergereMesaje(id, id2);

        std::cout << "Chat deleted succesfully.\n"; 
    } catch (std::runtime_error& e) {
        std::cout << e.what() << std::endl;
    }
}

void Interfata::afisare_evenimente() {
    std::cout << "All events:\n";

    Lista<Eveniment> events = serviceEvenimente.getAll();

    for (int i = 0; i < events.getNrElems(); i++) {
        std::cout << events[i].getId() << " " << events[i].getNume() << " " << events[i].new_numar_persoane_interesate() << " " << events[i].getLocatie() << std::endl;
    }
}

void Interfata::afisare_eveniment() {
    std::cout << "Enter event id: ";
    int id;
    std::cin >> id;

    try {
        Eveniment event = serviceEvenimente.get(id);

        std::cout << event.getId() << " " << event.getNume() << " " << event.new_numar_persoane_interesate() << " " << event.getLocatie() << std::endl;
    } catch (std::runtime_error& e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << std::endl;
}

void Interfata::adaugare_eveniment() {
    std::cout << "Enter event id: ";
    int id;
    std::cin >> id;

    std::cout << "Enter event nume: ";
    std::string nume;
    std::cin.ignore();
    std::getline(std::cin, nume);

    std::cout << "Enter event organizer id: ";
    int numar_persoane_interesate;
    std::cin >> numar_persoane_interesate;

    try {
        serviceUtilizatori.get(numar_persoane_interesate);
    } catch (std::runtime_error& e) {
        std::cout << e.what() << std::endl;
        return;
    }

    std::cout << "Enter event locatie: ";
    std::string locatie;
    std::cin.ignore();
    std::getline(std::cin, locatie);

    try {
        Eveniment event(id, nume, numar_persoane_interesate, locatie);
        serviceEvenimente.adaugare(event);

        std::cout << "Eveniment added succesfully.\n"; 
    } catch (std::runtime_error& e) {
        std::cout << e.what() << std::endl;
    }
}

void Interfata::modificare_eveniment() {
    std::cout << "Enter event id: ";
    int id;
    std::cin >> id;

    std::cout << "Enter new event nume: ";
    std::string nume;
    std::cin.ignore();
    std::getline(std::cin, nume);

    std::cout << "Enter new event organizer id: ";
    int numar_persoane_interesate;
    std::cin >> numar_persoane_interesate;

    std::cout << "Enter new event locatie: ";
    std::string locatie;
    std::cin.ignore();
    std::getline(std::cin, locatie);

    try {
        Eveniment event(id, nume, numar_persoane_interesate, locatie);
        serviceEvenimente.modificare(id, event);

        std::cout << "Eveniment updated succesfully.\n"; 
    } catch (std::runtime_error& e) {
        std::cout << e.what() << std::endl;
    }
}

void Interfata::stergere_eveniment() {
    std::cout << "Enter event id: ";
    int id;
    std::cin >> id;

    try {
        serviceEvenimente.stergere(id);

        std::cout << "Eveniment removed succesfully.\n"; 
    } catch (std::runtime_error& e) {
        std::cout << e.what() << std::endl;
    }
}

void Interfata::adaugare_participant() {
    std::cout << "Enter event id: ";
    int id;
    std::cin >> id;

    std::cout << "Enter participant id: ";
    int id_user;
    std::cin >> id_user;

    try {
        serviceUtilizatori.get(id_user);
    } catch (std::runtime_error& e) {
        std::cout << e.what() << std::endl;
        return;
    }

    try {
        serviceEvenimente.adaugareParticipant(id, id_user);

        std::cout << "Participant added succesfully.\n"; 
    } catch (std::runtime_error& e) {
        std::cout << e.what() << std::endl;
    }
}

void Interfata::stergere_participant() {
    std::cout << "Enter event id: ";
    int id;
    std::cin >> id;

    std::cout << "Enter participant id: ";
    int id_user;
    std::cin >> id_user;

    try {
        serviceEvenimente.stergereParticipant(id, id_user);

        std::cout << "Participant removed succesfully.\n"; 
    } catch (std::runtime_error& e) {
        std::cout << e.what() << std::endl;
    }
}

void Interfata::afisare_participanti() {
    std::cout << "Enter event id: ";
    int id;
    std::cin >> id;

    try {
        Lista<int> participanti = serviceEvenimente.getParticipanti(id);

        for (int i = 0; i < participanti.getNrElems(); i++) {
            Utilizator user = serviceUtilizatori.get(participanti[i]);
            std::cout << user.getId() << " " << user.getNume() << " " << user.getVarsta() << " " << user.getStatus() << "\n";
        }
    } catch (std::runtime_error& e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << std::endl;
}






