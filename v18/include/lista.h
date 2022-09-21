#ifndef LIST_H
#define LIST_H

#include <iostream>

template<class T>
class Lista {
public:
    Lista();

    Lista(const Lista& other);

    Lista<T>& operator=(const Lista& other);

    ~Lista();

    T& operator[](int index);
    const T& operator[](int index) const;

    template<class U>
    friend std::ostream& operator<<(std::ostream& os, const Lista<U>& list);
    
    int size() const;

    void inserare(int index, const T& value);

    void inserare_sfarsit(const T& value);

    void stergere_sfarsit();

    void inserare_inceput(const T& value);

    void stergere_inceput();

    void stergere(int index);

    void clear();

    bool isEmpty() const;

    bool operator==(const Lista<T>& other) const;

private:
    int capacitate = 10;
    int nr_elemente = 0;
    T* elemente = nullptr;
};

template<class T>
inline Lista<T>::Lista() 
    : capacitate(10), nr_elemente(0), elemente(new T[capacitate]) {};

template<class T>
inline Lista<T>::Lista(const Lista& other) 
    : nr_elemente(other.nr_elemente), capacitate(other.capacitate), elemente(new T[other.capacitate]) {
    for (int i = 0; i < other.nr_elemente; i++)
        this->elemente[i] = other.elemente[i];
}

template<class T>
inline Lista<T>& Lista<T>::operator=(const Lista& other)  {
    if (this != &other) {
        if (this->elemente)
            delete[] this->elemente;

        this->nr_elemente = other.nr_elemente;
        this->elemente = new T[other.nr_elemente];
        for (int i = 0; i < other.nr_elemente; i++) {
            this->elemente[i] = other.elemente[i];
        }
    }
    return *this;
}


template<class T>
inline Lista<T>::~Lista() {
    this->clear();
}

template<class T>
inline T& Lista<T>::operator[](int index) {
    return this->elemente[index];
}

template<class T>
inline const T& Lista<T>::operator[](int index) const {
    return this->elemente[index];
}

template<class U>
inline std::ostream& operator<<(std::ostream& os, const Lista<U>& list) {
    os << "Lista(s=" << list.nr_elemente << ", c=" << list.capacitate << ")=[";
    for (int i = 0; i < list.nr_elemente; i++) {
        os << list.elemente[i] << ",";
    }
    os << "]";
    return os;
}

template<class T>
inline int Lista<T>::size() const {
    return nr_elemente;
}

template<class T>
inline void Lista<T>::inserare(int index, const T& value) {
    if (elemente == nullptr)
        elemente = new T[capacitate];
    
    if (index < 0 || index > this->nr_elemente)
        throw "Index out of range";

    if (this->nr_elemente == this->capacitate) {
        this->capacitate *= 2;
        T* newData = new T[this->capacitate];
        for (int i = 0; i < this->nr_elemente; i++) {
            newData[i] = this->elemente[i];
        }
        delete[] this->elemente;
        this->elemente = newData;
    }
    for (int i = this->nr_elemente; i > index; i--) {
        this->elemente[i] = this->elemente[i - 1];
    }
    this->elemente[index] = value;
    this->nr_elemente++;
}

template<class T>
inline void Lista<T>::inserare_sfarsit(const T& value) {
    this->inserare(this->nr_elemente, value);
}

template<class T>
inline void Lista<T>::stergere_sfarsit() {
    if (nr_elemente > 0)
        nr_elemente--;
}

template<class T>
inline void Lista<T>::inserare_inceput(const T& value) {
    this->inserare(0, value);
}

template<class T>
inline void Lista<T>::stergere_inceput() {
    if (nr_elemente > 0)
        this->stergere(0);
}

template<class T>
inline void Lista<T>::stergere(int index) {
    if (index < 0 || index >= this->nr_elemente) {
        throw "index gresit";
    }
    for (int i = index; i < this->nr_elemente - 1; i++) {
        this->elemente[i] = this->elemente[i + 1];
    }
    this->nr_elemente--;
}

template<class T>
inline void Lista<T>::clear() {
    if (this->elemente)
        delete[] this->elemente;
        
    this->capacitate = 10;
    this->nr_elemente = 0;
    this->elemente = nullptr;
}

template<class T>
inline bool Lista<T>::isEmpty() const {
    return this->nr_elemente == 0;
}

template<class T>
inline bool Lista<T>::operator==(const Lista<T>& other) const {
    if (this->nr_elemente != other.nr_elemente)
        return false;
    if (this->capacitate != other.capacitate)
        return false;

    for (int i = 0; i < this->nr_elemente; i++) {
        if (this->elemente[i] != other.elemente[i])
            return false;
    }
    return true;
}

#endif // LIST_H
