#ifndef UTILIZATOR_H
#define UTILIZATOR_H

#include "Data.h"
#include <string>
using namespace std;

class Utilizator {
public:
    Utilizator();
    Utilizator(string nume, string prenume, Data dataNasterii);
    Utilizator(const Utilizator& utilizator);
    Utilizator& operator=(const Utilizator& utilizator);
    string get_nume() const;
    string get_prenume() const;
    Data get_data_nasterii() const;
    Data get_data_inregistrarii() const;
    int get_varsta() const;
    void set_nume(string nume);
    void set_prenume(string prenume);
    void set_data_nasterii(Data dataNasterii);
    void set_data_inregistrarii(Data dataInregistrarii);
    bool operator==(const Utilizator& utilizator) const;
    bool operator!=(const Utilizator& utilizator) const;

private:
    string nume;
    string prenume;
    Data data_nasterii;
    Data data_inregistrarii;
};

#endif // UTILIZATOR_H
