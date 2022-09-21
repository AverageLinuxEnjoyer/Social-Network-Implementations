#include "User.h"

User::User(int id_, string nume_, string prenume_) : id(id_), nume(nume_), prenume(prenume_) {}

int User::getId() const { return id; }

void User::setId(int id_) { id = id_; }

string User::getNume() const { return nume; }

void User::setNume(const string &nume_) { nume = nume_; }

string User::getPrenume() const { return prenume; }

void User::setPrenume(const string &prenume_) { prenume = prenume_; }

bool User::operator==(const User &user) {
    return this->id == user.id && this->nume == user.nume && this->prenume == user.prenume;
}

bool User::operator<(const User &user) {
    return this->id < user.id && this->nume < user.nume && this->prenume < user.prenume;
}
