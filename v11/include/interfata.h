#ifndef INTERFATA_H
#define INTERFATA_H

#include "retea.h"

class Interfata {
public:
    void run();

    void meniu_afisare_utilizatori();
    void meniu_adaugare_utilizatori();
    void meniu_modificare_utilizatori();
    void meniu_stergere_utilizatori();

    void meniu_afisare_evenimente();
    void meniu_adaugare_evenimente();
    void meniu_modificare_evenimente();
    void meniu_stergere_evenimente();

    void meniu_afisare_evenimente_participate();
    void meniu_participare_eveniment();
    void meniu_anulare_participare();

    void meniu_afisare_prieteni();
    void meniu_adaugare_prieteni();
    void meniu_stergere_prieteni();

    void meniu_afisare_mesaje();
    void meniu_adaugare_mesaje();

private:
    Retea retea;
};

#endif // INTERFATA_H
