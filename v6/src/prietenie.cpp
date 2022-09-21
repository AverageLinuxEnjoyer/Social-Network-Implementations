#include "../include/prietenie.h"
#include <algorithm>

Prietenie::Prietenie()
{

}

Prietenie::Prietenie(int id1, int id2)
{
    idUser1 = std::min(id1, id2);
    idUser2 = std::max(id1, id2);
}

int Prietenie::getId1() const 
{
    return idUser1;
}

int Prietenie::getId2() const 
{
    return idUser2;
}

void Prietenie::setId1(int id1) 
{
    idUser1 = id1;
}

void Prietenie::setId2(int id2) 
{
    idUser2 = id2;
}

std::ostream& operator<<(std::ostream& os, const Prietenie& prietenie) 
{
    os << "Prietenie(idUser1=" << prietenie.idUser1 << ", idUser2=" << prietenie.idUser2 << ")";
    return os;
}

std::istream& operator>>(std::istream& is, Prietenie& prietenie) {
    int id1, id2;

    std::cout << "idUser1=";
    is >> id1;

    std::cout << "idUser2=";
    is >> id2;

    prietenie.idUser1 = std::min(id1, id2);
    prietenie.idUser2 = std::max(id1, id2);

    return is;
}