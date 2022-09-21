#include "../include/utilizator.h"

int Utilizator::getId() const { 
    return id; 
}

Utilizator& Utilizator::setId(int id_) { 
    id = id_; 
    return *this;
}

std::string Utilizator::getNume() const { 
    return nume; 
}

Utilizator& Utilizator::setNume(const std::string &nume_) { 
    nume = nume_; 
    return *this;
}

std::string Utilizator::getPrenume() const { 
    return prenume; 
}

Utilizator& Utilizator::setPrenume(const std::string &prenume_) { 
    prenume = prenume_; 
    return *this;
}

int Utilizator::getVarsta() const { 
    return varsta; 
}

Utilizator& Utilizator::setVarsta(int varsta_) { 
    varsta = varsta_; 
    return *this;
}

std::string Utilizator::getAdresa() const { 
    return adresa; 
}

Utilizator& Utilizator::setAdresa(const std::string &adresa_) { 
    adresa = adresa_; 
    return *this;
}

std::string Utilizator::getTelefon() const { 
    return telefon; 
}

Utilizator& Utilizator::setTelefon(const std::string &telefon_) { 
    telefon = telefon_; 
    return *this;
}

std::string Utilizator::getEmail() const { 
    return email; 
}

Utilizator& Utilizator::setEmail(const std::string &email_) { 
    email = email_; 
    return *this;
}

std::string Utilizator::getParola() const { 
    return parola;
}

Utilizator& Utilizator::setParola(const std::string &parola_) { 
    parola = parola_;
    return *this;
}

bool Utilizator::operator==(const Utilizator &other) const {
    return id == other.id;
}
