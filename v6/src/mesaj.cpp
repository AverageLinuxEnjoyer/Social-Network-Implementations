#include "../include/mesaj.h"

Mesaj::Mesaj()
{
    
}

Mesaj::Mesaj(int id1, int id2, const std::string &text)
{
    this->idUser1 = id1;
    this->idUser2 = id2;
    this->text = text;
}

int Mesaj::getId1() const 
{
    return idUser1;
}

int Mesaj::getId2() const 
{
    return idUser2;
}

void Mesaj::setId1(int id1) {
    this->idUser1 = id1;
}

void Mesaj::setId2(int id2) 
{
    this->idUser2 = id2;    
}

std::string Mesaj::getText() const 
{
    return text;
}

void Mesaj::setText(const std::string &text) 
{
    this->text = text;
}

std::ostream& operator<<(std::ostream& os, const Mesaj& mesaj) 
{
    os << "Mesaj(idUser1=" << mesaj.idUser1 << ", idUser2=" << mesaj.idUser2 << ", text=" << mesaj.text << ")";
    return os;
}

std::istream& operator>>(std::istream& is, Mesaj& mesaj) 
{
    std::cout << "idUser1=";
    is >> mesaj.idUser1;

    std::cout << "idUser2=";
    is >> mesaj.idUser2;

    std::cout << "text=";
    std::cin.ignore();
    getline(is, mesaj.text);

    return is;
}