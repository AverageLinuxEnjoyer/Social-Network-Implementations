#include "retea.h"

Retea::Retea()
{

}

bool Retea::adaugaUtilizator(User utilizator)
{
	for (int i = 0; i < utilizatori.getMarime(); i++)
	{
		if (utilizatori[i].getId() == utilizator.getId())
			return false;
	}
	utilizatori.adauga(utilizator, utilizatori.getMarime());
	return true;
}

bool Retea::stergeUtilizator(int id)
{
	for (int i = 0; i < utilizatori.getMarime(); i++)
	{
		if (utilizatori[i].getId() == id)
		{
			utilizatori.stergere(i);
			return true;
		}
	}
	return false;
}

bool Retea::modificaUtilizator(int id, User user)
{
	for (int i = 0; i < utilizatori.getMarime(); i++)
	{
		if (utilizatori[i].getId() == id)
		{
			utilizatori[i] = user;
			return true;
		}
	}
	return false;
}

Lista<User> Retea::getAllUtilizatori()
{
	return utilizatori;
}

User Retea::getUtilizatorById(int id)
{
	for (int i = 0; i < utilizatori.getMarime(); i++)
	{
		if (utilizatori[i].getId() == id)
			return utilizatori[i];
	}
	return User();
}

bool Retea::adaugaEveniment(Eveniment eveniment)
{
	for (int i = 0; i < evenimente.getMarime(); i++)
	{
		if (evenimente[i].getNume() == eveniment.getNume())
			return false;
	}
	evenimente.adauga(eveniment, evenimente.getMarime());
	return true;
}

bool Retea::stergeEveniment(string nume)
{
	for (int i = 0; i < evenimente.getMarime(); i++)
	{
		if (evenimente[i].getNume() == nume)
		{
			evenimente.stergere(i);
			return true;
		}
	}
	return false;
}

bool Retea::modificaEveniment(string nume, Eveniment eveniment)
{
	for (int i = 0; i < evenimente.getMarime(); i++)
	{
		if (evenimente[i].getNume() == nume)
		{
			evenimente[i] = eveniment;
			return true;
		}
	}
	return false;
}

Lista<Eveniment> Retea::getAllEvenimente()
{
	return evenimente;
}

bool Retea::adaugaMesaj(Mesaj mesaj)
{
	for (int i = 0; i < mesaje.getMarime(); i++)
	{
		if (mesaje[i].getMesaj() == mesaj.getMesaj())
			return false;
	}
	mesaje.adauga(mesaj, utilizatori.getMarime());
	return true;
}

bool Retea::stergeMesaj(string mesaj)
{
	for (int i = 0; i < mesaje.getMarime(); i++)
	{
		if (mesaje[i].getMesaj() == mesaj)
		{
			mesaje.stergere(i);
			return true;
		}
	}
	return false;
}

Lista<Mesaj> Retea::getBetweenUsers(int id_user_1, int id_user_2)
{
	Lista<Mesaj> mesaje_user_1;
	Lista<Mesaj> mesaje_user_2;
	for (int i = 0; i < mesaje.getMarime(); i++)
	{
		if (mesaje[i].getIdUser1() == id_user_1)
			mesaje_user_1.adauga(mesaje[i], mesaje_user_1.getMarime());
		if (mesaje[i].getIdUser2() == id_user_2)
			mesaje_user_2.adauga(mesaje[i], mesaje_user_2.getMarime());
	}

	Lista<Mesaj> mesaje_intersectie;
	for (int i = 0; i < mesaje_user_1.getMarime(); i++)
	{
		for (int j = 0; j < mesaje_user_2.getMarime(); j++)
		{
			if (mesaje_user_1[i].getIdUser2() == mesaje_user_2[j].getIdUser1())
				mesaje_intersectie.adauga(mesaje_user_1[i], mesaje_intersectie.getMarime());
		}
	}
	
	return mesaje_intersectie;
}

bool Retea::adaugaPrietenie(int id_user_1, int id_user_2)
{
	for (int i = 0; i < prietenii[id_user_1].getMarime(); i++)
	{
		if (prietenii[id_user_1][i] == id_user_2)
			return false;
	}
	prietenii[id_user_1].adauga(id_user_2, 0);
	prietenii[id_user_2].adauga(id_user_1, 0);
	return true;
}

bool Retea::stergePrietenie(int id_user_1, int id_user_2)
{
	return false;
}

Lista<User> Retea::getAllPrietenii(int id_user)
{
	Lista<User> lista_prietenii;
	Lista<int> ids = prietenii[id_user];

	for (int i = 0; i < ids.getMarime(); i++)
		lista_prietenii.adauga(utilizatori[ids[i]], 0);

	return lista_prietenii;
}
