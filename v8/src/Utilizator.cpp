#include "../include/Utilizator.h"

Utilizator::Utilizator()
{
    id = 0;
    nume = "";
    prenume = "";
    email = "";
    parola = "";
    student = false;
}


Utilizator::Utilizator(int id, std::string nume, std::string prenume, std::string email, std::string parola, bool student)
{
    this->id = id;
    this->nume = nume;
    this->prenume = prenume;
    this->email = email;
    this->parola = parola;
    this->student = student;
}


int Utilizator::getId() const {
    return id;
}


std::string Utilizator::getNume() const {
    return nume;
}


std::string Utilizator::getPrenume() const {
    return prenume;
}


std::string Utilizator::getEmail() const {
    return email;
}


std::string Utilizator::getParola() const {
    return parola;
}


bool Utilizator::isStudent() const {
    return student;
}


void Utilizator::setId(int id) {
    this->id = id;
}


void Utilizator::setNume(std::string nume) {
    this->nume = nume;
}


void Utilizator::setPrenume(std::string prenume) {
    this->prenume = prenume;
}


void Utilizator::setEmail(std::string email) {
    this->email = email;
}


void Utilizator::setParola(std::string parola) {
    this->parola = parola;
}


void Utilizator::setStudent(bool student) {
    this->student = student;
}


bool Utilizator::operator==(const Utilizator& other) const {
    return id == other.id;    
}


bool Utilizator::operator!=(const Utilizator& other) const {
    return id != other.id;
}


bool Utilizator::operator<(const Utilizator& other) const {
    return id < other.id;
}

bool Utilizator::operator>(const Utilizator& other) const {
    return id > other.id;
}
