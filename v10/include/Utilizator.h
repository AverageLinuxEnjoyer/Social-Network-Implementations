#ifndef USER_H
#define USER_H

#include <iostream>
#include "Lista.h"

class Utilizator {
public:
    Utilizator();
    Utilizator(const Utilizator& other) = default;
    Utilizator(int id, std::string nume, int varsta, std::string status);
    ~Utilizator() = default;

    std::string getNume() const;
    void setNume(const std::string &new_nume);

    int getId() const;
    void setId(int new_id);

    int getVarsta() const;
    void setVarsta(int new_varsta);

    std::string getStatus() const;
    void setStatus(const std::string &new_status);

    bool operator>(const Utilizator& other) const;
    bool operator!=(const Utilizator& other) const;
    bool operator<(const Utilizator& other) const;
    bool operator==(const Utilizator& other) const;

    Lista<int> getPrieteni() const;
    void setPrieteni(const Lista<int> &new_prieteni);
    void adaugarePrieten(int new_prieten);
    void stergerePrieten(int new_prieten);


private:
    int id;
    std::string nume;
    int varsta;
    std::string status;
    Lista<int> prieteni;
};

#endif // USER_H
