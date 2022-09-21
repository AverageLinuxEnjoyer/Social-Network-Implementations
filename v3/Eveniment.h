#pragma once

#include <string>
using namespace std;

class Eveniment {
private:
    int id;
    string nume;
    string data;

public:
    Eveniment() = default;
    Eveniment(int id_, string nume_, string data_);

    int getId() const;
    void setId(int id_);

    string getNume() const;
    void setNume(const string &nume_);

    string getData() const;
    void setData(const string &data_);

    bool operator==(const Eveniment &eveniment);
    bool operator<(const Eveniment &eveniment);
public:
    
};