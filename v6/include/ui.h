#ifndef UI_H
#define UI_H

#include "retea.h"

class UI {
public:
    void run();

private:
    void add_user();
    void edit_user();
    void remove_user();
    void print_users();
    void add_prietenie();
    void remove_prietenie();
    void print_prietenii();
    void add_mesaj();
    void remove_mesaje();
    void print_mesaje();

    Retea r;
};

#endif // UI_H
