#include "mesaj.h"


Mesaj::Mesaj()
{
	
}

Mesaj::Mesaj(int id1, int id2, string mesaj)
{
	this->id_user_1 = id1;
	this->id_user_2 = id2;
	this->mesaj = mesaj;
}

void Mesaj::setMesaj(string a_mesaj)
{
	mesaj = a_mesaj;
}

string Mesaj::getMesaj()
{
	return mesaj;
}

void Mesaj::setIdUser1(int id)
{
	this->id_user_1 = id;
}

void Mesaj::setIdUser2(int id)
{
	this->id_user_2 = id;
}

int Mesaj::getIdUser1()
{
	return id_user_1;
}

int Mesaj::getIdUser2()
{
	return id_user_2;
}
