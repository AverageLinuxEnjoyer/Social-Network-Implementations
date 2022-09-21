#ifndef LIST_H
#define LIST_H

template<class T>
class Lista {
private:
    T* elemente;
    int nr_elems;
    int capacitate;

    void resize(int new_capacitate) {
        T* new_elemente = new T[new_capacitate];
        for (int i = 0; i < nr_elems; i++) {
            new_elemente[i] = elemente[i];
        }
        delete[] elemente;
        elemente = new_elemente;
        capacitate = new_capacitate;
    }

public:
    Lista() : elemente(new T[5]), nr_elems(0), capacitate(5) {}
    Lista(int capacitate) : elemente(new T[capacitate]), nr_elems(0), capacitate(capacitate) {}
    Lista(const Lista& other) : elemente(new T[other.capacitate]), nr_elems(other.nr_elems), capacitate(other.capacitate) {
        for (int i = 0; i < nr_elems; i++) {
            elemente[i] = other.elemente[i];
        }
    }

    ~Lista() {
        delete[] elemente;
    }

    int getNrElems() const {
        return nr_elems;
    }

    void stergere(int index) {
        if (index < 0 || index >= nr_elems) {
            throw "Index out of range";
        }
        for (int i = index; i < nr_elems - 1; i++) {
            elemente[i] = elemente[i + 1];
        }
        nr_elems--;
    }

    void inserare(int index, T value) {
        if (index < 0 || index > nr_elems) {
            throw "Index out of range";
        }
        if (nr_elems == capacitate) {
            resize(capacitate * 2);
        }
        for (int i = nr_elems; i > index; i--) {
            elemente[i] = elemente[i - 1];
        }
        elemente[index] = value;
        nr_elems++;
    }

    void inserare_sfarsit(T elem) {
        if (nr_elems == capacitate) {
            resize(capacitate * 2);
        }
        elemente[nr_elems++] = elem;
    }

    void stergere_sfarsit() {
        if (nr_elems > 0) {
            nr_elems--;
        }
    }

    T& operator[](int index) {
        return elemente[index];
    }

    const T& operator[](int index) const {
        return elemente[index];
    }

    Lista& operator=(const Lista& other) {
        if (this != &other) {
            delete[] elemente;
            elemente = new T[other.capacitate];
            nr_elems = other.nr_elems;
            capacitate = other.capacitate;
            for (int i = 0; i < nr_elems; i++) {
                elemente[i] = other.elemente[i];
            }
        }
        return *this;
    }
};

#endif // LIST_H
