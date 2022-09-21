#include "meniu.h"

void Meniu::runMeniu() {
    int optiune;
    do {
        cout << "1. Adauga user" << endl;
        cout << "2. Update user" << endl;
        cout << "3. Sterge user" << endl;
        cout << "4. Afiseaza useri" << endl;
        cout << "==========================" << endl;
        cout << "5. Adauga eveniment" << endl;
        cout << "6. Update eveniment" << endl;
        cout << "7. Sterge eveniment" << endl;
        cout << "8. Afiseaza evenimente" << endl;
        cout << "==========================" << endl;
        cout << "9. Adauga mesaj" << endl;
        cout << "10. Afiseaza mesaje" << endl;
        cout << "==========================" << endl;
        cout << "11. Adauga prietenie" << endl;
        cout << "12. Sterge prietenie" << endl;
        cout << "13. Afiseaza prieteni" << endl;
        cout << "==========================" << endl;
        cout << "0. Exit" << endl;
        cout << "Optiune: ";
        cin >> optiune;
        cout << endl;
        switch (optiune) {
            case 1:
                addUser();
                break;
            case 2:
                updateUser();
                break;
            case 3:
                removeUser();
                break;
            case 4:
                getUsers();
                break;
            case 5:
                addEveniment();
                break;
            case 6:
                updateEveniment();
                break;
            case 7:
                removeEveniment();
                break;
            case 8:
                getEvenimente();
                break;
            case 9:
                addMesaj();
                break;
            case 10:
                getMesaje();
                break;
            case 11:
                addPrietenie();
                break;
            case 12:
                removePrietenie();
                break;
            case 13:
                getPrieteni();
                break;
            case 0:
                break;
            default:
                cout << "Aceasta optiune nu exista\n" << endl;
                break;
        }
    } while (optiune != 0);
}

void Meniu::addUser() {
    int id;
    string nume, prenume;

    cout << "Id: "; cin >> id;
    cout << "Nume: "; cin >> nume;
    cout << "Prenume: "; cin >> prenume;

    User user(id, nume, prenume);
    retea.addUser(user);
}

void Meniu::updateUser() {
    int id;
    string nume, prenume;

    cout << "Id: "; cin >> id;
    cout << "Nume: "; cin >> nume;
    cout << "Prenume: "; cin >> prenume;

    User user(id, nume, prenume);
    retea.updateUser(id, user);
}

void Meniu::removeUser() {
    int id;

    cout << "Id: "; cin >> id;

    retea.removeUser(id);
}

void Meniu::getUsers() {
    vector<User> users = retea.getUsers();
    for (User user : users) {
        cout << "UserID: " << user.getId() << " Nume: " << user.getNume() << " Prenume: " << user.getPrenume() << endl;
    }
}

void Meniu::updateEveniment() {
    int id;
    string nume, locatie;

    cout << "Id: "; cin >> id;
    cout << "Nume: "; cin >> nume;
    cout << "Locatie: "; cin >> locatie;

    Eveniment eveniment(id, nume, locatie);
    retea.updateEveniment(id, eveniment);
}

void Meniu::removeEveniment() {
    int id;

    cout << "Id: "; cin >> id;

    retea.removeEveniment(id);
}

void Meniu::getEvenimente() {
    vector<Eveniment> evenimente = retea.getEvenimente();
    for (Eveniment eveniment : evenimente) {
        cout << "EvenimentID: " << eveniment.getId() << " Nume: " << eveniment.getNume() << " Locatie: " << eveniment.getData() << endl;
    }
}

void Meniu::addMesaj() {
    int id_user1, id_user2;
    string text;

    cout << "Id user1: "; cin >> id_user1;
    cout << "Id user2: "; cin >> id_user2;
    cout << "Text: "; cin >> text;

    Mesaj mesaj(id_user1, id_user2, text);
    retea.addMesaj(mesaj);
}

void Meniu::getMesaje() {
    vector<Mesaj> mesaje = retea.getMesaje();
    for (Mesaj mesaj : mesaje) {
        cout << mesaj.getId_user_destinatar() << " " << mesaj.getId_user_expeditor() << " " << mesaj.getContinut() << endl;
    }
}

void Meniu::addPrietenie() {
    int id_user1, id_user2;

    cout << "Id user1: "; cin >> id_user1;
    cout << "Id user2: "; cin >> id_user2;

    retea.addPrietenie(id_user1, id_user2);
}

void Meniu::removePrietenie() {
    int id_user1, id_user2;

    cout << "Id user1: "; cin >> id_user1;
    cout << "Id user2: "; cin >> id_user2;

    retea.removePrietenie(id_user1, id_user2);
}

void Meniu::getPrieteni() {
    int id_user;
    cout << "Id user: "; cin >> id_user;

    vector<User> prieteni = retea.getPrieteni(id_user);
    for (User prieten : prieteni) {
        cout << "UserID: " << prieten.getId() << " Nume: " << prieten.getNume() << " Prenume: " << prieten.getPrenume() << endl;
    }
}

void Meniu::addEveniment() {
    int id;
    string nume, locatie;

    cout << "Id: "; cin >> id;
    cout << "Nume: "; cin >> nume;
    cout << "Locatie: "; cin >> locatie;

    Eveniment eveniment(id, nume, locatie);
    retea.addEveniment(eveniment);
}
