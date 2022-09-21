#include "UI.h"

UI::UI()
{
    
}

UI::~UI()
{
    
}

void UI::run() {
    int optiune;
    while (true) {
        print_menu();
        cin >> optiune;
        switch (optiune) {
            case 1:
                show_users();
                break;
            case 2:
                show_prieteni();
                break;
            case 3:
                show_mesaje();
                break;
            case 4:
                add_user();
                break;
            case 5:
                add_prietenie();
                break;
            case 6:
                add_mesaj();
                break;
            case 7:
                update_user();
                break;
            case 8:
                delete_user();
                break;
            case 9:
                delete_prietenie();
                break;
            case 10:
                return;
            default:
                cout << "Optiune invalida!" << endl;
                break;
        }
    }
}

void UI::print_menu() {
    cout << "1. Afisare utilizatori" << endl;
    cout << "2. Afisare prieteni" << endl;
    cout << "3. Afisare mesaje" << endl;
    cout << "4. Adaugare utilizator" << endl;
    cout << "5. Adaugare prietenie" << endl;
    cout << "6. Adaugare mesaj" << endl;
    cout << "7. Update utilizator" << endl;
    cout << "8. Stergere utilizator" << endl;
    cout << "9. Stergere prietenie" << endl;
    cout << "10. Iesire" << endl;
}

void UI::show_users() {
    vector<User> users_ = retea.get_users();
    for (int i = 0; i < users_.size(); i++) {
        cout << users_[i].getNume()  << " " << users_[i].getPrenume() << " " << users_[i].getVarsta() << endl;
    }
}

void UI::show_prieteni() {
    string nume;
    cout << "Introduceti numele utilizatorului: ";
    cin >> nume;
    vector<string> prieteni_ = retea.get_prieteni(nume);
    for (int i = 0; i < prieteni_.size(); i++) {
        cout << prieteni_[i] << endl;
    }
}

void UI::show_mesaje() {
    string nume;
    cout << "Introduceti numele utilizatorului: ";
    cin >> nume;
    vector<Mesaj> mesaje_ = retea.get_mesaje(nume);
    for (int i = 0; i < mesaje_.size(); i++) {
        cout << mesaje_[i].getNume_user1() << "-" << mesaje_[i].getNume_user2() << ":" << mesaje_[i].getMesaj() << endl;
    }
}

void UI::add_user() {
    string nume, prenume;
    int varsta;

    cout << "Introduceti numele: ";
    cin >> nume;
    cout << "Introduceti prenumele: ";
    cin >> prenume;
    cout << "Introduceti varsta: ";
    cin >> varsta;

    User user(nume, prenume, varsta);

    try 
    {
        retea.inserare_user(user);
    } catch (const char* msg) 
    {
        cout << msg << endl;
    }
}

void UI::add_prietenie() {
    string nume1, nume2;

    cout << "Introduceti numele utilizatorului 1: ";
    cin >> nume1;
    cout << "Introduceti numele utilizatorului 2: ";
    cin >> nume2;

    Prietenie prietenie(nume1, nume2);

    try
    {
        retea.inserare_prietenie(prietenie);
    } catch (const char* msg) 
    {
        cout << msg << endl;
    }
}

void UI::add_mesaj() {
    string nume1, nume2, mesaj;

    cout << "Introduceti numele utilizatorului 1: ";
    cin >> nume1;
    cout << "Introduceti numele utilizatorului 2: ";
    cin >> nume2;
    cout << "Introduceti mesajul: ";
    cin >> mesaj;

    Mesaj mesaj_ = Mesaj(nume1, nume2, mesaj);

    try 
    {
        retea.inserare_mesaj(mesaj_);
    } catch (const char* msg) 
    {
        cout << msg << endl;
    }
}

void UI::update_user() {
    string nume, prenume, nume_nou;
    int varsta;

    cout << "Introduceti numele utilizatorului: ";
    cin >> nume;

    User user = retea.get_user(nume);

    cout << "Introduceti numele nou: ";
    cin >> nume_nou;

    user.setNume(nume_nou);

    cout << "Introduceti prenumele nou: ";
    cin >> prenume;

    user.setPrenume(prenume);

    cout << "Introduceti varsta noua: ";
    cin >> varsta;

    user.setVarsta(varsta);

    try 
    {
        retea.update_user(nume, user);
    } catch (const char* msg) 
    {
        cout << msg << endl;
    }
}

void UI::delete_user() {
    string nume;

    cout << "Introduceti numele utilizatorului: ";
    cin >> nume;

    try 
    {
        retea.stergere_user(nume);
    } catch (const char* msg) 
    {
        cout << msg << endl;
    }
}

void UI::delete_prietenie() {
    string nume1, nume2;

    cout << "Introduceti numele utilizatorului 1: ";
    cin >> nume1;
    cout << "Introduceti numele utilizatorului 2: ";
    cin >> nume2;

    try 
    {
        retea.stergere_prietenie(Prietenie(nume1, nume2));
    } catch (const char* msg) 
    {
        cout << msg << endl;
    }
}


