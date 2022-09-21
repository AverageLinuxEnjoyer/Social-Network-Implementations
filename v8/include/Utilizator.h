#ifndef UTILIZATOR_H
#define UTILIZATOR_H

#include <string>

class Utilizator {
private:
    int id;
    std::string nume;
    std::string prenume;
    std::string email;
    std::string parola;
    bool student;

public:
    Utilizator();
    Utilizator(int id, std::string nume, std::string prenume, std::string email, std::string parola, bool student);

    int getId() const;
    std::string getNume() const;
    std::string getPrenume() const;
    std::string getEmail() const;
    std::string getParola() const;
    bool isStudent() const;

    void setId(int id);
    void setNume(std::string nume);
    void setPrenume(std::string prenume);
    void setEmail(std::string email);
    void setParola(std::string parola);
    void setStudent(bool student);

    bool operator==(const Utilizator& other) const;
    bool operator!=(const Utilizator& other) const;
    bool operator<(const Utilizator& other) const;
    bool operator>(const Utilizator& other) const;
};

#endif // UTILIZATOR_H
