#ifndef DICTIONAR_H
#define DICTIONAR_H

#include <iostream>

template<class T, class U>
class Dictionar {
    struct Nod {
        T cheie;
        U valoare;
        Nod *urmatorul_nod;
    };
public:
    class Iterator {
    public:
        Iterator(Nod *nod);

        U& operator*();
        U* operator->();

        Iterator& operator++();
        Iterator operator++(int);

        bool operator==(const Iterator& other) const;
        bool operator!=(const Iterator& other) const;
    private:
        Nod *curent;
    };

    Dictionar();
    ~Dictionar();

    void adaugare(T cheie, U valoare);
    void stergere(T cheie);
    bool contine_cheie(T cheie);
    U get_valoare(T cheie);
    
    U& operator[](T cheie);

    Iterator begin();
    Iterator end();

    int getDim();
    void print();

private:
    Nod *primul_nod;
    int dimensiune;
};

template<class T, class U>
inline Dictionar<T, U>::Dictionar()
    : primul_nod(nullptr),
      dimensiune(0)
{}

template<class T, class U>
inline Dictionar<T, U>::~Dictionar()
{
    Nod *curent = primul_nod;
    while (curent != nullptr) {
        Nod *urmatorul_nod = curent->urmatorul_nod;
        delete curent;
        curent = urmatorul_nod;
    }
}

template<class T, class U>
inline void Dictionar<T, U>::adaugare(T cheie, U valoare) {
    if (contine_cheie(cheie)) {
        Nod *curent = primul_nod;
        while (curent != nullptr) {
            if (curent->cheie == cheie) {
                curent->valoare = valoare;
                return;
            }
            curent = curent->urmatorul_nod;
        }
    }
    
    Nod *n = new Nod{cheie, valoare, primul_nod};
    primul_nod = n;

    dimensiune++;
}

template<class T, class U>
inline void Dictionar<T, U>::stergere(T cheie) {
    Nod *curent = primul_nod;
    Nod *prev = nullptr;
    while (curent != nullptr) {
        if (curent->cheie == cheie) {
            if (prev == nullptr) {
                primul_nod = curent->urmatorul_nod;
            } else {
                prev->urmatorul_nod = curent->urmatorul_nod;
            }
            delete curent;
            dimensiune--;
            return;
        }
        prev = curent;
        curent = curent->urmatorul_nod;
    }
}

template<class T, class U>
inline bool Dictionar<T, U>::contine_cheie(T cheie) {
    Nod *curent = primul_nod;
    while (curent != nullptr) {
        if (curent->cheie == cheie) {
            return true;
        }
        curent = curent->urmatorul_nod;
    }
    return false;
}

template<class T, class U>
inline U Dictionar<T, U>::get_valoare(T cheie) {
    Nod *curent = primul_nod;
    while (curent != nullptr) {
        if (curent->cheie == cheie) {
            return curent->valoare;
        }
        curent = curent->urmatorul_nod;
    }
    return U();
}

template<class T, class U>
inline U& Dictionar<T, U>::operator[](T cheie) {
    Nod *curent = primul_nod;
    while (curent != nullptr) {
        if (curent->cheie == cheie) {
            return curent->valoare;
        }
        curent = curent->urmatorul_nod;
    }

    if  (!curent)
    {
        adaugare(cheie, U());
        return primul_nod->valoare;
    }

    return curent->valoare;
}

template<class T, class U>
inline typename Dictionar<T, U>::Iterator Dictionar<T, U>::begin() {
    return Iterator(primul_nod);
}

template<class T, class U>
inline typename Dictionar<T, U>::Iterator Dictionar<T, U>::end() {
    return Iterator(nullptr);
}

template<class T, class U>
inline int Dictionar<T, U>::getDim() {
    return dimensiune;
}

template<class T, class U>
inline void Dictionar<T, U>::print() {
    Nod *curent = primul_nod;
    while (curent != nullptr) {
        std::cout << "{" << curent->cheie << ": " << curent->valoare << ", " << "}";
        curent = curent->urmatorul_nod;
    }
}

template<class T, class U>
inline Dictionar<T, U>::Iterator::Iterator(Nod *nod)
    : curent(nod)
{}

template<class T, class U>
inline U& Dictionar<T, U>::Iterator::operator*() {
    return curent->valoare;
}

template<class T, class U>
inline U* Dictionar<T, U>::Iterator::operator->() {
    return &curent->valoare;
}

template<class T, class U>
inline typename Dictionar<T, U>::Iterator& Dictionar<T, U>::Iterator::operator++() {
    curent = curent->urmatorul_nod;
    return *this;
}

template<class T, class U>
inline typename  Dictionar<T, U>::Iterator Dictionar<T, U>::Iterator::operator++(int) {
    Iterator tmp(*this);
    curent = curent->urmatorul_nod;
    return tmp;
}

template<class T, class U>
inline bool Dictionar<T, U>::Iterator::operator==(const Iterator& other) const {
    return curent == other.curent;
}

template<class T, class U>
inline bool Dictionar<T, U>::Iterator::operator!=(const Iterator& other) const {
    return curent != other.curent;
}





#endif // DICTIONAR_H
