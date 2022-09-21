#ifndef PRIETENIE_H
#define PRIETENIE_H

#include <string>
#include <iostream>

class Prietenie {
private:
    std::string utilizator1;
    std::string utilziator2;
    bool acceptat;

public:
    Prietenie();
    Prietenie(std::string utilizator1, std::string utilziator2, bool acceptat);
    ~Prietenie();
    std::string getUtilizator1();
    std::string getUtilizator2();
    bool getAcceptat();
    void setUtilizator1(std::string utilizator1);
    void setUtilizator2(std::string utilizator2);
    void setAcceptat(bool acceptat);
    bool operator==(const Prietenie& other);

    friend std::ostream& operator<<(std::ostream& os, const Prietenie& p);
    friend std::istream& operator>>(std::istream& is, Prietenie& p);
};

#endif // PRIETENIE_H
