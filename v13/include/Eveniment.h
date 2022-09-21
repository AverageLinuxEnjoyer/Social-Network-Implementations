#ifndef EVENIMENT_H
#define EVENIMENT_H

#include "Data.h"
#include "Lista.h"
#include "Utilizator.h"

class Eveniment {
public:
    Eveniment();
    Eveniment(string titlu, string descriere, Data data, string locatie);
    Eveniment(const Eveniment& eveniment);
    Eveniment& operator=(const Eveniment& eveniment);
    string get_titlu() const;
    string get_descriere() const;
    Data get_data() const;
    string get_locatie() const;
    void set_titlu(string titlu);
    void set_descriere(string descriere);
    void set_data(Data data);
    void set_locatie(string locatie);
    bool operator==(const Eveniment& eveniment) const;
    bool operator!=(const Eveniment& eveniment) const;

    Lista<Utilizator> get_utilizatori_participanti() const;
    void adauga_utilizator_participant(Utilizator utilizator);

private:
    string titlu;
    string descriere;
    Data data;
    string locatie;
    Lista<Utilizator> utilizatori_participanti;
};

#endif // EVENIMENT_H
