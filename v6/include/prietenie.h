#ifndef PRIETENIE_H
#define PRIETENIE_H

#include <iostream>

class Prietenie {
public:
    Prietenie();
    Prietenie(int id1, int id2);

    int getId1() const;
    int getId2() const;
    void setId1(int id1);
    void setId2(int id2);
    
    friend std::ostream& operator<<(std::ostream& os, const Prietenie& prietenie);
    friend std::istream& operator>>(std::istream& is, Prietenie& prietenie);

private:
    int idUser1;
    int idUser2;
};

#endif // PRIETENIE_H
