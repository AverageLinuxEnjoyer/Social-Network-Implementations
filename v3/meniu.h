#pragma once

#include "retea.h"

class Meniu {
public:
    void runMeniu();

    void addUser();
    void updateUser();
    void removeUser();
    void getUsers();

    void addEveniment();
    void updateEveniment();
    void removeEveniment();
    void getEvenimente();

    void addMesaj();
    void getMesaje();

    void addPrietenie();
    void removePrietenie();
    void getPrieteni();

private:
    Retea retea;
};