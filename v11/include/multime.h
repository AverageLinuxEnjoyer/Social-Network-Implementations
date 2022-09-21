#ifndef Multime_H
#define Multime_H

#include <vector>
#include <iostream>

template<class T>
class Multime {
    struct Nod {
        T valoare;
        Nod *urmatorul;
    };

public:
    Multime();
    ~Multime();

    T getById(int id);
    void adaugare(T valoare);
    void stergere(T valoare);
    bool exista(T valoare);
    int getDim();

    std::vector<T> toVector();

    void print();

private:
    Nod* head;
    int dim;

};

template<class T>
inline Multime<T>::Multime()
    : head(nullptr),
      dim(0)
{}

template<class T>
inline Multime<T>::~Multime() {
    Nod *current = head;
    while (current != nullptr) {
        Nod *urmatorul = current->urmatorul;
        delete current;
        current = urmatorul;
    }
}

template<class T>
inline T Multime<T>::getById(int id) {
    Nod *current = head;
    while (current != nullptr) {
        if (current->valoare.getId() == id) {
            return current->valoare;
        }
        current = current->urmatorul;
    }
    return T();
}

template<class T>
inline void Multime<T>::adaugare(T valoare) {
    if (exista(valoare)) {
        return;
    }

    Nod *n = new Nod{valoare, head};
    head = n;

    dim++;
}

template<class T>
inline void Multime<T>::stergere(T valoare) {
    Nod *current = head;
    Nod *prev = nullptr;
    while (current != nullptr) {
        if (current->valoare == valoare) {
            if (prev == nullptr) {
                head = current->urmatorul;
            } else {
                prev->urmatorul = current->urmatorul;
            }
            delete current;
            dim--;
            return;
        }
        prev = current;
        current = current->urmatorul;
    }
}

template<class T>
inline bool Multime<T>::exista(T valoare) {
    Nod *current = head;
    while (current != nullptr) {
        if (current->valoare == valoare) {
            return true;
        }
        current = current->urmatorul;
    }
    return false;
}

template<class T>
inline int Multime<T>::getDim() {
    return dim;
}

template<class T>
inline std::vector<T> Multime<T>::toVector() {
    std::vector<T> rezultat;
    Nod *current = head;
    while (current != nullptr) {
        rezultat.push_back(current->valoare);
        current = current->urmatorul;
    }
    return rezultat;
}

template<class T>
inline void Multime<T>::print() {
    Nod *current = head;
    while (current != nullptr) {
        std::cout << current->valoare << " ";
        current = current->urmatorul;
    }
}

#endif // Multime_H
