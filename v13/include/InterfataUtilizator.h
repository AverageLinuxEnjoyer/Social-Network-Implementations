#ifndef INTERFATAUTILIZATOR_H
#define INTERFATAUTILIZATOR_H

#include "Retea.h"
#include "ServiceEveniment.h"
#include <valarray>

class InterfataUtilizator {
public:
    InterfataUtilizator() = default;
    InterfataUtilizator(const InterfataUtilizator& interfata) = default;
    InterfataUtilizator& operator=(const InterfataUtilizator& interfata) = default;
    ~InterfataUtilizator() = default;

    void porneste();

private:

    void afisare_meniu();

    void afisare_utilizatori();
    void adauga_utilizator();
    void modifica_utilizator();
    void sterge_utilizator();

    void afisare_prietenii();
    void afisare_prieteni();
    void adauga_prietenie();
    void sterge_prietenie();

    void afisare_mesaje();
    void adauga_mesaj();


    void afisare_evenimente();
    void adauga_eveniment();
    void modifica_eveniment();
    void sterge_eveniment();
    void adauga_utilizator_participant();
    void afisare_participanti();

    Retea retea;
    ServiceEveniment service_eveniment;
};

#endif // INTERFATAUTILIZATOR_H
