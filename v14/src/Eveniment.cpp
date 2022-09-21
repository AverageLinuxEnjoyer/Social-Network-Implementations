#include "../include/Eveniment.h"

Eveniment::Eveniment()
{
    
}

Eveniment::Eveniment(std::string titlu, std::string data, std::string locatie, std::string organizator)
{
    this->titlu = titlu;
    this->data = data;
    this->locatie = locatie;
    this->organizator = organizator;
}

Eveniment::~Eveniment()
{

}

std::string Eveniment::getTitlu() {
    return this->titlu;
}


std::string Eveniment::getData() {
    return this->data;
}

std::string Eveniment::getLocatie() {
    return this->locatie;
}

std::string Eveniment::getOrganizator() {
    return this->organizator;
}

void Eveniment::setTitlu(std::string titlu) {
    this->titlu = titlu;
}

void Eveniment::setData(std::string data) {
    this->data = data;
}

void Eveniment::setLocatie(std::string locatie) {
    this->locatie = locatie;
}

void Eveniment::setOrganizator(std::string organizator) {
    this->organizator = organizator;
}

bool Eveniment::operator==(const Eveniment& other) {
    return this->titlu == other.titlu && this->data == other.data && this->locatie == other.locatie && this->organizator == other.organizator;
}

std::ostream& operator<<(std::ostream& os, const Eveniment& e) {
    os << e.titlu << " " << e.data << " " << e.locatie << " " << e.organizator;
    return os;
}

std::istream& operator>>(std::istream& is, Eveniment& e) {  
    is >> e.titlu >> e.data >> e.locatie >> e.organizator;
    return is;
}