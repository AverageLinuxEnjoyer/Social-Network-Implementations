#ifndef PRIETENIE_H
#define PRIETENIE_H

#include <vector>

class Utilizator;

class Prietenie {
public:
    Prietenie();
    Prietenie(const Prietenie &other);
    Prietenie(const Utilizator *user1, const Utilizator *user2);
    Prietenie& operator=(const Prietenie &other);
    ~Prietenie() = default;

    const Utilizator *getUser1() const;
    const Utilizator *getUser2() const;

    bool operator==(const Prietenie &other) const;
    bool operator!=(const Prietenie &other) const;

private:
    const Utilizator *user1;
    const Utilizator *user2;
};

#endif // PRIETENIE_H
