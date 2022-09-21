#ifndef PRIETENIE_H
#define PRIETENIE_H

class Prietenie {
private:
    int id1;
    int id2;

public:
    Prietenie();
    Prietenie(int id1, int id2);

    int getId1() const;
    int getId2() const;

    void setId1(int id1);
    void setId2(int id2);

    bool operator==(const Prietenie& other) const;
    bool operator!=(const Prietenie& other) const;
};

#endif // PRIETENIE_H
