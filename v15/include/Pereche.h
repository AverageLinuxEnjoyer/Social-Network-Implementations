#ifndef UNORDERED_PAIR_H
#define UNORDERED_PAIR_H

class Pereche {
public:
    Pereche() = default;
    Pereche(const Pereche& other) = default;
    Pereche(int a, int b);
    ~Pereche() = default;

    int getFirst() const;
    int getSecond() const;

    bool operator==(const Pereche& other) const;

private:
    int first;
    int second;
};

#endif // UNORDERED_PAIR_H
