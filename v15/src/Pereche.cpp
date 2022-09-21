#include "../include/Pereche.h"
#include <algorithm>

Pereche::Pereche(int a, int b)
    : first(std::min(a, b)),
      second(std::max(a, b))
{}

int Pereche::getFirst() const {
    return first;
}

int Pereche::getSecond() const {
    return second;
}

bool Pereche::operator==(const Pereche& other) const {
    return first == other.first && second == other.second;
}
