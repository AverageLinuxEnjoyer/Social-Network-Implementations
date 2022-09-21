#include "User.h"

bool User::operator==(const User& other) const {
    return nume == other.nume && prenume == other.prenume && varsta == other.varsta;
}

bool User::operator<(const User& other) const {
    if (nume < other.nume)
        return true;
    if (nume == other.nume && prenume < other.prenume)
        return true;
    if (nume == other.nume && prenume == other.prenume && varsta < other.varsta)
        return true;
    return false;
}

bool User::operator!=(const User& other) const {
    return !(*this == other);
}

string User::getNume() const { 
    return nume; 
}

void User::setNume(const string &nume_) { 
    nume = nume_; 
}

string User::getPrenume() const { 
    return prenume; 
}

void User::setPrenume(const string &prenume_) { 
    prenume = prenume_;
}

int User::getVarsta() const { 
    return varsta; 
}

void User::setVarsta(int varsta_) { 
    varsta = varsta_; 
}

User::User()
{
    
}

User::User(string nume_, string prenume_, int varsta_)
{
    nume = nume_;
    prenume = prenume_;
    varsta = varsta_;
}

User::~User()
{
    
}

