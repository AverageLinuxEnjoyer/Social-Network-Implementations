#include "../include/Eveniment.h"

Eveniment::Eveniment(int id, std::string nume, int numar_persoane_interesate, std::string locatie)
{
    this->id = id;
    this->nume = nume;
    this->numar_persoane_interesate = numar_persoane_interesate;
    this->locatie = locatie;
}

int Eveniment::getId() const { return id; }

void Eveniment::setId(int new_id) { id = new_id; }

std::string Eveniment::getNume() const { return nume; }

void Eveniment::setNume(const std::string &new_nume) { nume = new_nume; }

int Eveniment::new_numar_persoane_interesate() const { return numar_persoane_interesate; }

void Eveniment::setNumarPersoaneInteresate(int new_numar_persoane_interesate) { numar_persoane_interesate = new_numar_persoane_interesate; }

std::string Eveniment::getLocatie() const { return locatie; }

void Eveniment::setLocatie(const std::string &new_locatie) { locatie = new_locatie; }

bool Eveniment::operator==(const Eveniment& other) const { return id == other.id; }

bool Eveniment::operator<(const Eveniment& other) const { return nume < other.nume; }

bool Eveniment::operator>(const Eveniment& other) const { return nume > other.nume; }

const Lista<int>& Eveniment::getParticipanti() const { return participanti; }

void Eveniment::setParticipanti(const Lista<int> &new_participanti) { participanti = new_participanti; }

void Eveniment::adaugareParticipant(int participant) { participanti.inserare_sfarsit(participant);}

void Eveniment::stergereParticipant(int participant) {
    for (int i = 0; i < participanti.getNrElems(); i++) {
        if (participanti[i] == participant) {
            participanti.stergere(i);
            break;
        }
    }
}

bool Eveniment::operator!=(const Eveniment& other) const { return !(*this == other); }
