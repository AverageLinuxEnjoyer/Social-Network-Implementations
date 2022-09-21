#pragma once
#include <string>
using namespace std;
class User
{
private:
	int id;
	string nume;
	int varsta;
public:
	User() = default;
	User(int a_id, string a_nume, int a_varsta);
	int getId();
	string getNume();
	int getVarsta();
	void setId(int a_id);
	void setNume(string a_nume);
	void setVarsta(int a_varsta);
};

