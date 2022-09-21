#ifndef MESAJ_H
#define MESAJ_H

#include <string>

class Mesaj {
public:
    Mesaj();
	Mesaj(int id_user1, int id_user2, std::string continut);
	~Mesaj();

	int getIdUser1();
	int getIdUser2();
	std::string getContinut();

	void setIdUser1(int idUser1);
	void setIdUser2(int idUser2);
	void setContinut(const std::string &continut_);

private:
	int id_user1;
	int id_user2;
	std::string continut;
};

#endif // MESAJ_H
