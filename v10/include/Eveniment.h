#ifndef EVENIMENT_H
#define EVENIMENT_H

#include <string>
#include "Lista.h"

class Eveniment{
private:
    int id;
    std::string nume;
    int numar_persoane_interesate;
    std::string locatie;
    Lista<int> participanti;
    
public:
    Eveniment() = default;
    Eveniment(int id, std::string nume, int numar_persoane_interesate, std::string locatie);
    Eveniment(const Eveniment& other) = default;
    ~Eveniment() = default;

    int getId() const;
    void setId(int new_id);

    std::string getNume() const;
    void setNume(const std::string &new_nume);

    int new_numar_persoane_interesate() const;
    void setNumarPersoaneInteresate(int new_numar_persoane_interesate);

    std::string getLocatie() const;
    void setLocatie(const std::string &new_locatie);

    bool operator==(const Eveniment& other) const;
    bool operator<(const Eveniment& other) const;
    bool operator>(const Eveniment& other) const;

    const Lista<int>& getParticipanti() const;
    void setParticipanti(const Lista<int> &new_participanti);
    void adaugareParticipant(int participant);
    void stergereParticipant(int participant);

    bool operator!=(const Eveniment& other) const;

};

#endif // EVENIMENT_H
