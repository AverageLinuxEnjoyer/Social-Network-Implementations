#include "../include/Retea.h"
#include <exception>
#include <stdexcept>

Retea::Retea()
{
    
}

Retea::~Retea()
{
    
}

void Retea::addUtilizator(Utilizator utilizator) {
    
    // se verifica daca utilizatorul deja exista
    // daca da, se arunca o exceptie
    for (int i = 0; i < this->utilizatori.getSize(); i++) {
        if (this->utilizatori.get(i).getNume() == utilizator.getNume()) {
            throw std::runtime_error("Utilizatorul exista deja!");
        }
    }

    this->utilizatori.add(utilizator);
}

void Retea::removeUtilizator(std::string nume) {

    for (int i = 0; i < this->utilizatori.getSize(); i++) {
        if (this->utilizatori.get(i).getNume() == nume) {
            this->utilizatori.remove(i);
            return;
        }
    }

    // se arunca o exceptie daca utilizatorul care trebuie sa fie sters nu exista
    throw std::runtime_error("Utilizatorul nu exista!");
}

void Retea::updateUtilizator(std::string nume, Utilizator utilizator) {
    
        for (int i = 0; i < this->utilizatori.getSize(); i++) {
            if (this->utilizatori.get(i).getNume() == nume) {
                this->utilizatori.get(i) = utilizator;
                return;
            }
        }
    
        // se arunca o exceptie daca utilizatorul care trebuie sa fie modificat nu exista
        throw std::runtime_error("Utilizatorul nu exista!");
}
