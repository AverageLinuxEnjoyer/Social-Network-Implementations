#pragma once
#include "dictionar.h"
#include "prietenie.h"
#include "user.h"
#include "mesaj.h"
#include "lista.h"
#include "eveniment.h"

class Retea
{
private:
	Dictionary<int, Lista<int>> prietenii;
	Lista<User> utilizatori;
	Lista<Eveniment> evenimente;
	Lista<Mesaj> mesaje;
public:
	Retea();

	bool adaugaUtilizator(User utilizator);
	bool stergeUtilizator(int id);
	bool modificaUtilizator(int id, User user);
	Lista<User> getAllUtilizatori();
	User getUtilizatorById(int id);
	
	bool adaugaEveniment(Eveniment eveniment);
	bool stergeEveniment(string nume);
	bool modificaEveniment(string nume, Eveniment eveniment);
	Lista<Eveniment> getAllEvenimente();

	bool adaugaMesaj(Mesaj mesaj);
	bool stergeMesaj(string mesaj);
	Lista<Mesaj> getBetweenUsers(int id_user_1, int id_user_2);

	bool adaugaPrietenie(int id_user_1, int id_user_2);
	bool stergePrietenie(int id_user_1, int id_user_2S);
	Lista<User> getAllPrietenii(int id_user);
};

