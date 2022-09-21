#ifndef EVENIMENT_H
#define EVENIMENT_H

#include <string>

class Eveniment {
private:
    int id;
    std::string nume;
    std::string data;
    std::string locatie;

public:
    Eveniment();
    Eveniment(int id, std::string nume, std::string data, std::string locatie);

    int getId() const;
    std::string getNume() const;
    std::string getData() const;
    std::string getLocatie() const;

    void setId(int id);
    void setNume(std::string nume);
    void setData(std::string data);
    void setLocatie(std::string locatie);

    bool operator==(const Eveniment& other) const;
    bool operator!=(const Eveniment& other) const;
    bool operator<(const Eveniment& other) const;
    bool operator>(const Eveniment& other) const;
};

#endif // EVENIMENT_H
