#include "../include/ui.h"
#include <set>

void UI::run() {
    int cmd;
    while (true) {
        std::cout << "1. Adauga user\n";
        std::cout << "2. Editeaza user\n";
        std::cout << "3. Sterge user\n";
        std::cout << "4. Afiseaza useri\n";
        std::cout << "5. Adauga prietenie\n";
        std::cout << "6. Sterge prietenie\n";
        std::cout << "7. Afiseaza prietenii\n";
        std::cout << "8. Adauga mesaj\n";
        std::cout << "9. Sterge mesaje\n";
        std::cout << "10. Afiseaza mesaje\n";
        std::cout << "0. Iesire\n";
        std::cout << "Comanda: ";
        std::cin >> cmd;
        std::cin.ignore();
        switch (cmd) {
            case 1:
                add_user();
                break;
            case 2:
                edit_user();
                break;
            case 3:
                remove_user();
                break;
            case 4:
                print_users();
                break;
            case 5:
                add_prietenie();
                break;
            case 6:
                remove_prietenie();
                break;
            case 7:
                print_prietenii();
                break;
            case 8:
                add_mesaj();
                break;
            case 9:
                remove_mesaje();
                break;
            case 10:
                print_mesaje();
                break;
        }
    }
}

void UI::add_user() {
    User user;
    std::cin >> user;

    try {
        r.addUser(user);
    } catch (const char* msg) {
        std::cout << msg << std::endl;
    }
}

void UI::edit_user() {
    int id;
    std::cout << "Id: ";
    std::cin >> id;

    try {
        User user = r.getUser(id);
        std::cin >> user;
        r.editUser(id, user);
    } catch (const char* msg) {
        std::cout << msg << std::endl;
    }
}

void UI::remove_user() {
    int id;
    std::cout << "Id: ";
    std::cin >> id;

    try {
        r.removeUser(id);
    } catch (const char* msg) {
        std::cout << msg << std::endl;
    }
}

void UI::print_users() {
    List<User> users = r.getUsers();
    for (int i = 0; i < users.size(); i++) {
        std::cout << users.get(i) << std::endl;
    }
}

void UI::add_prietenie() {
    int id1, id2;
    std::cout << "Id1: ";
    std::cin >> id1;
    std::cout << "Id2: ";
    std::cin >> id2;

    try {
        r.addPrietenie(id1, id2);
    } catch (const char* msg) {
        std::cout << msg << std::endl;
    }
}

void UI::remove_prietenie() {
    int id1, id2;
    std::cout << "Id1: ";
    std::cin >> id1;
    std::cout << "Id2: ";
    std::cin >> id2;

    try {
        r.removePrietenie(id1, id2);
    } catch (const char* msg) {
        std::cout << msg << std::endl;
    }
}

void UI::print_prietenii() {
    List<Prietenie> prieteni = r.getPrietenii();
    for (int i = 0; i < prieteni.size(); i++) {
        std::cout << prieteni.get(i) << std::endl;
    }
}

void UI::add_mesaj() {
    int id1, id2;
    std::string text;
    std::cout << "Id1: ";
    std::cin >> id1;
    std::cout << "Id2: ";
    std::cin >> id2;
    std::cout << "Text: ";
    std::getline(std::cin, text);

    try {
        r.addMesaj(id1, id2, text);
    } catch (const char* msg) {
        std::cout << msg << std::endl;
    }
}

void UI::remove_mesaje() {
    int id1, id2;
    std::cout << "Id1: ";
    std::cin >> id1;
    std::cout << "Id2: ";
    std::cin >> id2;

    try {
        r.removeMesaje(id1, id2);
    } catch (const char* msg) {
        std::cout << msg << std::endl;
    }
}

void UI::print_mesaje() {
    int id1, id2;
    std::cout << "Id1: ";
    std::cin >> id1;

    std::cout << "Id2: ";
    std::cin >> id2;

    try {
        List<Mesaj> mesaje = r.getMesaje(id1, id2);
        for (int i = 0; i < mesaje.size(); i++) {
            std::cout << mesaje.get(i) << std::endl;
        }
    } catch (const char* msg) {
        std::cout << msg << std::endl;
    }
}



