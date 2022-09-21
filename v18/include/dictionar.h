#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <iostream>

template<class T, class U>
class Dictionar {
    struct Nod {
        T cheie;
        U valoare;
        Nod *urmator;
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

    bool contine(T cheie);

    bool schimbare_cheie(T oldcheie, T newcheie);

    U get(T cheie);
    
    U& operator[](T cheie);

    Iterator begin();

    Iterator end();

    int size();

    void print();

private:
    Nod *head;
    int nr_elemente;
};

template<class T, class U>
inline Dictionar<T, U>::Dictionar()
    : head(nullptr),
      nr_elemente(0)
{}

template<class T, class U>
inline Dictionar<T, U>::~Dictionar()
{
    Nod *curent = head;
    while (curent != nullptr) {
        Nod *urmator = curent->urmator;
        delete curent;
        curent = urmator;
    }
}

template<class T, class U>
inline void Dictionar<T, U>::adaugare(T cheie, U valoare) {
    if (contine(cheie)) {
        Nod *curent = head;
        while (curent != nullptr) {
            if (curent->cheie == cheie) {
                curent->valoare = valoare;
                return;
            }
            curent = curent->urmator;
        }
    }
    
    Nod *n = new Nod{cheie, valoare, head};
    head = n;

    nr_elemente++;
}

template<class T, class U>
inline void Dictionar<T, U>::stergere(T cheie) {
    Nod *curent = head;
    Nod *prev = nullptr;
    while (curent != nullptr) {
        if (curent->cheie == cheie) {
            if (prev == nullptr) {
                head = curent->urmator;
            } else {
                prev->urmator = curent->urmator;
            }
            delete curent;
            nr_elemente--;
            return;
        }
        prev = curent;
        curent = curent->urmator;
    }
}

template<class T, class U>
inline bool Dictionar<T, U>::contine(T cheie) {
    Nod *curent = head;
    while (curent != nullptr) {
        if (curent->cheie == cheie) {
            return true;
        }
        curent = curent->urmator;
    }
    return false;
}

template<class T, class U>
inline bool Dictionar<T, U>::schimbare_cheie(T oldcheie, T newcheie) {
    if (!contine(oldcheie)) {
        return false;
    }
    if (contine(newcheie)) {
        return false;
    }

    Nod *curent = head;
    while (curent != nullptr) {
        if (curent->cheie == oldcheie) {
            curent->cheie = newcheie;
            return true;
        }
        curent = curent->urmator;
    }

    return false;
}

template<class T, class U>
inline U Dictionar<T, U>::get(T cheie) {
    Nod *curent = head;
    while (curent != nullptr) {
        if (curent->cheie == cheie) {
            return curent->valoare;
        }
        curent = curent->urmator;
    }
    return U();
}

template<class T, class U>
inline U& Dictionar<T, U>::operator[](T cheie) {
    Nod *curent = head;
    while (curent != nullptr) {
        if (curent->cheie == cheie) {
            return curent->valoare;
        }
        curent = curent->urmator;
    }

    if  (!curent)
    {
        adaugare(cheie, U());
        return head->valoare;
    }

    return curent->valoare;
}

template<class T, class U>
inline typename Dictionar<T, U>::Iterator Dictionar<T, U>::begin() {
    return Iterator(head);
}

template<class T, class U>
inline typename Dictionar<T, U>::Iterator Dictionar<T, U>::end() {
    return Iterator(nullptr);
}

template<class T, class U>
inline int Dictionar<T, U>::size() {
    return nr_elemente;
}

template<class T, class U>
inline void Dictionar<T, U>::print() {
    Nod *curent = head;
    while (curent != nullptr) {
        std::cout << "{" << curent->cheie << ": " << curent->valoare << ", " << "}";
        curent = curent->urmator;
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
    curent = curent->urmator;
    return *this;
}

template<class T, class U>
inline typename  Dictionar<T, U>::Iterator Dictionar<T, U>::Iterator::operator++(int) {
    Iterator tmp(*this);
    curent = curent->urmator;
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





#endif // DICTIONARY_H
