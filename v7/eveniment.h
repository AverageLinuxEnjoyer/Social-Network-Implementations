#pragma once
#include <string>
using namespace std;
class Eveniment
{
private:
	string nume;
	string locatie;
	string data;
public:
	Eveniment();
	Eveniment(string nume, string locatie, string data);

	void setNume(string a_nume);
	void setLocatie(string a_locatie);
	void setData(string a_data);
	string getNume();
	string getLocatie();
	string getData();
};

