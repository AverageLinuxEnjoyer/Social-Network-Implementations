#ifndef RETEA_H
#define RETEA_H

#include "Eveniment.h"
#include "Mesaj.h"
#include "Prietenie.h"
#include "Utilizator.h"
#include "TAD_Lista.h"
#include "TAD_MultimeOrdonata.h"
#include "FileManager.h"

class Retea {
private:
    MultimeOrdonata<Utilizator> utilizatori;
    Lista<Eveniment> evenimente;
    Lista<Mesaj> mesaje;
    Lista<Prietenie> prietenii;

    FileManager fileManager;

    bool existaUtilizator(int id);
    bool existaEveniment(int id);
    bool existaMesaj(int id);

public:
    Retea();
    ~Retea();

    void adaugaUtilizator(Utilizator utilizator);
    void adaugaEveniment(Eveniment eveniment);
    void adaugaMesaj(Mesaj mesaj);
    void adaugaPrietenie(int id1, int id2);

    void stergeUtilizator(int id);
    void stergeEveniment(int id);
    void stergeMesaj(int id);
    void stergePrietenie(int id1, int id2);

    void modificaUtilizator(Utilizator utilizator);
    void modificaEveniment(Eveniment eveniment);

    Utilizator getUtilizator(int id);
    Eveniment getEveniment(int id);
    Mesaj getMesaj(int id);
    Lista<Mesaj> getMesaje(int id1, int id2);
    Lista<Utilizator> getPrieteni(int id);

    Lista<Utilizator> getUtilizatori();
    Lista<Eveniment> getEvenimente();
    Lista<Mesaj> getMesaje();
    Lista<Prietenie> getPrietenii();
};

#endif // RETEA_H
