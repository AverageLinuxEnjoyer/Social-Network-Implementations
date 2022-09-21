#include "../include/Utilizator.h"

Utilizator::Utilizator(std::string nume_utilizator, int varsta, std::string email)
    : nume_utilizator(nume_utilizator),
      varsta(varsta),
      email(email)
{}

std::string Utilizator::getnume_utilizator() const {
    return nume_utilizator;
}

void Utilizator::setnume_utilizator(const std::string &nume_utilizator_) {
    nume_utilizator = nume_utilizator_;
}

int Utilizator::getvarsta() const {
    return varsta;
}

void Utilizator::setvarsta(int varsta_) {
    varsta = varsta_;
}

std::string Utilizator::getEmail() const {
    return email;
}

void Utilizator::setEmail(const std::string &email_) {
    email = email_;
}

std::vector<Prietenie> Utilizator::getFriends() const { return friends; }

void Utilizator::addFriend(const Utilizator &Utilizator) {
    friends.push_back(Prietenie(this, &Utilizator));
}

void Utilizator::removeFriend(const Utilizator &Utilizator) {
    for (int i = 0; i < friends.size(); i++) {
        if (friends[i].getUtilizator1() == this && friends[i].getUtilizator2() == &Utilizator) {
            friends.erase(friends.begin() + i);
            return;
        }
    }
}

void Utilizator::sendMesaj(Utilizator& utilizator, const std::string& continut) {
    Mesaj Mesaj(this, &utilizator, continut);

    this->Mesaje.push_back(Mesaj);
    utilizator.Mesaje.push_back(Mesaj);
}

std::vector<Mesaj> Utilizator::getMesaje() const {
    return Mesaje;
}

bool Utilizator::operator==(const Utilizator &other) const {
    return nume_utilizator == other.nume_utilizator && varsta == other.varsta && email == other.email && friends == other.friends;
}

bool Utilizator::operator!=(const Utilizator &other) const {
    return !(*this == other);
}

bool Utilizator::operator<(const Utilizator &other) const {
    return nume_utilizator < other.nume_utilizator;
}

bool Utilizator::operator>(const Utilizator &other) const {
    return nume_utilizator > other.nume_utilizator;
}
