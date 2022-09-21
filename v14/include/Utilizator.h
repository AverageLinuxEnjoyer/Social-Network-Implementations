#ifndef UTILIZATOR_H
#define UTILIZATOR_H

#include <string>
#include <iostream>

class Utilizator {
private:
    std::string nume;
    std::string prenume;
    int varsta;
    std::string parola;
    std::string email;
    std::string adresa;
    std::string telefon;
public:
    Utilizator();
    Utilizator(std::string nume, std::string prenume, int varsta, std::string parola, std::string email, std::string adresa, std::string telefon);
    ~Utilizator();
    std::string getNume();
    std::string getPrenume();
    int getVarsta();
    std::string getParola();
    std::string getEmail();
    std::string getAdresa();
    std::string getTelefon();
    void setNume(std::string nume);
    void setPrenume(std::string prenume);
    void setVarsta(int varsta);
    void setParola(std::string parola);
    void setEmail(std::string email);
    void setAdresa(std::string adresa);
    void setTelefon(std::string telefon);

    bool operator==(const Utilizator& other);

    friend std::ostream& operator<<(std::ostream& os, const Utilizator& u);
    friend std::istream& operator>>(std::istream& is, Utilizator& u);

};

#endif // UTILIZATOR_H
