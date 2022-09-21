#include "../include/Utilizator.h"

bool Utilizator::operator==(const Utilizator& other) {
    return this->nume == other.nume && this->prenume == other.prenume && this->parola == other.parola && this->email == other.email && this->adresa == other.adresa && this->telefon == other.telefon && this->varsta == other.varsta;
}

Utilizator::Utilizator()
{
    
}

Utilizator::Utilizator(std::string nume, std::string prenume, int varsta, std::string parola, std::string email, std::string adresa, std::string telefon)
{
    this->nume = nume;
    this->prenume = prenume;
    this->varsta = varsta;
    this->parola = parola;
    this->email = email;
    this->adresa = adresa;
    this->telefon = telefon;
}

Utilizator::~Utilizator()
{
    
}

std::string Utilizator::getNume() {
    return this->nume;
}

std::string Utilizator::getPrenume() {
    return this->prenume;
}

int Utilizator::getVarsta() {
    return this->varsta;
}

std::string Utilizator::getParola() {
    return this->parola;
}

std::string Utilizator::getEmail() {
    return this->email;
}

std::string Utilizator::getAdresa() {
    return this->adresa;
}

std::string Utilizator::getTelefon() {
    return this->telefon;
}

void Utilizator::setNume(std::string nume) {
    this->nume = nume;
}

void Utilizator::setPrenume(std::string prenume) {
    this->prenume = prenume;
}

void Utilizator::setVarsta(int varsta) {
    this->varsta = varsta;
}

void Utilizator::setParola(std::string parola) {
    this->parola = parola;
}

void Utilizator::setEmail(std::string email) {
    this->email = email;
}

void Utilizator::setAdresa(std::string adresa) {
    this->adresa = adresa;
}

void Utilizator::setTelefon(std::string telefon) {
    this->telefon = telefon;
}

std::ostream& operator<<(std::ostream& os, const Utilizator& u) {
    os << u.nume << " " << u.prenume << " " << u.varsta << " " << u.parola << " " << u.email << " " << u.adresa << " " << u.telefon;
    return os;
}

std::istream& operator>>(std::istream& is, Utilizator& u) {
    is >> u.nume >> u.prenume >> u.varsta >> u.parola >> u.email >> u.adresa >> u.telefon;
    return is;
}