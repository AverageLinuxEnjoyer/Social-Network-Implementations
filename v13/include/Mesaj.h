#ifndef MESAJ_H
#define MESAJ_H

#include <iostream>
#include "Utilizator.h"
using namespace std;

class Mesaj {  
private:
    static int nr_mesaje;
    int nr;
    string text;
    Utilizator expeditor;
    Utilizator destinatar;

public:
    Mesaj();
    Mesaj(string text, Utilizator expeditor, Utilizator destinatar);
    Mesaj(const Mesaj& mesaj);
    Mesaj& operator=(const Mesaj& mesaj);
    int get_nr() const;
    string get_text() const;
    Utilizator get_expeditor() const;
    Utilizator get_destinatar() const;
    void set_nr(int nr);
    void set_text(string text);
    void set_expeditor(Utilizator expeditor);
    void set_destinatar(Utilizator destinatar);
    bool operator==(const Mesaj& mesaj) const;
    bool operator!=(const Mesaj& mesaj) const;
    bool operator<(const Mesaj& mesaj) const;
    bool operator>(const Mesaj& mesaj) const;
};

#endif // MESAJ_H
