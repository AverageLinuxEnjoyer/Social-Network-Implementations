#ifndef UTILIZATOR_H
#define UTILIZATOR_H

#include <iostream>
#include <string>
#include "Lista.h"
#include "MultiDictionar.h"
#include "Mesaj.h"

class Utilizator {
public:
    Utilizator();
    Utilizator(int id, std::string nume, std::string prenume, int varsta, std::string email, std::string parola);
    Utilizator(const Utilizator& other);
    ~Utilizator();

    Utilizator& operator=(const Utilizator& other);
    bool operator==(const Utilizator& other) const;

    std::string getNume() const;
    void setNume(const std::string &nume_);

    std::string getPrenume() const;
    void setPrenume(const std::string &prenume_);

    int getVarsta() const;
    void setVarsta(int varsta_);

    std::string getEmail() const;
    void setEmail(const std::string &email_);

    std::string getParola() const;
    void setParola(const std::string &parola_);

    Lista<int> getPrieteni() const;
    void adaugaPrieten(int id);

    Lista<int> getEvenimente() const;
    void adaugaEveniment(int id);

    int getId() const;

    friend std::ostream& operator<<(std::ostream& out, const Utilizator& utilizator);
    friend std::istream& operator>>(std::istream& in, Utilizator& utilizator);

private:
    int id;
    std::string nume;
    std::string prenume;
    int varsta;
    std::string email;
    std::string parola;
    Lista<int> prieteni;
    Lista<int> evenimente;
};

#endif // UTILIZATOR_H
