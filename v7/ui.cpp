#include "ui.h"
#include <iostream>

using namespace std;


UI::UI()
{
    retea.adaugaUtilizator(User(1, "Marian Marinescu", 45));
    retea.adaugaUtilizator(User(2, "Andreea Andreescu", 30));
    retea.adaugaUtilizator(User(3, "Florin Florinescu", 44));
    retea.adaugaUtilizator(User(4, "Dinu Dinescu", 31));
    retea.adaugaUtilizator(User(5, "Georgiana Georgescu", 43));
    retea.adaugaUtilizator(User(6, "Vasilica Vasilescu", 32));
    retea.adaugaUtilizator(User(7, "Ion Ionescu", 42));
    retea.adaugaUtilizator(User(8, "Petru Petrescu", 33));
    retea.adaugaUtilizator(User(9, "Monica Monescu", 41));
    retea.adaugaUtilizator(User(10, "Alina Alinescu", 34));
    retea.adaugaUtilizator(User(11, "Alinut Alinescu", 34));
    retea.adaugaUtilizator(User(12, "Alinel Alinescu", 34));
    retea.adaugaUtilizator(User(13, "Alinica Alinescu", 34));
    retea.adaugaUtilizator(User(14, "Alinutescu Alinescu", 34));
    retea.adaugaUtilizator(User(15, "Alinoi Alinescu", 34));   

    retea.adaugaPrietenie(1, 2);
    retea.adaugaPrietenie(2, 3);
    retea.adaugaPrietenie(3, 4);
    retea.adaugaPrietenie(4, 5);
    retea.adaugaPrietenie(5, 6);
    retea.adaugaPrietenie(6, 7);
    retea.adaugaPrietenie(7, 8);
    retea.adaugaPrietenie(8, 9);
    retea.adaugaPrietenie(9, 10);
    retea.adaugaPrietenie(10, 11);
    retea.adaugaPrietenie(11, 12);
    retea.adaugaPrietenie(12, 13);
    retea.adaugaPrietenie(13, 14);
    retea.adaugaPrietenie(14, 15);
    retea.adaugaPrietenie(15, 1);
}

UI::~UI()
{
    
}

void UI::run() {
    int optiune;
    do {
        cout << "1. Adaugare utilizator" << endl;
        cout << "2. Stergere utilizator" << endl;
        cout << "3. Modificare utilizator" << endl;
        cout << "4. Afisare utilizatori" << endl;
        cout << "5. Adaugare eveniment" << endl;
        cout << "6. Stergere eveniment" << endl;
        cout << "7. Modificare eveniment" << endl;
        cout << "8. Afisare evenimente" << endl;
        cout << "9. Adaugare prietenie" << endl;
        cout << "10. Stergere prietenie" << endl;
        cout << "11. Afisare prieteni" << endl;
        cout << "12. Adaugare mesaj" << endl;
        cout << "13. Stergere mesaj" << endl;
        cout << "14. Afisare mesaje" << endl;
        cout << "0. Iesire" << endl;
        cout << "Optiune: ";
        cin >> optiune;
        cout << endl;

        switch (optiune) {
            case 1:
                meniu_adaugare_utilizator();
                break;
            case 2:
                meniu_stergere_utilizator();
                break;
            case 3:
                meniu_modificare_utilizator();
                break;
            case 4:
                get_all_utilizatori();
                break;
            case 5:
                meniu_adaugare_eveniment();
                break;
            case 6:
                meniu_stergere_eveniment();
                break;
            case 7:
                meniu_modificare_eveniment();
                break;
            case 8:
                get_all_evenimente();
                break;
            case 9:
                meniu_adaugare_prietenie();
                break;
            case 10:
                meniu_stergere_prietenie();
                break;
            case 11:
                get_prieteni();
                break;
            case 12:
                meniu_adaugare_mesaj();
                break;
            case 13:
                meniu_stergere_mesaj();
                break;
            case 14:
                get_mesaje();
                break;
            case 0:
                break;
            default:
                cout << "Optiune invalida!" << endl;
                break;
        }
    } while (optiune != 0);
}

void UI::meniu_adaugare_utilizator() {
    int id;
    string nume;
    int varsta;

    cout << "Id: ";
    cin >> id;

    cout << "Nume: ";
    cin >> nume;

    cout << "Varsta: ";
    cin >> varsta;

    if (retea.adaugaUtilizator(User(id, nume, varsta))) {
        cout << "Utilizatorul a fost adaugat cu succes!" << endl;
    } else {
        cout << "Utilizatorul nu a putut fi adaugat!" << endl;
    }
}

void UI::meniu_stergere_utilizator() {
    int id;

    cout << "Id: ";
    cin >> id;

    if (retea.stergeUtilizator(id)) {
        cout << "Utilizatorul a fost sters cu succes!" << endl;
    } else {
        cout << "Utilizatorul nu a putut fi sters!" << endl;
    }
}

void UI::meniu_modificare_utilizator() {
    int id;
    string nume;
    int varsta;

    cout << "Id: ";
    cin >> id;

    cout << "Nume: ";
    cin >> nume;

    cout << "Varsta: ";
    cin >> varsta;

    if (retea.modificaUtilizator(id, User(id, nume, varsta))) {
        cout << "Utilizatorul a fost modificat cu succes!" << endl;
    } else {
        cout << "Utilizatorul nu a putut fi modificat!" << endl;
    }
}

void UI::get_all_utilizatori() {
    Lista<User> utilizatori = retea.getAllUtilizatori();

    for (int i = 0; i < utilizatori.getMarime(); i++) {
        std::cout << utilizatori[i].getId() << " " << utilizatori[i].getNume() << " " << utilizatori[i].getVarsta() << std::endl;
    }
}

void UI::meniu_adaugare_eveniment() {
    string nume, locatie, data;

    cout << "Nume: ";
    cin >> nume;

    cout << "Locatie: ";
    cin >> locatie;

    cout << "Data: ";
    cin >> data;

    if (retea.adaugaEveniment(Eveniment(nume, locatie, data))) {
        cout << "Evenimentul a fost adaugat cu succes!" << endl;
    } else {
        cout << "Evenimentul nu a putut fi adaugat!" << endl;
    }
}

void UI::meniu_stergere_eveniment() {
    string nume;

    if (retea.stergeEveniment(nume)) {
        cout << "Evenimentul a fost sters cu succes!" << endl;
    } else {
        cout << "Evenimentul nu a putut fi sters!" << endl;
    }
}

void UI::meniu_modificare_eveniment() {
    string nume, locatie, data;

    cout << "Nume: ";
    cin >> nume;

    cout << "Locatie: ";
    cin >> locatie;

    cout << "Data: ";
    cin >> data;

    if (retea.modificaEveniment(nume, Eveniment(nume, locatie, data))) {
        cout << "Evenimentul a fost modificat cu succes!" << endl;
    } else {
        cout << "Evenimentul nu a putut fi modificat!" << endl;
    }
}

void UI::get_all_evenimente() {
    Lista<Eveniment> evenimente = retea.getAllEvenimente();

    for (int i = 0; i < evenimente.getMarime(); i++) {
        std::cout << evenimente[i].getNume() << " " << evenimente[i].getLocatie() << " " << evenimente[i].getData() << std::endl;
    }
}

void UI::meniu_adaugare_prietenie() {
    int id1, id2;

    cout << "Id1: ";
    cin >> id1;

    cout << "Id2: ";
    cin >> id2;

    if (retea.adaugaPrietenie(id1, id2)) {
        cout << "Prietenie a fost adaugata cu succes!" << endl;
    } else {
        cout << "Prietenie nu a putut fi adaugata!" << endl;
    }
}

void UI::meniu_stergere_prietenie() {
    int id1, id2;

    cout << "Id1: ";
    cin >> id1;

    cout << "Id2: ";
    cin >> id2;

    if (retea.stergePrietenie(id1, id2)) {
        cout << "Prietenie a fost stearsa cu succes!" << endl;
    } else {
        cout << "Prietenie nu a putut fi stearsa!" << endl;
    }
}

void UI::get_prieteni() {
    int id;
    std::cout << "Id user: ";
    std::cin >> id;

    Lista<User> prieteni = retea.getAllPrietenii(id);

    for (int i = 0; i < prieteni.getMarime(); i++) {
        std::cout << prieteni[i].getId() << " " << prieteni[i].getNume() << " " << prieteni[i].getVarsta() << std::endl;
    }
}

void UI::meniu_adaugare_mesaj() {
    int id1, id2;
    string text;

    cout << "Id1: ";
    cin >> id1;

    cout << "Id2: ";
    cin >> id2;

    cout << "Text: ";
    cin >> text;

    if (retea.adaugaMesaj(Mesaj(id1, id2, text))) {
        cout << "Mesajul a fost adaugat cu succes!" << endl;
    } else {
        cout << "Mesajul nu a putut fi adaugat!" << endl;
    }
}

void UI::meniu_stergere_mesaj() {
    string text;
    std::cin >> text;

    if (retea.stergeMesaj(text)) {
        cout << "Mesajul a fost sters cu succes!" << endl;
    } else {
        cout << "Mesajul nu a putut fi sters!" << endl;
    }
}

void UI::get_mesaje() {
    int id1, id2;
    std::cin >> id1 >> id2;

    Lista<Mesaj> mesaje = retea.getBetweenUsers(id1, id2);

    for (int i = 0; i < mesaje.getMarime(); i++) {
        std::cout << mesaje[i].getIdUser1() << " " << mesaje[i].getIdUser2() << " " << mesaje[i].getMesaj() << std::endl;
    }
}







