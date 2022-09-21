#include "../include/UI.h"
#include <iostream>
#include <stdexcept>

UI::UI(ServiceUtilizatori& service_utilizatori, ServiceEvenimente& service_evenimente)
    : serviceUtilizatori(service_utilizatori),
      serviceEvenimente(service_evenimente)
{}

void UI::run() {
    int optiune;
    while(true) {

        std::cout << std::endl;
        std::cout << "0. Afisare utilizatori" << std::endl;
        std::cout << "1. Adaugare utilizator" << std::endl;
        std::cout << "2. Modificare utilizator" << std::endl;
        std::cout << "3. Stergere utilizator" << std::endl;
        std::cout << "4. Afisare evenimente participate." << std::endl;

        std::cout << "5. Afisare prieteni" << std::endl;
        std::cout << "6. Adaugare prieten" << std::endl;

        std::cout << "7. Afisare evenimente" << std::endl;
        std::cout << "8. Adaugare eveniment" << std::endl;
        std::cout << "9. Modificare eveniment" << std::endl;
        std::cout << "10. Stergere eveniment" << std::endl;

        std::cout << "11. Participare eveniment" << std::endl;
        std::cout << "12. Afisare participanti eveniment." << std::endl;

        std::cout << "13. Trimitere mesaj" << std::endl;
        std::cout << "14. Afisare mesaje" << std::endl;

        std::cout << "15. Inchidere" << std::endl;

        std::cout << "Optiune: ";
        std::cin >> optiune;

        std::cout << std::endl;

        switch(optiune) {
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
                afisare_evenimete_participate();
                break;
            case 5:
                afisare_prieteni();
                break;
            case 6:
                adaugare_prieten();
                break;
            case 7:
                afisare_evenimente();
                break;
            case 8:
                adaugare_eveniment();
                break;
            case 9:
                modificare_eveniment();
                break;
            case 10: 
                stergere_eveniment();
                break;
            case 11:
                participare_eveniment();
                break;
            case 12:
                afisare_participanti_eveniment();
                break;
            case 13:
                trimitereMesaj();
                break;
            case 14:
                afisare_mesaje();
                break;
            case 15:
                return;
            default:
                std::cout << "Aceasta optiune nu exista." << std::endl;
        }
    }
}


void UI::afisare_utilizatori() {
    std::cout << "Utilizatori (id, nume, prenume, varsta, email, parola):" << std::endl;
    auto utilizatori = serviceUtilizatori.getAll();
    for(int i = 0; i < utilizatori.size(); i++) {
        std::cout << utilizatori[i] << std::endl;
    }
}

void UI::adaugare_utilizator() {
    Utilizator utilizator;
    std::cout << "Introduceti datele utilizatorului (id, nume, prenume, varsta, email, parola):" << std::endl;
    std::cin >> utilizator;

    try {
        serviceUtilizatori.addUtilizator(utilizator);
    } catch(std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}

void UI::modificare_utilizator() {
    int id;
    std::cout << "Introduceti id-ul utilizatorului: ";
    std::cin >> id;

    Utilizator utilizator;
    std::cout << "Introduceti datele (id, nume, prenume, varsta, email, parola):" << std::endl;
    std::cin >> utilizator;

    try {
        serviceUtilizatori.updateUtilizator(id, utilizator);
    } catch(std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}

void UI::stergere_utilizator() {
    int id;
    std::cout << "Introduceti id-ul utilizatorului: ";
    std::cin >> id;

    try {
        serviceUtilizatori.deleteUtilizator(id);
    } catch(std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}

void UI::afisare_evenimete_participate() {
    int id;
    std::cout << "Introduceti id-ul utilizatorului: ";
    std::cin >> id;

    try {
        Utilizator utilizator = serviceUtilizatori.getUtilizator(id);
        Lista<int> id_evenimente = utilizator.getEvenimente();

        std::cout << "Evenimente participate:" << std::endl;
        for(int i = 0; i < id_evenimente.size(); i++) {
            std::cout << serviceEvenimente.getEveniment(id_evenimente[i]) << std::endl;
        }
    } catch(std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}

void UI::afisare_prieteni() {
    int id;
    std::cout << "Introduceti id-ul utilizatorului: ";
    std::cin >> id;

    std::cout << "Prieteni (id, nume, prenume, varsta, email, parola):" << std::endl;
    Lista<int> id_prieteni = serviceUtilizatori.getPrieteni(id);
    
    for(int i = 0; i < id_prieteni.size(); i++) {
        std::cout << serviceUtilizatori.getUtilizator(id_prieteni[i]) << std::endl;
    }
}

void UI::adaugare_prieten() {
    int id_utilizator;
    std::cout << "Introduceti id-ul utilizatorului: ";
    std::cin >> id_utilizator;

    int id_prieten;
    std::cout << "Introduceti id-ul prietenului: ";
    std::cin >> id_prieten;

    try {
        serviceUtilizatori.adaugarePrieten(id_utilizator, id_prieten);
    } catch(std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}

void UI::afisare_evenimente() {
    std::cout << "Evenimente (id, nume, data, locatie, descriere):" << std::endl;
    Lista<Eveniment> evenimente = serviceEvenimente.getAll();
    for(int i = 0; i < evenimente.size(); i++) {
        std::cout << evenimente[i] << std::endl;
    }
}

void UI::adaugare_eveniment() {
    Eveniment eveniment;
    std::cout << "Introduceti datele evenimentului (id, nume, data, locatie, numar bilete):" << std::endl;
    std::cin >> eveniment;

    try {
        serviceEvenimente.addEveniment(eveniment);
    } catch(std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}

void UI::modificare_eveniment() {
    int id;
    std::cout << "Introduceti id-ul evenimentului: ";
    std::cin >> id;

    Eveniment eveniment;
    std::cout << "Introduceti datele (id, nume, data, locatie, descriere):" << std::endl;
    std::cin >> eveniment;

    try {
        serviceEvenimente.updateEveniment(id, eveniment);
    } catch(std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}

void UI::stergere_eveniment() {
    int id;
    std::cout << "Introduceti id-ul evenimentului: ";
    std::cin >> id;

    try {
        serviceEvenimente.deleteEveniment(id);
    } catch(std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}

void UI::participare_eveniment() {
    int id_utilizator;
    std::cout << "Introduceti id-ul utilizatorului: ";
    std::cin >> id_utilizator;

    int id_eveniment;
    std::cout << "Introduceti id-ul evenimentului: ";
    std::cin >> id_eveniment;

    try {
        serviceEvenimente.adaugareParticipant(id_eveniment, id_utilizator);
        serviceUtilizatori.participareEveniment(id_utilizator, id_eveniment);
    } catch(std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}

void UI::afisare_participanti_eveniment() {
    int id_eveniment;
    std::cout << "Introduceti id-ul evenimentului: ";
    std::cin >> id_eveniment;

    Lista<int> id_participanti = serviceEvenimente.getParticipanti(id_eveniment);

    std::cout << "Participanti (id, nume, prenume, varsta, email, parola):" << std::endl;
    for(int i = 0; i < id_participanti.size(); i++) {
        std::cout << serviceUtilizatori.getUtilizator(id_participanti[i]) << std::endl;
    }
}

void UI::trimitereMesaj() {
    int id_utilizator;
    std::cout << "Introduceti id-ul utilizatorului: ";
    std::cin >> id_utilizator;

    int id_prieten;
    std::cout << "Introduceti id-ul prietenului: ";
    std::cin >> id_prieten;

    std::string mesaj;
    std::cout << "Introduceti mesajul: ";
    // read until newline
    std::cin.ignore();
    std::getline(std::cin, mesaj);

    try {
        serviceUtilizatori.trimiteMesaj(id_utilizator, id_prieten, mesaj);
    } catch(std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}

void UI::afisare_mesaje() {
    int id_utilizator1, id_utilizator2;
    std::cout << "Introduceti id-ul utilizatorului: ";
    std::cin >> id_utilizator1;
    std::cout << "Introduceti id-ul celui de-al doilea utilizator: ";
    std::cin >> id_utilizator2;
    
    Lista<Mesaj> mesaje;
    try {
        mesaje = serviceUtilizatori.getMesaje(id_utilizator1, id_utilizator2);
    } catch (std::runtime_error &e) {
        std::cout << e.what() << std::endl;
        return;
    }

    std::cout << "(<Expeditor>, <Destinatar>): <mesaj>" << std::endl;
    for (int i = 0; i < mesaje.size(); i++) {
        std::cout << "(" <<  serviceUtilizatori.getUtilizator(mesaje[i].senderId()).getNume() << ", " <<
                     serviceUtilizatori.getUtilizator(mesaje[i].receiverId()).getNume() << "): " << mesaje[i].getText() << std::endl;
    }


}
