#pragma once
#include "prietenie.h"
#include <string>
using namespace std;
class Mesaj
{
private:
	int id_user_1;
	int id_user_2;
	string mesaj;
public:
	Mesaj();
	Mesaj(int id1, int id2, string mesaj);
	void setMesaj(string a_mesaj);
	string getMesaj();
	void setIdUser1(int id);
	void setIdUser2(int id);
	int getIdUser1();
	int getIdUser2();
};