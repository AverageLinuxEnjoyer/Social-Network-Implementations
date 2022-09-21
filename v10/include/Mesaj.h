#ifndef MESAJ_H
#define MESAJ_H

#include <string>

class Mesaj {
private:
    int id1;
    int id2;
    std::string mesaj;

public:
    Mesaj() = default;
    Mesaj(int id1, int id2, std::string mesaj);
    Mesaj(const Mesaj& other) = default;
    ~Mesaj() = default;

    int getId1() const;
    void setId1(int new_id1);

    int getId2() const;
    void setId2(int new_id2);

    std::string getMesaj() const;
    void setMesaj(const std::string &new_mesaj);

    bool operator==(const Mesaj& other) const;
    bool operator<(const Mesaj& other) const;
    bool operator>(const Mesaj& other) const;

    bool operator!=(const Mesaj& other) const;
};

#endif // MESAJ_H
