#ifndef EVENT_H
#define EVENT_H

#include <string>
#include "lista.h"
#include "utilizator.h"

class Eveniment {
public:
    Eveniment() = default;
    Eveniment(std::string nume, std::string locatie, std::string descriere, std::string data);

    std::string getNume() const;
    void setNume(const std::string &name_);

    std::string getLocatie() const;
    void setLocatie(const std::string &location_);

    std::string getDescriere() const;
    void setDescriere(const std::string &description_);

    std::string getDate() const;
    void setDate(const std::string &date_);

    const Lista<Utilizator*>& get_utilizatori_interesati() const;
    void adaugare_utilizator_interesat(Utilizator* user);

private:
    std::string nume;
    std::string locatie;
    std::string descriere;
    std::string data;
    Lista<Utilizator*> utlizatori_interesati;
};

#endif // EVENT_H
