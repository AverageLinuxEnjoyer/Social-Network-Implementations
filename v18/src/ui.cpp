#include "../include/ui.h"
#include <iostream>

UserInterface::UserInterface(Retea &service)
    : userService(service)
{}

void UserInterface::run() {
    int option = 0;

    while(true) {
        std::cout << "1. Utilizator menu" << std::endl;
        std::cout << "2. Eveniment menu" << std::endl;
        std::cout << "3. Exit" << std::endl;

        std::cin >> option;

        switch(option) {
            case 1:
                meniu_useri();
                break;
            case 2:
                meniu_evenimente();
                break;
            case 3:
                return;
            default:
                std::cout << "Optiune invalida." << std::endl;
        }
    }
}

void UserInterface::meniu_useri() {
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
                afisiare_useri();
                break;
            case 1:
                meniu_adaugare_utilizator();
                break;
            case 2:
                meniu_update_utilizator();
                break;
            case 3:
                meniu_stergere_utilizator();
                break;
            case 4:
                meniu_adaugare_prietenie();
                break;
            case 5:
                meniu_stergere_prietenie();
                break;
            case 6:
                afisare_prietenii();
                break;
            case 7:
                meniu_trimitere_mesaj();
                break;
            case 8:
                afisare_mesaje();
                break;
            case 9:
                return;
            default:
                std::cout << "Optiune invalida." << std::endl;
                break;
        }
    }
}

void UserInterface::meniu_evenimente() {
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
                afisare_meniu_evenimente();
                break;
            case 1:
                meniu_adaugare_eveniment();
                break;
            case 2:
                meniu_update_eveniment();
                break;
            case 3:
                meniu_stergere_eveniment();
                break;
            case 4:
                meniu_adaugare_utilizator_interesat();
                break;
            case 5:
                afisare_utilizatori_interesati();
                break;
            case 6:
                return;
            default:
                std::cout << "Optiune invalida." << std::endl;
                break;
        }
    }
}


void UserInterface::afisiare_useri() {
    Lista<Utilizator*> utilizatori = userService.getUtilizatori();
    for (int i = 0; i < utilizatori.size(); i++) {
        std::cout << utilizatori[i]->getUsername() << " " << utilizatori[i]->getVarsta() << " " << utilizatori[i]->getEmail() << std::endl;
    }
}

void UserInterface::meniu_adaugare_utilizator() {
    do {
        std::cout << "Nume de utilizator: ";
        std::string username;
        std::cin >> username;

        std::cout << "Varsta: ";
        int varsta;
        std::cin >> varsta;

        std::cout << "Email: ";
        std::string email;
        std::cin >> email;

        if (userService.adaugareUtilizator(username, varsta, email)) {
            std::cout << "Utilizator adaugat cu succes.\n";
            return;
        } else {
            std::cout << "Acest nume de utilizator e deja folosit. Incearca din nou\n";
        }
    } while(true);
}

void UserInterface::meniu_update_utilizator() {
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

        if (userService.updateUtilizator(username, newUsername, newAge, newEmail)) {
            std::cout << "Utilizatorul a fost actualizat cu succes.\n";
            return;
        } else {
            std::cout << "Utilizatorul nu exista. Incearca din nou\n";
        }
    } while(true);
}

void UserInterface::meniu_stergere_utilizator() {
    do {
        std::cout << "Nume de utilizator: ";
        std::string username;
        std::cin >> username;

        if (userService.stergereUtiliztor(username)) {
            std::cout << "Utilizator sters cu succes.\n";
            return;
        } else {
            std::cout << "Utilizatorul nu exista.\n";
            return;
        }
    } while(true);
}

void UserInterface::meniu_adaugare_prietenie() {
    do {
        std::cout << "Nume de utilizator: ";
        std::string username;
        std::cin >> username;

        std::cout << "Nume de utilizator prieten: ";
        std::string friendUsername;
        std::cin >> friendUsername;

        if (userService.adaugarePrietenie(username, friendUsername)) {
            std::cout << "Prieten adaugat cu succes.\n";
            return;
        } else {
            std::cout << "Unul din utilizatori nu exista sau sunt prieteni deja. Incearca din nou.\n";
        }
    } while(true);
}

void UserInterface::meniu_stergere_prietenie() {
    do {
        std::cout << "Nume de utilizator: ";
        std::string username;
        std::cin >> username;

        std::cout << "Nume de utilizator prieten: ";
        std::string friendUsername;
        std::cin >> friendUsername;

        if (userService.stergerePrietenie(username, friendUsername)) {
            std::cout << "Prieten sters cu succes.\n";
            return;
        } else {
            std::cout << "Unul din utilizatori nu exista sau nu sunt prieteni. Incearca din nou.\n";
        }
    } while(true);
}

void UserInterface::afisare_prietenii() {
    do {
        std::cout << "Nume de utilizator: ";
        std::string username;
        std::cin >> username;

        Utilizator* user = nullptr;
        auto utilizatori = userService.getUtilizatori();
        // find the user
        for (int i = 0; i < utilizatori.size(); i++) {
            if (utilizatori[i]->getUsername() == username) {
                user = utilizatori[i];
                break;
            }
        }

        if (user == nullptr) {
            std::cout << "Utilizatorul nu exista. Incearca din nou.\n";
            continue;
        }

        auto prieteni = user->getFriends();

        for (int i = 0; i < prieteni.size(); i++) {
            std::cout << prieteni[i].getUser2()->getUsername() << std::endl;
        }

        return;
    } while(true);
}

void UserInterface::meniu_trimitere_mesaj() {
    do {
        std::cout << "Nume de utilizator: ";
        std::string user_expeditor;
        std::cin >> user_expeditor;

        std::cout << "Nume de utilizator al destinatarului: ";
        std::string user_destinatar;
        std::cin >> user_destinatar;

        std::cout << "Mesaj: ";
        std::string message;
        std::cin.ignore();
        std::getline(std::cin, message);

        if (userService.trimitereMesaj(user_expeditor, user_destinatar, message)) {
            std::cout << "Mesaj trimis cu succes.\n";
            return;
        } else {
            std::cout << "Unul din utilizatori nu exista. Incearca din nou.\n";
        }
    } while(true);
}

void UserInterface::afisare_mesaje() {
    do {
        std::cout << "Nume de utilizator: ";
        std::string username;
        std::cin >> username;

        Utilizator* user = nullptr;
        for(int i = 0; i < userService.getUtilizatori().size(); i++)
            if(userService.getUtilizatori()[i]->getUsername() == username)
                user = userService.getUtilizatori()[i];

        if (user == nullptr) {
            std::cout << "Utilizatorul nu exista. Incearca din nou.\n";
            continue;
        }

        std::cout << "Mesaje:\n";
        for (int i = 0; i < user->getMesaje().size(); i++) {
            auto user_expeditor = user->getMesaje()[i].user_expeditor;
            auto user_destinatar = user->getMesaje()[i].user_destinatar;
            std::cout << user_expeditor->getUsername() << " -> " <<
                user_destinatar->getUsername() << ": " <<
                user->getMesaje()[i].continut << std::endl;
        }

        std::cout << "\n";
        break;
    } while(true);
}

void UserInterface::afisare_meniu_evenimente() {
    Lista<Eveniment> evenimente = userService.getEvenimente();
    
    for (int i = 0; i < evenimente.size(); i++) {
        std::cout << evenimente[i].getNume()  <<
            ", elemente: " << evenimente[i].getDate() <<
            ", locatie: " << evenimente[i].getLocatie() <<
            ", descriere: " << evenimente[i].getDescriere() <<
            ", useri interesati: " << evenimente[i].get_utilizatori_interesati().size() <<
        std::endl;
    }
}

void UserInterface::meniu_adaugare_eveniment() {
    do {
        std::cout << "Nume: ";
        std::string nume;
        std::cin >> nume;

        std::cout << "Data: ";
        std::string data;
        std::cin >> data;

        std::cout << "Locatie: ";
        std::string locatie;
        std::cin >> locatie;

        std::cin.ignore();
        std::cout << "Descriere: ";
        std::string descriere;
        std::getline(std::cin, descriere);

        if (userService.adaugareEveniment(nume, locatie, descriere, data)) {
            std::cout << "Eveniment adaugat cu succes.\n";
            return;
        } else {
            std::cout << "Exista deja un eveniment cu acest nume. Incearca din nou.\n";
        }
    } while(true);
}

void UserInterface::meniu_update_eveniment() {
    do {
        std::cout << "Numele evenimentului: ";
        std::string nume;
        std::cin >> nume;

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

        if (userService.updateEveniment(nume, newName, newDate, newLocation, newDescription)) {
            std::cout << "Eveniment actualizat cu succes.\n";
            return;
        } else {
            std::cout << "Nu exista un eveniment cu acest nume. Incearca din nou.\n";
        }
    } while(true);

}

void UserInterface::meniu_stergere_eveniment() {
    do {
        std::cout << "Numele evenimentului: ";
        std::string nume;
        std::cin >> nume;

        if (userService.stergereEveniment(nume)) {
            std::cout << "Eveniment sters cu succes.\n";
            return;
        } else {
            std::cout << "Nu exista un eveniment cu acest nume. Incearca din nou.\n";
        }
    } while(true);
}

void UserInterface::meniu_adaugare_utilizator_interesat() {
    do {
        std::cout << "Nume de utilizator: ";
        std::string username;
        std::cin >> username;

        std::cout << "Numele evenimentului: ";
        std::string eventName;
        std::cin.ignore();
        std::getline(std::cin, eventName);

        if (userService.adaugareParticipantEveniiment(eventName, username)) {
            std::cout << "Utilizatorul interesat adaugat cu succes.\n";
            return;
        } else {
            std::cout << "Evenimentul sau utilizatorul nu exista. Incearca din nou.\n";
        }
    } while(true);
}

void UserInterface::afisare_utilizatori_interesati() {
    do {
        std::cout << "Numele evenimentului: ";
        std::string eventName;
        std::cin.ignore();
        std::getline(std::cin, eventName);

        Eveniment event;
        Lista<Eveniment> evenimente = userService.getEvenimente();
        for (int i = 0; i < userService.getEvenimente().size(); i++) {
            if (userService.getEvenimente()[i].getNume() == eventName) {
                event = userService.getEvenimente()[i];
                break;
            }
        }

        if (event.getNume() == "") {
            std::cout << "Nu exista un eveniment cu acest nume. Incearca din nou.\n";
            continue;
        }

        std::cout << "Utilizatorii interesati:\n";
        for (int i = 0; i < event.get_utilizatori_interesati().size(); i++) {
            Utilizator* utlizatori_interesati = event.get_utilizatori_interesati()[i];
            std::cout << utlizatori_interesati->getUsername() << "\n";
        }
        break;

    } while(true);
}


