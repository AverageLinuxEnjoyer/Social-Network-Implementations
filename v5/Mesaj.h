#ifndef MESAJ_H
#define MESAJ_H

#include <iostream>
using namespace std;

class Mesaj {
private:
    string nume_user1;
    string nume_user2;
    string mesaj;

public:
    bool operator==(const Mesaj& other) const;
    bool operator<(const Mesaj& other) const;
    bool operator!=(const Mesaj& other) const;

    string getNume_user1() const;
    void setNume_user1(string nume_user1_);

    string getNume_user2() const;
    void setNume_user2(string nume_user2_);

    string getMesaj() const;
    void setMesaj(string mesaj_);

    Mesaj();
    Mesaj(string nume_user1_, string nume_user2_, string mesaj_);
    ~Mesaj();
};


#endif // MESAJ_H
