#ifndef Utilizator_HPP
#define Utilizator_HPP

#include <string>
#include <vector>
#include "Lista.h"
#include "Prietenie.h"
#include "Mesaj.h"

class Utilizator {
public:
    Utilizator() = default;
    Utilizator(std::string nume_utilizator, int varsta, std::string email);

    std::string getnume_utilizator() const;
    void setnume_utilizator(const std::string &nume_utilizator_);

    int getvarsta() const;
    void setvarsta(int varsta_);

    std::string getEmail() const;
    void setEmail(const std::string &email_);

    std::vector<Prietenie> getFriends() const;
    void addFriend(const Utilizator &Utilizator);
    void removeFriend(const Utilizator &Utilizator);

    // Trimite un mesaj catre Utilizator, returneaza true daca Utilizator e prieten si mesajul s-a trimis, false in caz contrar
    void sendMesaj(Utilizator& Utilizator, const std::string& Mesaj);
    std::vector<Mesaj> getMesaje() const;

    bool operator==(const Utilizator &other) const;
    bool operator!=(const Utilizator &other) const;

    bool operator<(const Utilizator &other) const;
    bool operator>(const Utilizator &other) const;

private:
    std::string nume_utilizator;
    int varsta;
    std::string email;
    std::vector<Prietenie> friends;
    std::vector<Mesaj> Mesaje;
};

#endif // Utilizator_HPP
