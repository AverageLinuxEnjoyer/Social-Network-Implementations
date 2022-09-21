#ifndef RETEA_H
#define RETEA_H

#include "RepoFile.h"
#include "Prietenie.h"
#include "Utilizator.h"
#include "Mesaj.h"
#include "Eveniment.h"

class Retea {
private:
    RepoFile<Utilizator> utilizatori;
    RepoFile<Eveniment> evenimente;
    RepoFile<Prietenie> prieteni;
    RepoFile<Mesaj> mesaje;

public:
    Retea();
    ~Retea();

    void addUtilizator(Utilizator utilizator);
    void removeUtilizator(std::string nume);
    void updateUtilizator(std::string nume, Utilizator utilizator);
    Utilizator getUtilizator(std::string nume);
    List<Utilizator> getUtilizatori();

    void addEveniment(Eveniment eveniment);
    void removeEveniment(std::string nume);
    void updateEveniment(std::string nume, Eveniment eveniment);
    Eveniment getEveniment(std::string nume);
    List<Eveniment> getEvenimente();

    void addPrietenie(std::string nume1, std::string nume2);
    void removePrietenie(std::string nume1, std::string nume2);
    List<Prietenie> getPrieteni();

    void sendMesaj(std::string nume1, std::string nume2, std::string content);
    List<Mesaj> getMesaje();
};

#endif // RETEA_H
