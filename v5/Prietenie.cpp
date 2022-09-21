#include "Prietenie.h"

string Prietenie::getNume_user1() const {
    return nume_user1;
}

void Prietenie::setNume_user1(string nume_user1_) {
    nume_user1 = nume_user1_;
}

string Prietenie::getNume_user2() const {
    return nume_user2;
}

void Prietenie::setNume_user2(string nume_user2_) {
    nume_user2 = nume_user2_;
}

Prietenie::Prietenie()
{
    
}

Prietenie::Prietenie(string nume_user1_, string nume_user2_)
{
    nume_user1 = nume_user1_;
    nume_user2 = nume_user2_;
}

Prietenie::~Prietenie()
{
    
}

