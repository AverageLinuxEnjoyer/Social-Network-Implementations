#ifndef UI_H
#define UI_H

#include "ServiceEvenimente.h"
#include "ServiceUtilizatori.h"

class UI {
public:
    UI(ServiceUtilizatori& service_utilizatori, ServiceEvenimente& service_evenimente);
    
    void run();
private:
    void afisare_utilizatori();
    void adaugare_utilizator();
    void modificare_utilizator();
    void stergere_utilizator();
    void afisare_evenimete_participate();

    void afisare_prieteni();
    void adaugare_prieten();

    void afisare_evenimente();
    void adaugare_eveniment();
    void modificare_eveniment();
    void stergere_eveniment();

    void participare_eveniment();
    void afisare_participanti_eveniment();

    void trimitereMesaj();
    void afisare_mesaje();

    ServiceUtilizatori& serviceUtilizatori;
    ServiceEvenimente& serviceEvenimente;
};

#endif // UI_H
