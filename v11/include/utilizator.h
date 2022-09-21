#ifndef UTILIZATOR_H
#define UTILIZATOR_H

#include <iostream>

class Utilizator {
public:
    int getId() const;
    Utilizator& setId(int id_);

    std::string getNume() const;
    Utilizator& setNume(const std::string &nume_);

    std::string getPrenume() const;
    Utilizator& setPrenume(const std::string &prenume_);

    int getVarsta() const;
    Utilizator& setVarsta(int varsta_);

    std::string getAdresa() const;
    Utilizator& setAdresa(const std::string &adresa_);

    std::string getTelefon() const;
    Utilizator& setTelefon(const std::string &telefon_);

    std::string getEmail() const;
    Utilizator& setEmail(const std::string &email_);

    std::string getParola() const;
    Utilizator& setParola(const std::string &parola_);

    bool operator==(const Utilizator &other) const;

private:
    int id;
    std::string nume;
    std::string prenume;
    int varsta;
    std::string adresa;
    std::string telefon;
    std::string email;
    std::string parola;
};

#endif // UTILIZATOR_H
