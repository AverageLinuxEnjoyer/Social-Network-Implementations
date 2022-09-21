#ifndef RETEA_H
#define RETEA_H

#include "multi_dictionar.h"
#include "multime.h"

#include "eveniment.h"
#include "utilizator.h"

#include "mesaj.h"

#include <vector>

class Retea {
public:
    Retea();
    ~Retea();

    Utilizator getDupaId(int id);
    std::vector<Utilizator> getUtilizatori();
    bool adaugareUtilizator(Utilizator user);
    bool modificareUtilizator(int id, Utilizator user);
    bool stergereUtilizator(int id);

    std::vector<Eveniment> getEvenimente();
    bool adaugareEveniment(Eveniment event);
    bool modificareEveniment(int id, Eveniment event);
    bool stergereEveniment(int id);

    bool participareEveniment(int id_user, int id_eveniment);
    bool anulareParticipare(int id_user, int id_eveniment);
    std::vector<Eveniment> getEvenimenteParticipate(int id_user);

    bool adaugarePrietenie(int id_user1, int id_user2);
    bool stergerePrietenie(int id_user1, int id_user2);
    std::vector<Utilizator> getPrieteni(int id_user);

    bool adaugareMesaj(Mesaj mesaj);
    std::vector<Mesaj> getMesaje(int id_user1, int id_user2);

private:
    void citire_utilizatori_din_fisier();
    void citire_evenimente_din_fisier();

    void scriere_utilizatori_in_fisier();
    void scriere_evenimente_in_fisier();

    Multime<Eveniment> evenimente;
    Multime<Utilizator> utilizatori;

    // int1 -> id user, int2 -> id eveniment
    MultiDict<int, int> evenimente_participate;

    // int1 -> id user, int2 -> id prieten
    MultiDict<int, int> prieteni;

    std::vector<Mesaj> mesaje;
};

#endif // RETEA_H
