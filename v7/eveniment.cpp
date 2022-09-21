#include "eveniment.h"

Eveniment::Eveniment()
{
	
}

Eveniment::Eveniment(string nume, string locatie, string data)
{
	this->nume = nume;
	this->locatie = locatie;
	this->data = data;
}

void Eveniment::setNume(string a_nume)
{
	nume = a_nume;
}

void Eveniment::setLocatie(string a_locatie)
{
	locatie = a_locatie;
}

void Eveniment::setData(string a_data)
{
	data = a_data;
}

string Eveniment::getNume()
{
	return nume;
}

string Eveniment::getLocatie()
{
	return locatie;
}

string Eveniment::getData()
{
	return data;
}
