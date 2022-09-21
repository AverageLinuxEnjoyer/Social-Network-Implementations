#include "../include/Prietenie.h"
#include <iostream>

Prietenie::Prietenie()
    : Utilizator1(nullptr),
      Utilizator2(nullptr)
{}

Prietenie::Prietenie(const Prietenie &other)
    : Utilizator1(other.Utilizator1),
      Utilizator2(other.Utilizator2)
{}

Prietenie::Prietenie(const Utilizator *Utilizator1, const Utilizator *Utilizator2)
    : Utilizator1(Utilizator1),
      Utilizator2(Utilizator2)
{}

Prietenie& Prietenie::operator=(const Prietenie &other) {
    Utilizator1 = other.Utilizator1;
    Utilizator2 = other.Utilizator2;
    
    return *this;
}

const Utilizator *Prietenie::getUtilizator1() const { return Utilizator1; }

const Utilizator *Prietenie::getUtilizator2() const { return Utilizator2; }

bool Prietenie::operator==(const Prietenie &other) const {
    return Utilizator1 == other.Utilizator1 && Utilizator2 == other.Utilizator2;
}

bool Prietenie::operator!=(const Prietenie &other) const {
    return !(*this == other);
}