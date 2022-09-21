#ifndef PRIETENIE_H
#define PRIETENIE_H

#include "Utilizator.h"
#include "Data.h"

class Prietenie {
public:
    Prietenie();
    Prietenie(Utilizator utilizator1, Utilizator utilizator2);
    Prietenie(const Prietenie& prietenie);
    Prietenie& operator=(const Prietenie& prietenie);
    Utilizator get_utilizator1() const;
    Utilizator get_utilizator2() const;
    Data get_data() const;
    int get_durata_prietenie() const;
    void set_utilizator1(Utilizator utilizator1);
    void set_utilizator2(Utilizator utilizator2);
    void set_data(Data data);
    bool operator==(const Prietenie& prietenie) const;
    bool operator!=(const Prietenie& prietenie) const;

private:
    Utilizator utilizator1;
    Utilizator utilizator2;
    Data data_prietenie;
};

#endif // PRIETENIE_H
