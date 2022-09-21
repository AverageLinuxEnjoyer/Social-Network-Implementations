#include "../include/Eveniment.h"

Eveniment::Eveniment()
    : id(),
      denumire(),
      data(),
      locatie(),
      bilete_ramase(),
      participanti()
{}

Eveniment::Eveniment(int id, std::string denumire, std::string data, std::string locatie, int nr_bilete)
    : id(id),
      denumire(denumire),
      data(data),
      locatie(locatie),
      bilete_ramase(nr_bilete),
      participanti()
{}

Eveniment::Eveniment(const Eveniment& other)
    : id(other.id),
      denumire(other.denumire),
      data(other.data),
      locatie(other.locatie),
      bilete_ramase(other.bilete_ramase),
      participanti(other.participanti)
{}

Eveniment::~Eveniment()
{
    
}

Eveniment& Eveniment::operator=(const Eveniment& other) {
    id = other.id;
    denumire = other.denumire;
    data = other.data;
    locatie = other.locatie;
    bilete_ramase = other.bilete_ramase;
    participanti = other.participanti;
    return *this;
}

bool Eveniment::operator==(const Eveniment& other) {
    return id == other.id && denumire == other.denumire
        && data == other.data && locatie == other.locatie
        && bilete_ramase == other.bilete_ramase
        && participanti == other.participanti;
}

std::string Eveniment::getDenumire() const { 
    return denumire; 
}

void Eveniment::setDenumire(const std::string &denumire_) { 
    denumire = denumire_; 
}

std::string Eveniment::getData() const { 
    return data; 
}

void Eveniment::setData(const std::string &data_) { 
    data = data_; 
}

std::string Eveniment::getLocatie() const { 
    return locatie; 
}

void Eveniment::setLocatie(const std::string &locatie_) { 
    locatie = locatie_;
}

int Eveniment::getBileteRamase() const { 
    return bilete_ramase; 
}

void Eveniment::setBileteRamase(int bileteRamase) { 
    bilete_ramase = bileteRamase; 
}

Lista<int> Eveniment::getParticipanti() const { 
    return participanti; 
}

void Eveniment::adaugaParticipant(int id) {
    participanti.push_back(id);    
}

int Eveniment::getId() const { 
    return id;
}

std::ostream& operator<<(std::ostream& out, const Eveniment& eveniment) {
    out << eveniment.id << " " << eveniment.denumire << " " << eveniment.data << " " << eveniment.locatie << " " << eveniment.bilete_ramase << " ";
    return out;
}

std::istream& operator>>(std::istream& in, Eveniment& eveniment) {
    in >> eveniment.id >> eveniment.denumire >> eveniment.data >> eveniment.locatie >> eveniment.bilete_ramase;

    return in;
}