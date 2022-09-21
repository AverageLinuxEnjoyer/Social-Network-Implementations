#ifndef UTILIZATOR_H
#define UTILIZATOR_H

#include <string>
#include <vector>
#include "lista.h"
#include "prietenie.h"
#include "mesaj.h"

class Utilizator {
public:
    Utilizator() = default;
    Utilizator(std::string username, int varsta, std::string email);

    std::string getUsername() const;
    void setUsername(const std::string &username_);

    int getVarsta() const;
    void setVarsta(int varsta_);

    std::string getEmail() const;
    void setEmail(const std::string &email_);

    std::vector<Prietenie> getFriends() const;
    void adaugarePrieten(const Utilizator &user);
    void stergerePrieten(const Utilizator &user);

    void trimitereMesaj(Utilizator& user, const std::string& message);
    std::vector<Mesaj> getMesaje() const;

    bool operator==(const Utilizator &other) const;
    bool operator!=(const Utilizator &other) const;

    bool operator<(const Utilizator &other) const;
    bool operator>(const Utilizator &other) const;

private:
    std::string username;
    int varsta;
    std::string email;
    std::vector<Prietenie> prieteni;
    std::vector<Mesaj> mesaje;
};

#endif // UTILIZATOR_H
