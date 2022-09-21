#ifndef RETEA_H
#define RETEA_H

#include "utilizator.h"
#include "eveniment.h"
#include "dictionar.h"
#include <string>

class Retea {
public:
    Retea(bool read_write_file = false);
    ~Retea();

    Retea(const Retea &other) = delete;
    Retea &operator=(const Retea &other) = delete;

    bool adaugareUtilizator(std::string username, int varsta, std::string email);

    bool updateUtilizator(std::string username, std::string newUsername, int newAge, std::string newEmail);

    bool stergereUtiliztor(std::string username);

    bool adaugarePrietenie(std::string username1, std::string username2);

    bool stergerePrietenie(std::string username1, std::string username2);

    bool trimitereMesaj(std::string sender_username, std::string receiver_username, std::string message);

    Lista<Utilizator*> getUtilizatori();

    bool adaugareEveniment(std::string nume, std::string locatie, std::string descriere, std::string data);

    bool updateEveniment(std::string nume, std::string newName, std::string newLocation, std::string newDescription, std::string newDate);

    bool stergereEveniment(std::string nume);

    bool adaugareParticipantEveniiment(std::string event_name, std::string username);

    Lista<Eveniment> getEvenimente();

private:
    Dictionar<std::string, Utilizator> utilizatori;
    Lista<Eveniment> evenimente;

    bool read_write_file;
};

#endif // RETEA_H
