#include "../include/Eveniment.h"

Eveniment::Eveniment()
{
    this->titlu = "";
    this->descriere = "";
    this->data = Data();
    this->locatie = "";
}

Eveniment::Eveniment(string titlu, string descriere, Data data, string locatie)
{
    this->titlu = titlu;
    this->descriere = descriere;
    this->data = data;
    this->locatie = locatie;    
}

Eveniment::Eveniment(const Eveniment& eveniment)
{
    this->titlu = eveniment.titlu;
    this->descriere = eveniment.descriere;
    this->data = eveniment.data;
    this->locatie = eveniment.locatie;
    this->utilizatori_participanti = eveniment.utilizatori_participanti;
}

Eveniment& Eveniment::operator=(const Eveniment& eveniment) {
    this->titlu = eveniment.titlu;
    this->descriere = eveniment.descriere;
    this->data = eveniment.data;
    this->locatie = eveniment.locatie;
    this->utilizatori_participanti = eveniment.utilizatori_participanti;

    return *this;
}


string Eveniment::get_titlu() const {
    return this->titlu;
}

string Eveniment::get_descriere() const {
    return this->descriere;
}

Data Eveniment::get_data() const {
    return this->data;
}

string Eveniment::get_locatie() const {
    return this->locatie;
}

void Eveniment::set_titlu(string titlu) {
    this->titlu = titlu;
}

void Eveniment::set_descriere(string descriere) {
    this->descriere = descriere;
}

void Eveniment::set_data(Data data) {
    this->data = data;
}

void Eveniment::set_locatie(string locatie) {
    this->locatie = locatie;
}

bool Eveniment::operator==(const Eveniment& eveniment) const {
    return this->titlu == eveniment.titlu && this->descriere == eveniment.descriere && this->data == eveniment.data && this->locatie == eveniment.locatie;
}

bool Eveniment::operator!=(const Eveniment& eveniment) const {
    return !(*this == eveniment);
}

Lista<Utilizator> Eveniment::get_utilizatori_participanti() const { 
    return utilizatori_participanti; 
}

void Eveniment::adauga_utilizator_participant(Utilizator utilizator) {
    for (int i = 0; i < utilizatori_participanti.get_dimensiune(); i++) {
        if (utilizatori_participanti.get_element(i) == utilizator) {
            throw "Utilizatorul exista deja in lista de participanti!";
        }
    }

    this->utilizatori_participanti.adauga_element(utilizator);
}
