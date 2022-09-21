#include "Mesaj.h"

bool Mesaj::operator==(const Mesaj& other) const {
    return nume_user1 == other.nume_user1 && nume_user2 == other.nume_user2 && mesaj == other.mesaj;
}

bool Mesaj::operator<(const Mesaj& other) const {
    if (nume_user1 < other.nume_user1)
        return true;
    if (nume_user1 == other.nume_user1 && nume_user2 < other.nume_user2)
        return true;
    if (nume_user1 == other.nume_user1 && nume_user2 == other.nume_user2 && mesaj < other.mesaj)
        return true;
    return false;
}

bool Mesaj::operator!=(const Mesaj& other) const {
    return !(*this == other);
}

string Mesaj::getNume_user1() const {
    return nume_user1;
}


void Mesaj::setNume_user1(string nume_user1_) {
    nume_user1 = nume_user1_;
}


string Mesaj::getNume_user2() const {
    return nume_user2;
}


void Mesaj::setNume_user2(string nume_user2_) {
    nume_user2 = nume_user2_;
}


string Mesaj::getMesaj() const {
    return mesaj;
}


void Mesaj::setMesaj(string mesaj_) {
    mesaj = mesaj_;
}


Mesaj::Mesaj()
{
    
}


Mesaj::Mesaj(string nume_user1_, string nume_user2_, string mesaj_)
{
    nume_user1 = nume_user1_;
    nume_user2 = nume_user2_;
    mesaj = mesaj_;
}


Mesaj::~Mesaj()
{
    
}