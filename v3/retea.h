#pragma once

#include <iostream>
using namespace std;

#include "multi_dictionary.h"
#include "Set.h"
#include "Eveniment.h"
#include "User.h"
#include "mesaj.h"

class Retea {
public:
    Retea();
    ~Retea();

    void addUser(User user);
    void updateUser(int id, User user);
    void removeUser(int id);
    vector<User> getUsers();

    void addEveniment(Eveniment eveniment);
    void updateEveniment(int id, Eveniment eveniment);
    void removeEveniment(int id);
    vector<Eveniment> getEvenimente();

    void addMesaj(Mesaj mesaj);
    vector<Mesaj> getMesaje();

    void addPrietenie(int id1, int id2);
    void removePrietenie(int id1, int id2);
    vector<User> getPrieteni(int id);

    User getUser(int id);

private:
    MultiDictionar<int, int> prietenii;
    Set<Mesaj> mesaje;
    Set<Eveniment> evenimente;
    Set<User> users;
};