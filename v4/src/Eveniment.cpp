#include "../include/Eveniment.h"

Eveniment::Eveniment()
{
    
}

Eveniment::Eveniment(std::string nume, std::string locatie, std::string descriere, std::string data)
    : nume(nume),
      locatie(locatie),
      descriere(descriere),
      data(data)
{}

std::string Eveniment::getNume() const { return nume; }

void Eveniment::setNume(const std::string &nume_) { nume = nume_; }

std::string Eveniment::getLocatie() const { return locatie; }

void Eveniment::setLocatie(const std::string &locatie_) { locatie = locatie_; }

std::string Eveniment::getDescriere() const { return descriere; }

void Eveniment::setDescriere(const std::string &descriere_) { descriere = descriere_; }

std::string Eveniment::getData() const { return data; }

void Eveniment::setData(const std::string &data_) { data = data_; }

const Lista<Utilizator*>& Eveniment::getUtilizatoriInteresati() const { return utilizatori_interesati; }

void Eveniment::addUtilizatorInteresat(Utilizator* Utilizator) {
    for (int i = 0; i < utilizatori_interesati.size(); i++)
        if (*utilizatori_interesati[i] == *Utilizator)
            return;

    utilizatori_interesati.insert(utilizatori_interesati.size(), Utilizator);

    std::cout << "Utilizatorul " << utilizatori_interesati[utilizatori_interesati.size()-1]->getnume_utilizator() << " e acum interesat in evenimentul " << nume << std::endl;
}
