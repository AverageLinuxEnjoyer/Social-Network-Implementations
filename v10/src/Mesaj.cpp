#include "../include/Mesaj.h"

Mesaj::Mesaj(int id1, int id2, std::string mesaj)
{
    this->id1 = id1;
    this->id2 = id2;
    this->mesaj = mesaj;
}

int Mesaj::getId1() const {
    return id1;
}

void Mesaj::setId1(int new_id1) {
    id1 = new_id1;
}

int Mesaj::getId2() const {
    return id2;
}

void Mesaj::setId2(int new_id2) {
    id2 = new_id2;
}

std::string Mesaj::getMesaj() const {
    return mesaj;
}


void Mesaj::setMesaj(const std::string &new_mesaj) {
    mesaj = new_mesaj;
}

bool Mesaj::operator==(const Mesaj& other) const {
    return (id1 == other.id1 && id2 == other.id2 && mesaj == other.mesaj);
}

bool Mesaj::operator<(const Mesaj& other) const {
    return (id1 < other.id1 || id2 < other.id2 || mesaj < other.mesaj);
}

bool Mesaj::operator>(const Mesaj& other) const {
    return (id1 > other.id1 || id2 > other.id2 || mesaj > other.mesaj);
}

bool Mesaj::operator!=(const Mesaj& other) const {
    return !(*this == other);
}

