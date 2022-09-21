#ifndef USER_INTERFACE_H
#define USER_INTERFACE_H

#include "ServiceUtilizator.h"
#include "ServiceEveniment.h"

class Interfata {
private:
    ServiceUtilizatori serviceUtilizatori;
    ServiceEvenimente serviceEvenimente;

    void afisare_utilizatori();
    void afisare_utilizator();
    void adaugare_utilizator();
    void update_utilizator();
    void stergere_utilizator();

    void adaugare_prieten();
    void stergere_prieten();
    void afisare_prieteni();

    void adaugare_mesaj();
    void afisare_mesaj();
    void stergere_mesaje();


    void afisare_evenimente();
    void afisare_eveniment();
    void adaugare_eveniment();
    void modificare_eveniment();
    void stergere_eveniment();

    void adaugare_participant();
    void stergere_participant();
    void afisare_participanti();

public:
    void start();
};

#endif // USER_INTERFACE_H
