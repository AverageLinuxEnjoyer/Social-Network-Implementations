#ifndef EVENIMENT_H
#define EVENIMENT_H

#include <iostream>
#include "Lista.h"

class Eveniment {
public:
    Eveniment();
    Eveniment(int id, std::string denumire, std::string data, std::string locatie, int nr_bilete);
    Eveniment(const Eveniment& other);
    ~Eveniment();

    Eveniment& operator=(const Eveniment& other);
    bool operator==(const Eveniment& other);

    std::string getDenumire() const;
    void setDenumire(const std::string &denumire_);

    std::string getData() const;
    void setData(const std::string &data_);

    std::string getLocatie() const;
    void setLocatie(const std::string &locatie_);

    int getBileteRamase() const;
    void setBileteRamase(int bileteRamase);

    Lista<int> getParticipanti() const;
    void adaugaParticipant(int id);

    int getId() const;

    friend std::ostream& operator<<(std::ostream& out, const Eveniment& eveniment);
    friend std::istream& operator>>(std::istream& in, Eveniment& eveniment);


private:
    int id;
    std::string denumire;
    std::string data;
    std::string locatie;
    int bilete_ramase;
    Lista<int> participanti;
};

#endif // EVENIMENT_H
