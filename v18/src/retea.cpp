#include "../include/retea.h"
#include <fstream>
#include <sstream>
#include <iomanip>

Retea::Retea(bool read_write_file)
    : read_write_file(read_write_file)
{
    if (read_write_file) {
        // citeste useri din fisiere
        std::ifstream file("utilizatori.txt");
        std::string line;
        while (std::getline(file, line)) {
            std::stringstream ss(line);
            std::string username;
            int varsta;
            std::string email;
            ss >> username >> varsta >> email;
            utilizatori.adaugare(username, Utilizator(username, varsta, email));
        }

        // citeste evenimente din fisier
        std::ifstream file2("evenimente.txt");
        std::string line2;
        while (std::getline(file2, line2)) {
            std::stringstream ss(line2);
            std::string nume;
            std::string locatie;
            std::string descriere;
            std::string data;
            ss >> std::quoted(nume) >> std::quoted(locatie) >> std::quoted(descriere) >> data;
            evenimente.inserare_sfarsit(Eveniment(nume, locatie, descriere, data));
        }

        // citeste friendship-uri din fisier
        std::ifstream file3("friendships.txt");
        std::string line3;
        while (std::getline(file3, line3)) {
            std::stringstream ss(line3);
            std::string username1;
            std::string username2;
            ss >> username1 >> username2;
            this->adaugarePrietenie(username1, username2);
        }

        // citeste mesaje din fisier
        std::ifstream file4("mesaje.txt");
        std::string line4;
        while (std::getline(file4, line4)) {
            std::stringstream ss(line4);
            std::string sender_username;
            std::string receiver_username;
            std::string message;
            ss >> sender_username >> receiver_username >> std::quoted(message);
            this->trimitereMesaj(sender_username, receiver_username, message);
        }
    }

}

Retea::~Retea()
{
    if (read_write_file) {
        // scrie useri in fisier
        std::ofstream file("utilizatori.txt");
        for (auto &user : utilizatori) {
            file << user.getUsername() << " " << user.getVarsta() << " " << user.getEmail() << std::endl;
        }

        // scrie evenimente in fisier
        // if the variable has multiple words, use std::quoted()
        std::ofstream file2("evenimente.txt");
        for (int i = 0; i < evenimente.size(); i++) {
            file2 << std::quoted(evenimente[i].getNume()) << " " << std::quoted(evenimente[i].getLocatie()) << " " << std::quoted(evenimente[i].getDescriere()) << " " << evenimente[i].getDate() << std::endl;
        }

        // adaugare prietenii intr-un vector
        std::ofstream file3("friendships.txt");
        std::vector<std::pair<std::string, std::string>> friendships;;
        for (auto &user : utilizatori) {
            for (auto &friendship : user.getFriends()) {
                friendships.push_back(std::make_pair(
                    friendship.getUser1()->getUsername(),
                     friendship.getUser2()->getUsername()
                ));
            }
        }

        // stergere prietenii duplicate
        for (int i = 0; i < friendships.size(); i++) {
            for (int j = i + 1; j < friendships.size(); j++) {
                if ((friendships[i].first == friendships[j].first && friendships[i].second == friendships[j].second) || 
                    (friendships[i].first == friendships[j].second && friendships[i].second == friendships[j].first)) {
                    friendships.erase(friendships.begin() + j);
                    j--;
                }
            }
        }

        // scriere prietenii in fisier
        for (auto &friendship : friendships) {
            file3 << friendship.first << " " << friendship.second << std::endl;
        }

        // adaugare mesaje intr-un vector
        std::ofstream file4("mesaje.txt");
        std::vector<Mesaj> mesaje;;
        for (auto &user : utilizatori) {
            for (auto &message : user.getMesaje()) {
                mesaje.push_back(message);
            }
        }

        // stergerea mesajelor duplicate
        for (int i = 0; i < mesaje.size(); i++) {
            for (int j = i + 1; j < mesaje.size(); j++) {
                if ((mesaje[i].user_expeditor->getUsername() == mesaje[j].user_expeditor->getUsername() && mesaje[i].user_destinatar->getUsername() == mesaje[j].user_destinatar->getUsername() && mesaje[i].continut == mesaje[j].continut) || (mesaje[i].user_expeditor->getUsername() == mesaje[j].user_destinatar->getUsername() && mesaje[i].user_destinatar->getUsername() == mesaje[j].user_expeditor->getUsername() && mesaje[i].continut == mesaje[j].continut)) {
                    mesaje.erase(mesaje.begin() + j);
                    j--;
                }
            }
        }

        // scrierea mesajelor in fisier
        for (auto &message : mesaje) {
            file4 << message.user_expeditor->getUsername() << " " << message.user_destinatar->getUsername() << " " << std::quoted(message.continut) << std::endl;
        }
    }
}

bool Retea::adaugareUtilizator(std::string username, int varsta, std::string email) {
    // check if the usernames are unique
    if (utilizatori.contine(username))
        return false;

    utilizatori.adaugare(username, Utilizator(username, varsta, email));
    return true;
}

bool Retea::updateUtilizator(std::string username, std::string newUsername, int newAge, std::string newEmail) {
    // find user
    if (!utilizatori.contine(username))
        return false;

    Utilizator* user = &utilizatori[username];
    
    for(auto& user2 : utilizatori)
        if (user2.getUsername() == newUsername && *user != user2)
            return false;

    utilizatori.schimbare_cheie(username, newUsername);
    user->setUsername(newUsername);
    user->setVarsta(newAge);
    user->setEmail(newEmail);
    return true;
}

bool Retea::stergereUtiliztor(std::string username) {
    // find user
    if (!utilizatori.contine(username))
        return false;

    Utilizator* user = &utilizatori[username];

    // stergere friendships of the user and its prieteni
    for (int j = 0; j < user->getFriends().size(); j++)
        stergerePrietenie(user->getUsername(), user->getFriends()[j].getUser2()->getUsername());

    // stergere the user
    for (auto &user2 : utilizatori)
        user2.stergerePrieten(*user);

    utilizatori.stergere(username);
    
    return true;
}

bool Retea::adaugarePrietenie(std::string username1, std::string username2) {
    // find utilizatori
    if (!utilizatori.contine(username1) || !utilizatori.contine(username2))
        return false;

    Utilizator *user1 = &utilizatori[username1];
    Utilizator *user2 = &utilizatori[username2];

    // check if friendship already exists
    for (int i = 0; i < user1->getFriends().size(); i++) {
        if (user1->getFriends()[i].getUser1() == user1 && user1->getFriends()[i].getUser2() == user2) {
            return false;
        }
    }

    // adaugare friendship
    user1->adaugarePrieten(*user2);
    user2->adaugarePrieten(*user1);
    return true;
}

bool Retea::stergerePrietenie(std::string username1, std::string username2) {
    // find utilizatori
    if (!utilizatori.contine(username1) || !utilizatori.contine(username2))
        return false;

    Utilizator *user1 = &utilizatori[username1];
    Utilizator *user2 = &utilizatori[username2];

    // check if friendship exists
    for (int i = 0; i < user1->getFriends().size(); i++) {
        if (user1->getFriends()[i].getUser1() == user1 && user1->getFriends()[i].getUser2() == user2) {
            user1->stergerePrieten(*user2);
            user2->stergerePrieten(*user1);
            return true;
        }
    }

    return false;
}

bool Retea::trimitereMesaj(std::string sender_username, std::string receiver_username, std::string message) {
    // find utilizatori
    if (!utilizatori.contine(sender_username) || !utilizatori.contine(receiver_username))
        return false;

    Utilizator *user_expeditor = &utilizatori[sender_username];
    Utilizator *user_destinatar = &utilizatori[receiver_username];

    user_expeditor->trimitereMesaj(*user_destinatar, message);

    return true;
}

Lista<Utilizator*> Retea::getUtilizatori() {
    Lista<Utilizator*> list;
    for (auto& user : utilizatori)
        list.inserare_sfarsit(&user);

    return list;
}


bool Retea::adaugareEveniment(std::string nume, std::string locatie, std::string descriere, std::string data) {
    // check if the event names are unique
    for (int i = 0; i < evenimente.size(); i++)
        if (evenimente[i].getNume() == nume)
            return false;

    evenimente.inserare_sfarsit(Eveniment(nume, locatie, descriere, data));

    return true;
}

Lista<Eveniment> Retea::getEvenimente() {
    return evenimente;
}

bool Retea::updateEveniment(std::string nume, std::string newName, std::string newLocation, std::string newDescription, std::string newDate) {
    for (int i = 0; i < evenimente.size(); i++)
    {
        if (evenimente[i].getNume() == nume)
        {
            // check if the event names are unique
            for (int j = 0; j < evenimente.size(); j++)
                if (evenimente[j].getNume() == newName && i != j)
                    return false;
                    
            evenimente[i].setNume(newName);
            evenimente[i].setLocatie(newLocation);
            evenimente[i].setDescriere(newDescription);
            evenimente[i].setDate(newDate);

            return true;
        }
    }

    return false;
}

bool Retea::stergereEveniment(std::string nume) {
    for (int i = 0; i < evenimente.size(); i++)
    {
        if (evenimente[i].getNume() == nume)
        {
            evenimente.stergere(i);
            return true;
        }
    }

    return false;
}

bool Retea::adaugareParticipantEveniiment(std::string event_name, std::string username) {
    // find event
    Eveniment *event = nullptr;
    for (int i = 0; i < evenimente.size(); i++)
    {
        if (evenimente[i].getNume() == event_name)
        {
            event = &evenimente[i];
            break;
        }
    }
    // check if event exists
    if (event == nullptr)
        return false;

    // find user
    if (!utilizatori.contine(username))
        return false;

    Utilizator *user = &utilizatori[username];

    event->adaugare_utilizator_interesat(user);

    return true;
}
