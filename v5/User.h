#ifndef USER_H
#define USER_H

#include <iostream>
using namespace std;

class User {
private:
    string nume;
    string prenume;
    int varsta;

public:
    bool operator==(const User& other) const;
    bool operator<(const User& other) const;
    bool operator!=(const User& other) const;

    string getNume() const;
    void setNume(const string &nume_);

    string getPrenume() const;
    void setPrenume(const string &prenume_);

    int getVarsta() const;
    void setVarsta(int varsta_);

    User();
    User(string nume_, string prenume_, int varsta_);
    ~User();
};

#endif // USER_H
