#include "../include/Eveniment.h"


Eveniment::Eveniment()
{
    id = 0;
    nume = "";
    data = "";
    locatie = "";
}


Eveniment::Eveniment(int id, std::string nume, std::string data, std::string locatie)
{
    this->id = id;
    this->nume = nume;
    this->data = data;
    this->locatie = locatie;
}


int Eveniment::getId() const {
    return id;
}


std::string Eveniment::getNume() const {
    return nume;
}


std::string Eveniment::getData() const {
    return data;
}


std::string Eveniment::getLocatie() const {
    return locatie;
}


void Eveniment::setId(int id) {
    this->id = id;
}


void Eveniment::setNume(std::string nume) {
    this->nume = nume;
}


void Eveniment::setData(std::string data) {
    this->data = data;
}


void Eveniment::setLocatie(std::string locatie) {
    this->locatie = locatie;
}

bool Eveniment::operator==(const Eveniment& other) const {
    return id == other.id;
}

bool Eveniment::operator!=(const Eveniment& other) const {
    return id != other.id;
}

bool Eveniment::operator<(const Eveniment& other) const {
    return id < other.id;
}

bool Eveniment::operator>(const Eveniment& other) const {
    return id > other.id;
}

