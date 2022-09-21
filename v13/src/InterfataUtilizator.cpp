#include "../include/InterfataUtilizator.h"

void InterfataUtilizator::porneste() {
    int optiune;
    do {
        afisare_meniu();

        cout << "> ";
        cin >> optiune;
        switch (optiune) {
            case 1:
                afisare_utilizatori();
                break;
            case 2:
                adauga_utilizator();
                break;
            case 3:
                modifica_utilizator();
                break;
            case 4:
                sterge_utilizator();
                break;
            case 5:
                afisare_prietenii();
                break;
            case 6:
                afisare_prieteni();
                break;
            case 7:
                adauga_prietenie();
                break;
            case 8:
                sterge_prietenie();
                break;
            case 9:
                afisare_mesaje();
                break;
            case 10:
                adauga_mesaj();
                break;
            case 11:
                afisare_evenimente();
                break;
            case 12:
                adauga_eveniment();
                break;
            case 13:
                modifica_eveniment();
                break;
            case 14:
                sterge_eveniment();
                break;
            case 15:
                adauga_utilizator_participant();
                break;
            case 16:
                afisare_participanti();
                break;
            case 0:
                break;
            default:
                cout << "Optiune invalida!" << endl;
        }
    } while (optiune != 0);
}

void InterfataUtilizator::afisare_meniu() {
    cout << "1. Afisare utilizatori" << endl;
    cout << "2. Adauga utilizator" << endl;
    cout << "3. Modifica utilizator" << endl;
    cout << "4. Sterge utilizator" << endl;
    cout << "5. Afisare prietenii" << endl;
    cout << "6. Afisare prieteni" << endl;
    cout << "7. Adauga prietenie" << endl;
    cout << "8. Sterge prietenie" << endl;
    cout << "9. Afisare mesaje" << endl;
    cout << "10. Adauga mesaj" << endl;
    cout << "11. Afisare evenimente" << endl;
    cout << "12. Adauga eveniment" << endl;
    cout << "13. Modifica eveniment" << endl;
    cout << "14. Sterge eveniment" << endl;
    cout << "15. Adauga utilizator participant" << endl;
    cout << "16. Afisare participanti" << endl;
    cout << "0. Iesire" << endl;
}

void InterfataUtilizator::afisare_utilizatori() {
    cout << "Utilizatori: " << endl;
    Lista<Utilizator> utilizatori = retea.get_utilizatori();
    
    for (int i = 0; i < utilizatori.get_dimensiune(); i++) {
        Utilizator u = utilizatori.get_element(i);

        cout << "[Nume:" << u.get_nume() << ", Prenume:" << u.get_prenume() << ", Data nasterii:" << u.get_data_nasterii() << ", Varsta: " << u.get_varsta() << ", Data inregistrarii:" << u.get_data_inregistrarii() << "]" << endl;
    }
}

void InterfataUtilizator::adauga_utilizator() {
    string nume, prenume;
    Data data_nasterii;

    cout << "Nume: ";
    cin >> nume;
    cout << "Prenume: ";
    cin >> prenume;
    cout << "Data nasterii: ";
    cin >> data_nasterii;
    try {
        Utilizator u(nume, prenume, data_nasterii);
        retea.adauga_utilizator(u);
    } catch (const char* mesaj) {
        cout << mesaj << endl;
    }
}

void InterfataUtilizator::modifica_utilizator() {
    string nume, nume_nou, prenume_nou;
    Data data_nasterii_noua;

    cout << "Nume: ";
    cin >> nume;

    cout << "Nume nou: ";
    cin >> nume_nou;

    cout << "Prenume nou: ";
    cin >> prenume_nou;

    cout << "Data nasterii noua: ";
    cin >> data_nasterii_noua;

    try {
        Utilizator u(nume_nou, prenume_nou, data_nasterii_noua);
        retea.modifica_utilizator(nume, u);
    } catch (const char* mesaj) {
        cout << mesaj << endl;
    }
}

void InterfataUtilizator::sterge_utilizator() {
    string nume;

    cout << "Nume: ";
    cin >> nume;

    try {
        retea.sterge_utilizator(nume);
    } catch (const char* mesaj) {
        cout << mesaj << endl;
    }
}

void InterfataUtilizator::afisare_prietenii() {
    // print all friendships
    cout << "Prietenii: " << endl;
    Lista<Prietenie> prieteni = retea.get_toate_prieteniile();

    for (int i = 0; i < prieteni.get_dimensiune(); i++) {
        Prietenie p = prieteni.get_element(i);

        Utilizator u1 = p.get_utilizator1();
        Utilizator u2 = p.get_utilizator2();
        int durata = p.get_durata_prietenie();

        cout << "[" << u1.get_nume() << " " << u1.get_prenume() << "] si [" << u2.get_nume() << " " << u2.get_prenume() << "] sunt prieteni de " << durata << " zile." << endl;
    }
}

void InterfataUtilizator::afisare_prieteni() {
    string nume;

    cout << "Nume: ";
    cin >> nume;

    try {
        Lista<Utilizator> prieteni = retea.get_prieteni(nume);

        for (int i = 0; i < prieteni.get_dimensiune(); i++) {
            Utilizator u = prieteni.get_element(i);

            cout << "[Nume:" << u.get_nume() << ", Prenume:" << u.get_prenume() << ", Data nasterii:" << u.get_data_nasterii() << ", Varsta: " << u.get_varsta() << ", Data inregistrarii:" << u.get_data_inregistrarii() << "]" << endl;
        }
    } catch (const char* mesaj) {
        cout << mesaj << endl;
    }
}

void InterfataUtilizator::adauga_prietenie() {
    string nume1, nume2;

    cout << "Nume1: ";
    cin >> nume1;

    cout << "Nume2: ";
    cin >> nume2;

    try {
        retea.adauga_prietenie(nume1, nume2);
    } catch (const char* mesaj) {
        cout << mesaj << endl;
    }
}

void InterfataUtilizator::sterge_prietenie() {
    string nume1, nume2;

    cout << "Nume1: ";
    cin >> nume1;

    cout << "Nume2: ";
    cin >> nume2;

    try {
        retea.sterge_prietenie(nume1, nume2);
    } catch (const char* mesaj) {
        cout << mesaj << endl;
    }
}

void InterfataUtilizator::afisare_mesaje() {
    string nume1, nume2;

    cout << "Nume1: ";
    cin >> nume1;

    cout << "Nume2: ";
    cin >> nume2;

    try {
        vector<Mesaj> mesaje = retea.get_mesaje(nume1, nume2);

        for (int i = 0; i < mesaje.size(); i++) {
            Mesaj m = mesaje[i];

            cout << "[Expeditor: " << m.get_expeditor().get_nume() << ", Destinatar: " << m.get_destinatar().get_nume() <<"] Text: " << m.get_text() << "]" << endl;
        }
    } catch (const char* mesaj) {
        cout << mesaj << endl;
    }
}

void InterfataUtilizator::adauga_mesaj() {
    string nume1, nume2;
    string mesaj;

    cout << "Nume1: ";
    cin >> nume1;

    cout << "Nume2: ";
    cin >> nume2;

    cout << "Mesaj: ";
    cin >> mesaj;

    try {
        Utilizator u1 = retea.get_utilizator(nume1);
        Utilizator u2 = retea.get_utilizator(nume2);
        retea.adauga_mesaj(Mesaj(mesaj, u1, u2));
    } catch (const char* mesaj) {
        cout << mesaj << endl;
    }
}

void InterfataUtilizator::afisare_evenimente() {
    Lista<Eveniment> evenimente = service_eveniment.get_evenimente();

    for (int i = 0; i < evenimente.get_dimensiune(); i++) {
        Eveniment e = evenimente.get_element(i);

        cout << "[Nume: " << e.get_titlu() << ", Data: " << e.get_data() << ", Locatie: " << e.get_locatie() << ", Descriere: " << e.get_descriere() << "]" << endl;
    }
}

void InterfataUtilizator::adauga_eveniment() {
    string titlu, locatie, descriere;
    Data data;

    cout << "Titlu: ";
    cin >> titlu;

    cout << "Data: ";
    cin >> data;

    cout << "Locatie: ";
    cin >> locatie;

    cout << "Descriere: ";
    cin >> descriere;

    try {
        service_eveniment.adauga_eveniment(Eveniment(titlu, descriere, data, locatie));
    } catch (const char* mesaj) {
        cout << mesaj << endl;
    }
}

void InterfataUtilizator::modifica_eveniment() {
    string titlu;

    cout << "Titlu: ";
    cin >> titlu;

    try {
        Eveniment e = service_eveniment.get_eveniment(titlu);

        Data data;
        string locatie;
        string descriere;
        string titlu_nou;

        cout << "Noul titlu: ";
        cin >> titlu_nou;

        cout << "Noua data: ";
        cin >> data;

        cout << "Noua locatie: ";
        cin >> locatie;

        cout << "Noua descriere: ";
        cin >> descriere;

        Eveniment nou(titlu_nou, descriere, data, locatie);

        service_eveniment.modifica_eveniment(e, nou);
    } catch (const char* mesaj) {
        cout << mesaj << endl;
    }
}

void InterfataUtilizator::sterge_eveniment() {
    string titlu;

    cout << "Titlu: ";
    cin >> titlu;

    try {
        service_eveniment.sterge_eveniment(titlu);
    } catch (const char* mesaj) {
        cout << mesaj << endl;
    }
}

void InterfataUtilizator::adauga_utilizator_participant() {
    string titlu, nume;

    cout << "Titlu eveniment: ";
    cin >> titlu;

    cout << "Nume utilizator: ";
    cin >> nume;

    try {
        Utilizator u = retea.get_utilizator(nume);
        Eveniment e = service_eveniment.get_eveniment(titlu);

        service_eveniment.adauga_utilizator_participant(e, u);
    } catch (const char* mesaj) {
        cout << mesaj << endl;
    }
}

void InterfataUtilizator::afisare_participanti() {
    string titlu;

    cout << "Titlu eveniment: ";
    cin >> titlu;

    try {
        Eveniment e = service_eveniment.get_eveniment(titlu);

        Lista<Utilizator> participanti = service_eveniment.get_participanti(e);

        for (int i = 0; i < participanti.get_dimensiune(); i++) {
            Utilizator u = participanti.get_element(i);

            cout << "[Nume: " << u.get_nume() << ", Prenume: " << u.get_prenume() << ", Email: " << u.get_data_nasterii() << ", data inscrierii: " << u.get_data_inregistrarii() << "]" << endl;
        }
    } catch (const char* mesaj) {
        cout << mesaj << endl;
    }
}




