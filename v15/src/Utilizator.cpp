#include "../include/Utilizator.h"

Utilizator::Utilizator()
    : id(),
      nume(),
      prenume(),
      varsta(),
      email(),
      parola(),
      prieteni(),
      evenimente()
{}

Utilizator::Utilizator(int id, std::string nume, std::string prenume, int varsta, std::string email, std::string parola)
    : id(id),
      nume(nume),
      prenume(prenume),
      varsta(varsta),
      email(email),
      parola(parola),
      prieteni(),
      evenimente()
{}

Utilizator::Utilizator(const Utilizator& other)
    : id(other.id),
      nume(other.nume),
      prenume(other.prenume),
      varsta(other.varsta),
      email(other.email),
      parola(other.parola),
      prieteni(other.prieteni),
      evenimente(other.evenimente)
{}

Utilizator& Utilizator::operator=(const Utilizator& other) {
    id = other.id;
    nume = other.nume;
    prenume = other.prenume;
    varsta = other.varsta;
    email = other.email;
    parola = other.parola;
    prieteni = other.prieteni;
    evenimente = other.evenimente;
    return *this;
}

bool Utilizator::operator==(const Utilizator& other) const {
    return id == other.id && nume == other.nume 
        && prenume == other.prenume && varsta == other.varsta 
        && email == other.email && parola == other.parola
        && prieteni == other.prieteni && evenimente == other.evenimente;
}

std::string Utilizator::getNume() const { 
    return nume; 
}

void Utilizator::setNume(const std::string &nume_) { 
    nume = nume_; 
}

std::string Utilizator::getPrenume() const { 
    return prenume; 
}

void Utilizator::setPrenume(const std::string &prenume_) { 
    prenume = prenume_; 
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

std::string Utilizator::getParola() const { 
    return parola; 
}

void Utilizator::setParola(const std::string &parola_) { 
    parola = parola_; 
}

Lista<int> Utilizator::getPrieteni() const {
    return prieteni;
}

void Utilizator::adaugaPrieten(int id_) {
    prieteni.push_back(id_);
}

Lista<int> Utilizator::getEvenimente() const { 
    return evenimente; 
}

void Utilizator::adaugaEveniment(int id) {
    evenimente.push_back(id);    
}

int Utilizator::getId() const { 
    return id; 
}

Utilizator::~Utilizator()
{

}

std::ostream& operator<<(std::ostream& os, const Utilizator& utilizator) {
    os << utilizator.id << " " << utilizator.nume << " " << utilizator.prenume << " " << utilizator.varsta << " " << utilizator.email << " " << utilizator.parola << " ";

    return os;
}

std::istream& operator>>(std::istream& is, Utilizator& utilizator) {
    is >> utilizator.id >> utilizator.nume >> utilizator.prenume >> utilizator.varsta >> utilizator.email >> utilizator.parola;
    
    return is;
}



