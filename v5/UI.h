#ifndef UI_H
#define UI_H

#include "Retea.h"

class UI {
private:
    Retea retea;

public:
    UI();
    ~UI();

    void run();

    void print_menu();
    
    void show_users();
    void show_prieteni();
    void show_mesaje();

    void add_user();
    void add_prietenie();
    void add_mesaj();

    void update_user();

    void delete_user();
    void delete_prietenie();

};

#endif // UI_H
