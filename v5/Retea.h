#ifndef RETEA_H
#define RETEA_H


#include "Mesaj.h"

#include "multi_dictionar.h"

#include "multime.h"

#include "Prietenie.h"

#include "User.h"


class Retea {

public:
    Retea();
    ~Retea();

    void generare_utilizatori();

    User get_user(string nume);

    vector<User> get_users();

    vector<string> get_prieteni(string nume);

    vector<Mesaj> get_mesaje(string nume);


    void inserare_user(User user);

    void inserare_prietenie(Prietenie prietenie);

    void inserare_mesaj(Mesaj mesaj);


    void update_user(string nume, User user);

    void stergere_user(string nume);

    void stergere_prietenie(Prietenie prietenie);

private:

    Multime<User> users;
    Multi_Dictionar<string, string> prieteni;
    Multi_Dictionar<string, Mesaj> mesaje;

};

#endif // RETEA_H
