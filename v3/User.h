#pragma once

#include <string>
using namespace std;

class User 
{
private:
    int id;
    string nume;
    string prenume;

public:
    User() = default;
    User(int id_, string nume_, string prenume_);

    int getId() const;
    void setId(int id_);

    string getNume() const;
    void setNume(const string &nume_);

    string getPrenume() const;
    void setPrenume(const string &prenume_);

    bool operator==(const User &user);
    bool operator<(const User &user);
};