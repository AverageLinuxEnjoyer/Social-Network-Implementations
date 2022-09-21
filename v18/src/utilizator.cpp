#include "../include/utilizator.h"

Utilizator::Utilizator(std::string username, int varsta, std::string email)
    : username(username),
      varsta(varsta),
      email(email)
{}

std::string Utilizator::getUsername() const {
    return username;
}

void Utilizator::setUsername(const std::string &username_) {
    username = username_;
}

int Utilizator::getVarsta() const {
    return varsta;
}

void Utilizator::setVarsta(int varsta_) {
    varsta = varsta_;
}

std::string Utilizator::getEmail() const {
    return email;
}

void Utilizator::setEmail(const std::string &email_) {
    email = email_;
}

std::vector<Prietenie> Utilizator::getFriends() const { return prieteni; }

void Utilizator::adaugarePrieten(const Utilizator &user) {
    prieteni.push_back(Prietenie(this, &user));
}

void Utilizator::stergerePrieten(const Utilizator &user) {
    for (int i = 0; i < prieteni.size(); i++) {
        if (prieteni[i].getUser1() == this && prieteni[i].getUser2() == &user) {
            prieteni.erase(prieteni.begin() + i);
            return;
        }
    }
}

void Utilizator::trimitereMesaj(Utilizator& user, const std::string& continut) {
    Mesaj message = {
        .user_expeditor = this,
        .user_destinatar = &user,
        .continut = continut
    };

    this->mesaje.push_back(message);
    user.mesaje.push_back(message);
}

std::vector<Mesaj> Utilizator::getMesaje() const {
    return mesaje;
}

bool Utilizator::operator==(const Utilizator &other) const {
    return username == other.username && varsta == other.varsta && email == other.email && prieteni == other.prieteni;
}

bool Utilizator::operator!=(const Utilizator &other) const {
    return !(*this == other);
}

bool Utilizator::operator<(const Utilizator &other) const {
    return username < other.username;
}

bool Utilizator::operator>(const Utilizator &other) const {
    return username > other.username;
}
