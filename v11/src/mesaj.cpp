#include "../include/mesaj.h"

Mesaj::Mesaj()
{

}

Mesaj::Mesaj(int id_user1, int id_user2, std::string continut)
{
    this->id_user1 = id_user1;
    this->id_user2 = id_user2;
    this->continut = continut;
}

Mesaj::~Mesaj()
{
    
}

int Mesaj::getIdUser1() {
    return id_user1;
}

int Mesaj::getIdUser2() {
    return id_user2;
}

std::string Mesaj::getContinut() {
    return continut;
}

void Mesaj::setIdUser1(int idUser1) { 
    id_user1 = idUser1; 
}

void Mesaj::setIdUser2(int idUser2) { 
    id_user2 = idUser2; 
}

void Mesaj::setContinut(const std::string &continut_) { 
    continut = continut_; 
}

