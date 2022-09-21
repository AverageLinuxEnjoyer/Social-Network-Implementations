#ifndef PRIETENIE_H
#define PRIETENIE_H

#include <iostream>
using namespace std;

class Prietenie {
private:
    string nume_user1;
    string nume_user2;

public:
    string getNume_user1() const;
    void setNume_user1(string nume_user1_);

    string getNume_user2() const;
    void setNume_user2(string nume_user2_);

    Prietenie();
    Prietenie(string nume_user1_, string nume_user2_);
    ~Prietenie();
};

#endif // PRIETENIE_H
