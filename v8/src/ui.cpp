#include  "../include/ui.h"

#include <iostream>

UI::UI()
{
    
}

UI::~UI()
{
    
}

void UI::run() {
    int optiune;
    while (true) {
        std::cout << "1. Adauga utilizator\n" \
                     "2. Adauga eveniment\n" \
                     "3. Adauga mesaj\n" \
                     "4. Adauga prietenie\n" \
                     "5. Sterge utilizator\n" \
                     "6. Sterge eveniment\n" \
                     "7. Sterge mesaj\n" \
                     "8. Sterge prietenie\n" \
                     "9. Modifica utilizator\n" \
                     "10. Modifica eveniment\n" \
                     "11. Afisare utilizatori\n" \
                     "12. Afisare evenimente\n" \
                     "13. Afisare mesaje\n" \
                     "14. Afisare mesaje intre utilizatori\n" \
                     "15. Afisare prietenii\n" \
                     "16. Afisare prieteni ai unui utilizator\n" \
                     "0. Iesire\n" \
                     "Optiune: ";
        std::cin >> optiune;
        std::cin.ignore();
        
        switch (optiune) {
            case 1:
                adaugaUtilizator();
                break;
            case 2:
                adaugaEveniment();
                break;
            case 3:
                adaugaMesaj();
                break;
            case 4:
                adaugaPrietenie();
                break;
            case 5:
                stergeUtilizator();
                break;
            case 6:
                stergeEveniment();
                break;
            case 7:
                stergeMesaj();
                break;
            case 8:
                stergePrietenie();
                break;
            case 9:
                modificaUtilizator();
                break;
            case 10:
                modificaEveniment();
                break;
            case 11:
                afisareUtilizatori();
                break;
            case 12:
                afisareEvenimente();
                break;
            case 13:
                afisareMesaje();
                break;
            case 14:
                afisareMesajeIntreUtilizatori();
                break;
            case 15:
                afisarePrietenii();
                break;
            case 16:
                afisarePrieteni();
                break;
            case 0:
                return;
            default:
                std::cout << "Optiune invalida!\n";
                break;
        }
    }
}

void UI::adaugaUtilizator() {
    int id;
    std::string nume, prenume, email, parola;
    bool student;
    std::cout << "Id: ";
    std::cin >> id;
    std::cin.ignore();
    std::cout << "Nume: ";
    std::getline(std::cin, nume);
    std::cout << "Prenume: ";
    std::getline(std::cin, prenume);
    std::cout << "Email: ";
    std::getline(std::cin, email);
    std::cout << "Parola: ";
    std::getline(std::cin, parola);
    std::cout << "Student: ";
    std::cin >> student;
    std::cin.ignore();

    retea.adaugaUtilizator(Utilizator(id, nume, prenume, email, parola, student));
}

void UI::adaugaEveniment() {
    int id;
    std::string nume, data, locatie;
    std::cout << "Id: ";
    std::cin >> id;
    std::cin.ignore();
    std::cout << "Nume: ";
    std::getline(std::cin, nume);
    std::cout << "Data: ";
    std::getline(std::cin, data);
    std::cout << "Locatie: ";
    std::getline(std::cin, locatie);

    retea.adaugaEveniment(Eveniment(id, nume, data, locatie));
}

void UI::adaugaMesaj() {
    int id, id1, id2;
    std::string mesaj, data;
    std::cout << "Id: ";
    std::cin >> id;
    std::cout << "Id1: ";
    std::cin >> id1;
    std::cout << "Id2: ";
    std::cin >> id2;
    std::cout << "Mesaj: ";
    std::cin.ignore();
    std::getline(std::cin, mesaj);
    std::cout << "Data: ";
    std::cin.ignore();
    std::getline(std::cin, data);

    retea.adaugaMesaj(Mesaj(id, id1, id2, mesaj, data));
}

void UI::adaugaPrietenie() {
    int id1, id2;
    std::cout << "Id1: ";
    std::cin >> id1;
    std::cout << "Id2: ";
    std::cin >> id2;

    retea.adaugaPrietenie(id1, id2);
}

void UI::stergeUtilizator() {
    int id;
    std::cout << "Id: ";
    std::cin >> id;
    std::cin.ignore();

    retea.stergeUtilizator(id);
}

void UI::stergeEveniment() {
    int id;
    std::cout << "Id: ";
    std::cin >> id;
    std::cin.ignore();

    retea.stergeEveniment(id);
}

void UI::stergeMesaj() {
    int id;
    std::cout << "Id: ";
    std::cin >> id;
    std::cin.ignore();

    retea.stergeMesaj(id);
}

void UI::stergePrietenie() {
    int id1, id2;
    std::cout << "Id1: ";
    std::cin >> id1;
    std::cout << "Id2: ";
    std::cin >> id2;
    std::cin.ignore();

    retea.stergePrietenie(id1, id2);
}

void UI::modificaUtilizator() {
    int id;
    std::string nume, prenume, email, parola;
    bool student;
    std::cout << "Id: ";
    std::cin >> id;
    std::cin.ignore();
    std::cout << "Nume nou: ";
    std::getline(std::cin, nume);
    std::cout << "Prenume nou: ";
    std::getline(std::cin, prenume);
    std::cout << "Email nou: ";
    std::getline(std::cin, email);
    std::cout << "Parola noua: ";
    std::getline(std::cin, parola);
    std::cout << "Student: ";
    std::cin >> student;
    std::cin.ignore();

    retea.modificaUtilizator(Utilizator(id, nume, prenume, email, parola, student));
}

void UI::modificaEveniment() {
    int id;
    std::string nume, data, locatie;
    std::cout << "Id: ";
    std::cin >> id;
    std::cin.ignore();
    std::cout << "Nume nou: ";
    std::getline(std::cin, nume);
    std::cout << "Data noua: ";
    std::getline(std::cin, data);
    std::cout << "Locatie noua: ";
    std::getline(std::cin, locatie);

    retea.modificaEveniment(Eveniment(id, nume, data, locatie));
}

void UI::afisareUtilizatori() {
    Lista<Utilizator> utilizatori = retea.getUtilizatori();
    std::cout << "Utilizatori: \n";
    for (int i = 0; i < utilizatori.size(); i++) {
        Utilizator u = utilizatori.get(i);
        std::cout << "Id: " << u.getId() << ", Nume: " << u.getNume() << ", Prenume: " << u.getPrenume() << ", Email: " << u.getEmail() << ", Parola: " << u.getParola() << ", Student: " << u.isStudent() << "\n";
    }
}

void UI::afisareEvenimente() {
    Lista<Eveniment> evenimente = retea.getEvenimente();
    std::cout << "Evenimente: \n";
    for (int i = 0; i < evenimente.size(); i++) {
        Eveniment e = evenimente.get(i);
        std::cout << "Id: " << e.getId() << ", Nume: " << e.getNume() << ", Data: " << e.getData() << ", Locatie: " << e.getLocatie() << "\n";
    }
}

void UI::afisareMesaje() {
    Lista<Mesaj> mesaje = retea.getMesaje();
    std::cout << "Mesaje: \n";
    for (int i = 0; i < mesaje.size(); i++) {
        Mesaj m = mesaje.get(i);
        Utilizator u1 = retea.getUtilizator(m.getId1());
        Utilizator u2 = retea.getUtilizator(m.getId2());

        std::cout << "Id: " << m.getId() << ", User1: " << u1.getNume() << ", User2: " << u2.getNume() << ", Mesaj: " << m.getText() << ", Data: " << m.getData() << "\n";
    }
}

void UI::afisareMesajeIntreUtilizatori() {
    int id1, id2;
    std::cout << "Id1: ";
    std::cin >> id1;
    std::cout << "Id2: ";
    std::cin >> id2;
    std::cin.ignore();

    Lista<Mesaj> mesaje = retea.getMesaje(id1, id2);

    if (mesaje.size() == 0)
    {
        std::cout << "Nu exista mesaje intre acesti utilizatori.\n";
        return;   
    }

    std::cout << "Mesaje: \n";
    for (int i = 0; i < mesaje.size(); i++) {
        Mesaj m = mesaje.get(i);
        Utilizator u1 = retea.getUtilizator(m.getId1());
        Utilizator u2 = retea.getUtilizator(m.getId2());
        std::cout << "Id: " << m.getId() << ", User1: " << u1.getNume() << ", User2: " << u2.getNume() << ", Mesaj: " << m.getText() << ", Data: " << m.getData() << "\n";
    }
}

void UI::afisarePrietenii() {
    Lista<Prietenie> prietenii = retea.getPrietenii();
    std::cout << "Prietenii: \n";
    for (int i = 0; i < prietenii.size(); i++) {
        Prietenie p = prietenii.get(i);
        Utilizator u1 = retea.getUtilizator(p.getId1());
        Utilizator u2 = retea.getUtilizator(p.getId2());
        std::cout << "User1: " << u1.getNume() << ", User2: " << u2.getNume() << "\n";
    }
}

void UI::afisarePrieteni() {
    int id;
    std::cout << "Id: ";
    std::cin >> id;
    std::cin.ignore();

    Lista<Utilizator> prieteni = retea.getPrieteni(id);

    if (prieteni.size() == 0)
    {
        std::cout << "Nu exista prieteni pentru acest utilizator.\n";
        return;   
    }

    std::cout << "Prieteni: \n";
    for (int i = 0; i < prieteni.size(); i++) {
        Utilizator u = prieteni.get(i);
        std::cout << "Id: " << u.getId() << ", Nume: " << u.getNume() << ", Prenume: " << u.getPrenume() << ", Email: " << u.getEmail() << ", Parola: " << u.getParola() << ", Student: " << u.isStudent() << "\n";
    }
}



