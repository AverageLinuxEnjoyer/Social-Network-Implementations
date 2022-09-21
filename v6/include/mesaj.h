#ifndef MESAJ_H
#define MESAJ_H

#include <iostream>

class Mesaj {
public:
    Mesaj();
    Mesaj(int id1, int id2, const std::string &text);

    int getId1() const;
    int getId2() const;
    void setId1(int id1);
    void setId2(int id2);

    std::string getText() const;
    void setText(const std::string &text);

    friend std::ostream& operator<<(std::ostream& os, const Mesaj& mesaj);
    friend std::istream& operator>>(std::istream& is, Mesaj& mesaj);

private:
    int idUser1;
    int idUser2;
    std::string text;
};

#endif // MESAJ_H
