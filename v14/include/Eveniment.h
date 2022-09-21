#ifndef EVENIMENT_H
#define EVENIMENT_H

#include <string>
#include <iostream>

class Eveniment {
private:
    std::string titlu;
    std::string data;
    std::string locatie;
    std::string organizator;
public:
    Eveniment();
    Eveniment(std::string titlu, std::string data, std::string locatie, std::string organizator);
    ~Eveniment();
    std::string getTitlu();
    std::string getData();
    std::string getLocatie();
    std::string getOrganizator();
    void setTitlu(std::string titlu);
    void setData(std::string data);
    void setLocatie(std::string locatie);
    void setOrganizator(std::string organizator);
    bool operator==(const Eveniment& other);

    friend std::ostream& operator<<(std::ostream& os, const Eveniment& e);
    friend std::istream& operator>>(std::istream& is, Eveniment& e);
};

#endif // EVENIMENT_H
