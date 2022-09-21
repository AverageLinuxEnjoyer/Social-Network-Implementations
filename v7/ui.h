#ifndef UI_H
#define UI_H

#include "retea.h"

class UI {
public:
    UI();
    ~UI();
    void run();

private:

    void meniu_adaugare_utilizator();
    void meniu_stergere_utilizator();
    void meniu_modificare_utilizator();
    void get_all_utilizatori();

    void meniu_adaugare_eveniment();
    void meniu_stergere_eveniment();
    void meniu_modificare_eveniment();
    void get_all_evenimente();

    void meniu_adaugare_prietenie();
    void meniu_stergere_prietenie();
    void get_prieteni();

    void meniu_adaugare_mesaj();
    void meniu_stergere_mesaj();
    void get_mesaje();

private:
    Retea retea;
};

#endif // UI_H
