#pragma once

#include <string>

using namespace std;

class Mesaj {
private:
    int id_user_expeditor;
    int id_user_destinatar;
    string continut;

public:
    Mesaj();
    Mesaj(int id_user_expeditor, int id_user_destinatar, string continut);
    ~Mesaj();

    int getId_user_expeditor();
    int getId_user_destinatar();
    string getContinut();

    void setId_user_expeditor(int id_user_expeditor);
    void setId_user_destinatar(int id_user_destinatar);
    void setContinut(string continut);

    bool operator==(const Mesaj &mesaj);
    bool operator<(const Mesaj &mesaj);
};