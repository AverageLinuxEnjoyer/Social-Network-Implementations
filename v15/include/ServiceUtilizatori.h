#ifndef SERVICEUTILIZATORI_H
#define SERVICEUTILIZATORI_H

#include "Repo.h"
#include "Utilizator.h"
#include "MultiDictionar.h"
#include "Pereche.h"

class ServiceUtilizatori {
public:
    ServiceUtilizatori(Repo<Utilizator>& repo, std::string messages_file_name = "");
    ~ServiceUtilizatori();

    void addUtilizator(const Utilizator& utilizator);
    void updateUtilizator(int id, const Utilizator& utilizator);
    void deleteUtilizator(int id);
    Utilizator getUtilizator(int id);
    Lista<Utilizator>& getAll();

    void adaugarePrieten(int id_utilizator, int id_prieten);
    Lista<int> getPrieteni(int id_utilizator);

    void participareEveniment(int id_utilizator, int id_eveniment);
    Lista<int> getEvenimenteParticipate(int id_utilizator);

    void trimiteMesaj(int utilizator1, int utilizator2, const std::string& mesaj);
    Lista<Mesaj> getMesaje(int id_utilizator1, int id_utilizator2);

private:
    void loadMessagesFromFile();
    void saveMessagesToFile();

    Repo<Utilizator>& repo;
    MultiDictionar<Pereche, Mesaj> mesaje;
    std::string messages_file_name;
};

#endif // SERVICEUTILIZATORI_H
