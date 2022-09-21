#ifndef SERVICEEVENIMENTE_H
#define SERVICEEVENIMENTE_H

#include "Eveniment.h"
#include "Repo.h"

class ServiceEvenimente {
public:
    ServiceEvenimente(Repo<Eveniment>& repo, std::string messages_file_name = "");
    ~ServiceEvenimente();

    void addEveniment(const Eveniment& eveniment);
    void updateEveniment(int id, const Eveniment& eveniment);
    void deleteEveniment(int id);
    Eveniment getEveniment(int id);
    Lista<Eveniment>& getAll();

    void adaugareParticipant(int id_eveniment, int id_participant);
    Lista<int> getParticipanti(int id_eveniment);

private:
    void loadParticipantsFromFile();
    void saveParticipantsToFile();

    Repo<Eveniment>& repo;
    std::string messages_file_name;
};

#endif // SERVICEEVENIMENTE_H
