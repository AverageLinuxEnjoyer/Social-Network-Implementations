#include "../include/Ui.h"
#include "../include/Culori.h"
#include <iostream>
#include <string>

UI::UI()
        : service(true)
{}

static Modifier::Modifier green(Modifier::FG_GREEN);
static Modifier::Modifier def(Modifier::FG_DEFAULT);

UI& UI::get_obiect() {
    static UI obiect;
    return obiect;
}

void UI::run() {
    int option = 0;

    while(true) {
        std::cout << "1. Meniu utilizator" << std::endl;
        std::cout << "2. Meniu eveniment" << std::endl;
        std::cout << "3. Iesire" << std::endl;


        std::cout << green << "Optiune: " << def;
        std::cin >> option;

        Clear();

        switch(option) {
            case 1:
                meniu_utilizator();
                break;
            case 2:
                meniu_eveniment();
                break;
            case 3:
                return;
            default:
                std::cout << "Optiune invalida." << std::endl;
        }
    }
}

void UI::meniu_utilizator() {
    int option;

    while(true) {
        std::cout << "0. Afisare utilizatori" << std::endl;
        std::cout << "1. Adaugare utilizator" << std::endl;
        std::cout << "2. Actualizare utilizator" << std::endl;
        std::cout << "3. Stergere utilizator" << std::endl;
        std::cout << "4. Adaugare prieten" << std::endl;
        std::cout << "5. Stergere prieten" << std::endl;
        std::cout << "6. Trimitere mesaj" << std::endl;
        std::cout << "7. Afisare mesaje" << std::endl;
        std::cout << "8. Inapoi" << std::endl;
        std::cout << green << "Optiune: " << def;
        std::cin >> option;
        std::cout << std::endl;

        Clear();

        switch(option) {
            case 0:
                afisare_utilizatori();
                break;
            case 1:
                adaugare_utilizator();
                break;
            case 2:
                modificare_utilizator();
                break;
            case 3:
                stergere_utilizator();
                break;
            case 4:
                adaugare_prietenie();
                break;
            case 5:
                stergere_prietenie();
                break;
            case 6:
                trimitere_mesaj();
                break;
            case 7:
                afisare_mesaje();
                break;
            case 8:
                return;
            default:
                std::cout << "Optiune invalida." << std::endl;
                break;
        }

        std::cout << green << "Apasa orice tasta pentru a continua." << std::endl << def;
        std::cin.ignore();
        std::cin.get();
    }
}

void UI::meniu_eveniment() {
    int option;

    while(true) {
        std::cout << "0. Afisare evenimente" << std::endl;
        std::cout << "1. Adaugare eveniment" << std::endl;
        std::cout << "2. Actualizare eveniment" << std::endl;
        std::cout << "3. Stergere eveniment" << std::endl;
        std::cout << "4. Adaugare utilizator interesat in eveniment" << std::endl;
        std::cout << "5. Afisare utilizatori interesati" << std::endl;
        std::cout << "6. Inapoi" << std::endl;
        std::cout << green << "Optiune: " << def;
        std::cin >> option;

        Clear();

        switch(option) {
            case 0:
                afisare_evenimente();
                break;
            case 1:
                adaugare_eveniment();
                break;
            case 2:
                modificare_eveniment();
                break;
            case 3:
                stergere_eveniment();
                break;
            case 4:
                adaugare_utilizator_interesat_in_eveniment();
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

        std::cout << green << "Apasa orice tasta pentru a continua." << std::endl << def;
        std::cin.ignore();
        std::cin.get();
    }
}


void UI::afisare_utilizatori() {
    Lista<Utilizator*> utilizatori = service.getUtilizatori();

    for (int i = 0; i < utilizatori.size(); i++) {
        std::cout << utilizatori[i]->getnume_utilizator() << " " << utilizatori[i]->getvarsta() << " " << utilizatori[i]->getEmail() << std::endl;
    }
}

void UI::adaugare_utilizator() {
    do {
        std::cout << "Nume de utilizator: ";
        std::string nume_utilizator;
        std::cin >> nume_utilizator;

        std::cout << "Varsta: ";
        int varsta;
        std::cin >> varsta;

        std::cout << "Email: ";
        std::string email;
        std::cin >> email;

        if (service.addUtilizator(nume_utilizator, varsta, email)) {
            std::cout << "Utilizator adaugat cu succes.\n";
            return;
        } else {
            std::cout << "Acest nume de utilizator e deja folosit. Incearca din nou\n";
        }
    } while(true);
}

void UI::modificare_utilizator() {
    do {
        std::cout << "Nume de utilizator: ";
        std::string nume_utilizator;
        std::cin >> nume_utilizator;

        std::cout << "Nume de utilizator nou: ";
        std::string newnume_utilizator;
        std::cin >> newnume_utilizator;

        std::cout << "Varsta noua: ";
        int newvarsta;
        std::cin >> newvarsta;

        std::cout << "Email nou: ";
        std::string newEmail;
        std::cin >> newEmail;

        if (service.updateUtilizator(nume_utilizator, newnume_utilizator, newvarsta, newEmail)) {
            std::cout << "Utilizatorul a fost actualizat cu succes.\n";
            return;
        } else {
            std::cout << "Utilizatorul nu exista. Incearca din nou\n";
        }
    } while(true);
}

void UI::stergere_utilizator() {
    do {
        std::cout << "Nume de utilizator: ";
        std::string nume_utilizator;
        std::cin >> nume_utilizator;

        if (service.removeUtilizator(nume_utilizator)) {
            std::cout << "Utilizator sters cu succes.\n";
            return;
        } else {
            std::cout << "Utilizatorul nu exista.\n";
            return;
        }
    } while(true);
}

void UI::adaugare_prietenie() {
    do {
        std::cout << "Nume de utilizator: ";
        std::string nume_utilizator;
        std::cin >> nume_utilizator;

        std::cout << "Nume de utilizator prieten: ";
        std::string friendnume_utilizator;
        std::cin >> friendnume_utilizator;

        if (service.addPrietenie(nume_utilizator, friendnume_utilizator)) {
            std::cout << "Prieten adaugat cu succes.\n";
            return;
        } else {
            std::cout << "Unul din utilizatori nu exista sau sunt prieteni deja. Incearca din nou.\n";
        }
    } while(true);
}

void UI::stergere_prietenie() {
    do {
        std::cout << "Nume de utilizator: ";
        std::string nume_utilizator;
        std::cin >> nume_utilizator;

        std::cout << "Nume de utilizator prieten: ";
        std::string friendnume_utilizator;
        std::cin >> friendnume_utilizator;

        if (service.removePrietenie(nume_utilizator, friendnume_utilizator)) {
            std::cout << "Prieten sters cu succes.\n";
            return;
        } else {
            std::cout << "Unul din utilizatori nu exista sau nu sunt prieteni. Incearca din nou.\n";
        }
    } while(true);
}

void UI::trimitere_mesaj() {
    do {
        std::cout << "Nume de utilizator: ";
        std::string expeditor;
        std::cin >> expeditor;

        std::cout << "Nume de utilizator al destinatarului: ";
        std::string destinatar;
        std::cin >> destinatar;

        std::cout << "Mesaj: ";
        std::string Mesaj;
        std::cin.ignore();
        std::getline(std::cin, Mesaj);

        if (service.trimiteMesaj(expeditor, destinatar, Mesaj)) {
            std::cout << "Mesaj trimis cu succes.\n";
            return;
        } else {
            std::cout << "Unul din utilizatori nu exista. Incearca din nou.\n";
        }
    } while(true);
}

void UI::afisare_mesaje() {
    do {
        std::cout << "Nume de utilizator: ";
        std::string nume_utilizator;
        std::cin >> nume_utilizator;

        Utilizator* Utilizator = nullptr;
        for(int i = 0; i < service.getUtilizatori().size(); i++)
            if(service.getUtilizatori()[i]->getnume_utilizator() == nume_utilizator)
                Utilizator = service.getUtilizatori()[i];

        if (Utilizator == nullptr) {
            std::cout << "Utilizatorul nu exista. Incearca din nou.\n";
            continue;
        }

        std::cout << "Mesaje:\n";
        for (int i = 0; i < Utilizator->getMesaje().size(); i++) {
            auto expeditor = Utilizator->getMesaje()[i].getExpeditor();
            auto destinatar = Utilizator->getMesaje()[i].getDestinatar();
            std::cout << expeditor->getnume_utilizator() << " -> " <<
                      destinatar->getnume_utilizator() << ": " <<
                      Utilizator->getMesaje()[i].getContinut() << std::endl;
        }

        std::cout << "\n";
        break;
    } while(true);
}

void UI::afisare_evenimente() {
    Lista<Eveniment> Eveniments = service.getEvenimente();

    for (int i = 0; i < Eveniments.size(); i++) {
        std::cout << Eveniments[i].getNume()  <<
                  ", data: " << Eveniments[i].getData() <<
                  ", locatie: " << Eveniments[i].getLocatie() <<
                  ", descriere: " << Eveniments[i].getDescriere() <<
                  ", Utilizatori interesati: " << Eveniments[i].getUtilizatoriInteresati().size() <<
                  std::endl;
    }
}

void UI::adaugare_eveniment() {
    do {
        std::cin.ignore();
        std::cout << "Nume: ";
        std::string name;
        std::getline(std::cin, name);

        std::cout << "Data: ";
        std::string date;
        std::getline(std::cin, date);

        std::cout << "Locatie: ";
        std::string location;
        std::getline(std::cin, location);

        std::cout << "Descriere: ";
        std::string description;
        std::getline(std::cin, description);

        if (service.addEveniment(name, location, description, date)) {
            std::cout << "Eveniment adaugat cu succes.\n";
            return;
        } else {
            std::cout << "Exista deja un eveniment cu acest nume. Incearca din nou.\n";
        }
    } while(true);
}

void UI::modificare_eveniment() {
    do {
        std::cin.ignore();
        std::cout << "Numele evenimentului: ";
        std::string name;
        std::getline(std::cin, name);

        std::cout << "Numele nou al evenimentului: ";
        std::string newName;
        std::getline(std::cin, newName);

        std::cout << "Data noua: ";
        std::string newDate;
        std::getline(std::cin, newDate);

        std::cout << "Locatia noua: ";
        std::string newLocation;
        std::getline(std::cin, newLocation);

        std::cout << "Descrierea noua: ";
        std::string newDescription;
        std::getline(std::cin, newDescription);

        if (service.updateEveniment(name, newName, newDate, newLocation, newDescription)) {
            std::cout << "Eveniment actualizat cu succes.\n";
            return;
        } else {
            std::cout << "Nu exista un eveniment cu acest nume. Incearca din nou.\n";
        }
    } while(true);

}

void UI::stergere_eveniment() {
    do {
        std::cin.ignore();
        std::cout << "Numele evenimentului: ";
        std::string name;
        std::getline(std::cin, name);

        if (service.removeEveniment(name)) {
            std::cout << "Eveniment sters cu succes.\n";
            return;
        } else {
            std::cout << "Nu exista un eveniment cu acest nume. Incearca din nou.\n";
        }
    } while(true);
}

void UI::adaugare_utilizator_interesat_in_eveniment() {
    do {
        std::cout << "Nume de utilizator: ";
        std::string nume_utilizator;
        std::cin >> nume_utilizator;

        std::cin.ignore();
        std::cout << "Numele evenimentului: ";
        std::string EvenimentName;
        std::getline(std::cin, EvenimentName);

        if (service.addInterestedUtilizator(EvenimentName, nume_utilizator)) {
            std::cout << "Utilizatorul interesat adaugat cu succes.\n";
            return;
        } else {
            std::cout << "Evenimentul sau utilizatorul nu exista. Incearca din nou.\n";
        }
    } while(true);
}

void UI::afisare_utilizatori_interesati() {
    do {
        std::cin.ignore();
        std::cout << "Numele evenimentului: ";
        std::string EvenimentName;
        std::getline(std::cin, EvenimentName);

        Eveniment Eveniment;
        for (int i = 0; i < service.getEvenimente().size(); i++) {
            if (service.getEvenimente()[i].getNume() == EvenimentName) {
                Eveniment = service.getEvenimente()[i];
                break;
            }
        }

        if (Eveniment.getNume() == "") {
            std::cout << "Nu exista un eveniment cu acest nume. Incearca din nou.\n";
            continue;
        }

        std::cout << "Utilizatorii interesati:\n";
        for (int i = 0; i < Eveniment.getUtilizatoriInteresati().size(); i++) {
            Utilizator* interested = Eveniment.getUtilizatoriInteresati()[i];
            std::cout << interested->getnume_utilizator() << "\n";
        }
        break;

    } while(true);
}