#include "../include/eveniment.h"

Eveniment::Eveniment(std::string nume, std::string locatie, std::string descriere, std::string data)
    : nume(nume),
      locatie(locatie),
      descriere(descriere),
      data(data)
{}

std::string Eveniment::getNume() const { return nume; }

void Eveniment::setNume(const std::string &name_) { nume = name_; }

std::string Eveniment::getLocatie() const { return locatie; }

void Eveniment::setLocatie(const std::string &location_) { locatie = location_; }

std::string Eveniment::getDescriere() const { return descriere; }

void Eveniment::setDescriere(const std::string &description_) { descriere = description_; }

std::string Eveniment::getDate() const { return data; }

void Eveniment::setDate(const std::string &date_) { data = date_; }

const Lista<Utilizator*>& Eveniment::get_utilizatori_interesati() const { return utlizatori_interesati; }

void Eveniment::adaugare_utilizator_interesat(Utilizator* user) {
    // if user is not already utlizatori_interesati in this event
    for (int i = 0; i < utlizatori_interesati.size(); i++)
        if (*utlizatori_interesati[i] == *user)
            return;

    utlizatori_interesati.inserare_sfarsit(user);

    std::cout << "Utilizator " << utlizatori_interesati[utlizatori_interesati.size()-1]->getUsername() << " is now utlizatori_interesati in event " << nume << std::endl;
}
