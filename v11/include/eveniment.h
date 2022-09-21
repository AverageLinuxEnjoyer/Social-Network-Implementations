#ifndef EVENIMENT_H
#define EVENIMENT_H

#include <string>

class Eveniment {
public:
    int getId() const;
    Eveniment& setId(int id_);

    std::string getNume() const;
    Eveniment& setNume(const std::string &nume_);

    std::string getLocatie() const;
    Eveniment& setLocatie(const std::string &locatie_);

    std::string getData() const;
    Eveniment& setData(const std::string &data_);

    std::string getOra() const;
    Eveniment& setOra(const std::string &ora_);

    std::string getTip() const;
    Eveniment& setTip(const std::string &tip_);

    std::string getDescriere() const;
    Eveniment& setDescriere(const std::string &descriere_);

    bool operator==(const Eveniment &other) const;

private:
    int id;
    std::string nume;
    std::string locatie;
    std::string data;
    std::string ora;    
    std::string tip;
    std::string descriere;
};

#endif // EVENIMENT_H
