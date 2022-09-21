#include "../include/Utilizator.h"

Utilizator::Utilizator()
{
    this->id = -1;
    this->nume = "";
    this->varsta = -1;
    this->status = "";
}

Utilizator::Utilizator(int id, std::string nume, int varsta, std::string status)
{
    this->id = id;
    this->nume = nume;
    this->varsta = varsta;
    this->status = status;
}

int Utilizator::getId() const { return id; }

void Utilizator::setId(int new_id) { id = new_id; }

std::string Utilizator::getNume() const { return nume; }

void Utilizator::setNume(const std::string &new_nume) { nume = new_nume; }

int Utilizator::getVarsta() const { return varsta; }

void Utilizator::setVarsta(int new_varsta) { varsta = new_varsta; }

std::string Utilizator::getStatus() const { return status; }

void Utilizator::setStatus(const std::string &new_status) { status = new_status; }

bool Utilizator::operator==(const Utilizator& other) const { return this->id == other.id; }

bool Utilizator::operator<(const Utilizator& other) const { return this->nume < other.nume; }

bool Utilizator::operator>(const Utilizator& other) const { return this->nume > other.nume; }

Lista<int> Utilizator::getPrieteni() const { return prieteni; }

void Utilizator::setPrieteni(const Lista<int> &new_prieteni) { prieteni = new_prieteni; }

void Utilizator::adaugarePrieten(int new_prieten) { prieteni.inserare_sfarsit(new_prieten); }

void Utilizator::stergerePrieten(int new_prieten) {
    for (int i = 0; i < prieteni.getNrElems(); i++) {
        if (prieteni[i] == new_prieten) {
            prieteni.stergere(i);
            break;
        }
    }
}

bool Utilizator::operator!=(const Utilizator& other) const { return !(*this == other); }
