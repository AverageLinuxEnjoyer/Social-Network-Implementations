#include "../include/Mesaj.h"

Mesaj::Mesaj()
    : expeditor(nullptr),
      destinatar(nullptr)
{}

Mesaj::Mesaj(Utilizator* expeditor, Utilizator* destinatar, std::string continut)
    : expeditor(expeditor),
      destinatar(destinatar),
      continut(continut)
{}

const Utilizator* Mesaj::getExpeditor() const { 
    return this->expeditor; 
}

void Mesaj::setExpeditor(Utilizator* expeditor) {
    this->expeditor = expeditor;
}

const Utilizator* Mesaj::getDestinatar() const { 
    return this->destinatar; 
}

void Mesaj::setDestinatar(Utilizator* destinatar) {
    this->destinatar = destinatar;
}

std::string Mesaj::getContinut() const { 
    return continut; 
}

void Mesaj::setContinut(const std::string &continut_) { 
    continut = continut_; 
}
