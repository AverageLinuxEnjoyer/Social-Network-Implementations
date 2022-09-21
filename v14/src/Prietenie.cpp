#include "../include/Prietenie.h"

Prietenie::Prietenie()
{
    
}

Prietenie::Prietenie(std::string utilizator1, std::string utilziator2, bool acceptat)
{
    this->utilizator1 = utilizator1;
    this->utilziator2 = utilziator2;
    this->acceptat = acceptat;
}

Prietenie::~Prietenie()
{
    
}

std::string Prietenie::getUtilizator1() {
    return this->utilizator1;
}

std::string Prietenie::getUtilizator2() {
    return this->utilziator2;
}


bool Prietenie::getAcceptat() {
    return this->acceptat;
}

void Prietenie::setUtilizator1(std::string utilizator1) {
    this->utilizator1 = utilizator1;
}

void Prietenie::setUtilizator2(std::string utilizator2) {
    this->utilziator2 = utilizator2;
}

void Prietenie::setAcceptat(bool acceptat) {
    this->acceptat = acceptat;
}

bool Prietenie::operator==(const Prietenie& other) {
    return this->utilizator1 == other.utilizator1 && this->utilziator2 == other.utilziator2 && this->acceptat == other.acceptat;
}

std::ostream& operator<<(std::ostream& os, const Prietenie& p) {
    os << p.utilizator1 << " " << p.utilziator2 << " " << p.acceptat;
    return os;
}

std::istream& operator>>(std::istream& is, Prietenie& p) {
    is >> p.utilizator1 >> p.utilziator2 >> p.acceptat;
    return is;
}