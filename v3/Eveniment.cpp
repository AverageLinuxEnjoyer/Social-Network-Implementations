#include "Eveniment.h"


Eveniment::Eveniment(int id_, string nume_, string data_)
{
    id = id_;
    nume = nume_;
    data = data_;
}

int Eveniment::getId() const { return id; }

void Eveniment::setId(int id_) { id = id_; }

string Eveniment::getNume() const { return nume; }

void Eveniment::setNume(const string &nume_) { nume = nume_; }

string Eveniment::getData() const { return data; }

void Eveniment::setData(const string &data_) { data = data_; }

bool Eveniment::operator==(const Eveniment &eveniment) {
    return this->id == eveniment.id && this->nume == eveniment.nume && this->data == eveniment.data;
}

bool Eveniment::operator<(const Eveniment &eveniment) {
    return this->id < eveniment.id && this->nume < eveniment.nume && this->data < eveniment.data;
}
