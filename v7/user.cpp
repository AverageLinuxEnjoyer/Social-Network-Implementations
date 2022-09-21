#include "user.h"

User::User(int a_id, string a_nume, int a_varsta)
{
	setId(a_id);
	setNume(a_nume);
	setVarsta(a_varsta);
}

int User::getId()
{
	return id;
}

string User::getNume()
{
	return nume;
}

int User::getVarsta()
{
	return varsta;
}

void User::setId(int a_id)
{
	this->id = a_id;
}

void User::setNume(string a_nume)
{
	this->nume = a_nume;
}

void User::setVarsta(int a_varsta)
{
	this->varsta = a_varsta;
}
