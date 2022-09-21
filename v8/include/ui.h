#ifndef UI_H
#define UI_H

#include "Retea.h"

class UI {
public:
    UI();
    ~UI();

    void run();

    void adaugaUtilizator();
    void adaugaEveniment();
    void adaugaMesaj();
    void adaugaPrietenie();

    void stergeUtilizator();
    void stergeEveniment();
    void stergeMesaj();
    void stergePrietenie();

    void modificaUtilizator();
    void modificaEveniment();
    
    void afisareUtilizatori();
    void afisareEvenimente();
    void afisareMesaje();
    void afisareMesajeIntreUtilizatori();
    void afisarePrietenii();
    void afisarePrieteni();

private:
    Retea retea;
};

#endif // UI_H
