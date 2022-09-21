#include "../include/Prietenie.h"

Prietenie::Prietenie()
{
    id1 = 0;
    id2 = 0;
}

Prietenie::Prietenie(int id1, int id2)
{
    this->id1 = id1;
    this->id2 = id2;
}

int Prietenie::getId1() const {
    return id1;
}

int Prietenie::getId2() const {
    return id2;
}

void Prietenie::setId1(int id1) {
    this->id1 = id1;
}

void Prietenie::setId2(int id2) {
    this->id2 = id2;
}

bool Prietenie::operator==(const Prietenie& other) const {
    return (id1 == other.id1 && id2 == other.id2) || (id1 == other.id2 && id2 == other.id1);
}

bool Prietenie::operator!=(const Prietenie& other) const {
    return !(*this == other);
}
