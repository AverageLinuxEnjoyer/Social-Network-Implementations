#include "../include/eveniment.h"

int Eveniment::getId() const { 
    return id;
}

Eveniment& Eveniment::setId(int id_) { 
    id = id_; 
    return *this;
}

std::string Eveniment::getNume() const { 
    return nume; 
}

Eveniment& Eveniment::setNume(const std::string &nume_) { 
    nume = nume_; 
    return *this;
}

std::string Eveniment::getLocatie() const { 
    return locatie; 
}

Eveniment& Eveniment::setLocatie(const std::string &locatie_) { 
    locatie = locatie_; 
    return *this;
}

std::string Eveniment::getData() const { 
    return data; 
}

Eveniment& Eveniment::setData(const std::string &data_) { 
    data = data_; 
    return *this;
}

std::string Eveniment::getOra() const { 
    return ora; 
}

Eveniment& Eveniment::setOra(const std::string &ora_) { 
    ora = ora_; 
    return *this;
}

std::string Eveniment::getTip() const { 
    return tip; 
}

Eveniment& Eveniment::setTip(const std::string &tip_) { 
    tip = tip_; 
    return *this;
}

std::string Eveniment::getDescriere() const { 
    return descriere; 
}

Eveniment& Eveniment::setDescriere(const std::string &descriere_) { 
    descriere = descriere_; 
    return *this;
}

bool Eveniment::operator==(const Eveniment &other) const {
    return id == other.id;
}
