#include "../include/Prietenie.h"

Prietenie::Prietenie()
{
    
}

Prietenie::Prietenie(Utilizator utilizator1, Utilizator utilizator2)
{   
    this->utilizator1 = utilizator1;
    this->utilizator2 = utilizator2;
    this->data_prietenie = Data::getDataDeAzi();
}

Prietenie::Prietenie(const Prietenie& prietenie)
{
    this->utilizator1 = prietenie.utilizator1;
    this->utilizator2 = prietenie.utilizator2;
    this->data_prietenie = prietenie.data_prietenie;
}

Prietenie& Prietenie::operator=(const Prietenie& prietenie) {
    this->utilizator1 = prietenie.utilizator1;
    this->utilizator2 = prietenie.utilizator2;
    this->data_prietenie = prietenie.data_prietenie;
    return *this;
}

Utilizator Prietenie::get_utilizator1() const {
    return this->utilizator1;
}

Utilizator Prietenie::get_utilizator2() const {
    return this->utilizator2;
}


Data Prietenie::get_data() const {
    return this->data_prietenie;
}

int Prietenie::get_durata_prietenie() const {
    Data durata = Data::getDataDeAzi() - this->data_prietenie;
    int durata_in_zile = durata.zi + durata.luna * 30 + durata.an * 365;

    return durata_in_zile;
}

void Prietenie::set_utilizator1(Utilizator utilizator1) {
    this->utilizator1 = utilizator1;
}

void Prietenie::set_utilizator2(Utilizator utilizator2) {
    this->utilizator2 = utilizator2;
}

void Prietenie::set_data(Data data) {
    this->data_prietenie = data;
}

bool Prietenie::operator==(const Prietenie& prietenie) const {
    return (this->utilizator1 == prietenie.utilizator1 && this->utilizator2 == prietenie.utilizator2);
}

bool Prietenie::operator!=(const Prietenie& prietenie) const {
    return !(*this == prietenie);
}
