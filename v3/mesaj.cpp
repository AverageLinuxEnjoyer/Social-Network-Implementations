#include "mesaj.h"

Mesaj::Mesaj()
{
    
}

Mesaj::Mesaj(int id_user_expeditor, int id_user_destinatar, string continut)
{
    this->id_user_expeditor = id_user_expeditor;
    this->id_user_destinatar = id_user_destinatar;
    this->continut = continut;
}

Mesaj::~Mesaj()
{
    
}

int Mesaj::getId_user_expeditor() {
    return this->id_user_expeditor;
}

int Mesaj::getId_user_destinatar() {
    return this->id_user_destinatar;
}

string Mesaj::getContinut() {
    return this->continut;
}

void Mesaj::setId_user_expeditor(int id_user_expeditor) {
    this->id_user_expeditor = id_user_expeditor;
}

void Mesaj::setId_user_destinatar(int id_user_destinatar) {
    this->id_user_destinatar = id_user_destinatar;
}

void Mesaj::setContinut(string continut) {
    this->continut = continut;
}

bool Mesaj::operator==(const Mesaj &mesaj) {
    return this->id_user_expeditor == mesaj.id_user_expeditor && this->id_user_destinatar == mesaj.id_user_destinatar && this->continut == mesaj.continut;
}

bool Mesaj::operator<(const Mesaj &mesaj) {
    return this->id_user_expeditor < mesaj.id_user_expeditor && this->id_user_destinatar < mesaj.id_user_destinatar && this->continut < mesaj.continut;
}
