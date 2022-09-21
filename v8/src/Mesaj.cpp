#include "../include/Mesaj.h"

Mesaj::Mesaj()
{
    id = 0;
    id1 = 0;
    id2 = 0;
    text = "";
    data = "";
}


Mesaj::Mesaj(int id, int id1, int id2, std::string text, std::string data)
{
    this->id = id;
    this->id1 = id1;
    this->id2 = id2;
    this->text = text;
    this->data = data;
}


int Mesaj::getId() const {
    return id;
}


int Mesaj::getId1() const
{
    return id1;
}


int Mesaj::getId2() const
{
    return id2;
}


std::string Mesaj::getText() const
{
    return text;
}


std::string Mesaj::getData() const
{
    return data;
}


void Mesaj::setId(int id) {
    this->id = id;
}


void Mesaj::setId1(int id1)
{
    this->id1 = id1;
}


void Mesaj::setId2(int id2)
{
    this->id2 = id2;
}


void Mesaj::setText(std::string text)
{
    this->text = text;
}


void Mesaj::setData(std::string data)
{
    this->data = data;
}

bool Mesaj::operator==(const Mesaj& other) const {
    return id == other.id;
}

bool Mesaj::operator!=(const Mesaj& other) const {
    return id != other.id;
}
