#include "../include/Utilizator.h"

Utilizator::Utilizator()
{
    this->nume = "";
    this->prenume = "";
    this->data_nasterii = Data();
    this->data_inregistrarii = Data();
}

Utilizator::Utilizator(string nume, string prenume, Data dataNasterii)
{
    this->nume = nume;
    this->prenume = prenume;
    this->data_nasterii = dataNasterii;
    this->data_inregistrarii = Data::getDataDeAzi();
}

Utilizator::Utilizator(const Utilizator& utilizator)
{
    this->nume = utilizator.nume;
    this->prenume = utilizator.prenume;
    this->data_nasterii = utilizator.data_nasterii;
    this->data_inregistrarii = utilizator.data_inregistrarii;
}

Utilizator& Utilizator::operator=(const Utilizator& utilizator) {
    this->nume = utilizator.nume;
    this->prenume = utilizator.prenume;
    this->data_nasterii = utilizator.data_nasterii;
    this->data_inregistrarii = utilizator.data_inregistrarii;
    return *this;
}

string Utilizator::get_nume() const {
    return this->nume;
}

string Utilizator::get_prenume() const {
    return this->prenume;
}


Data Utilizator::get_data_nasterii() const {
    return this->data_nasterii;
}

Data Utilizator::get_data_inregistrarii() const {
    return this->data_inregistrarii;
}

int Utilizator::get_varsta() const {
    return (Data::getDataDeAzi() - this->data_nasterii).an;
}

void Utilizator::set_nume(string nume) {
    this->nume = nume;
}

void Utilizator::set_prenume(string prenume) {
    this->prenume = prenume;
}

void Utilizator::set_data_nasterii(Data dataNasterii) {
    this->data_nasterii = dataNasterii;
}

void Utilizator::set_data_inregistrarii(Data dataInregistrarii) {
    this->data_inregistrarii = dataInregistrarii;
}

bool Utilizator::operator==(const Utilizator& utilizator) const {
    return (this->nume == utilizator.nume) && (this->data_nasterii == utilizator.data_nasterii);
}

bool Utilizator::operator!=(const Utilizator& utilizator) const {
    return !(*this == utilizator);
}




