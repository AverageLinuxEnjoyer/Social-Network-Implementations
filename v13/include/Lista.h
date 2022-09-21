#ifndef LISTA_H
#define LISTA_H

template<class T>
class Lista {
private:
    T* elemente;
    int dimensiune;
    int capacitate;

    void resize(int capacitateNoua) {
        T* elementeNou = new T[capacitateNoua];
        for (int i = 0; i < dimensiune; i++) {
            elementeNou[i] = elemente[i];
        }
        delete[] elemente;
        elemente = elementeNou;
        capacitate = capacitateNoua;
    }
public:
    Lista() {
        elemente = new T[0];
        dimensiune = 0;
        capacitate = 0;
    }
    Lista(int capacitate) {
        elemente = new T[capacitate];
        dimensiune = 0;
        this->capacitate = capacitate;
    }
    Lista(const Lista& Lista) {
        elemente = new T[Lista.capacitate];
        dimensiune = Lista.dimensiune;
        capacitate = Lista.capacitate;
        for (int i = 0; i < dimensiune; i++) {
            elemente[i] = Lista.elemente[i];
        }
    }
    Lista& operator=(const Lista& Lista) {
        if (this != &Lista) {
            delete[] elemente;
            elemente = new T[Lista.capacitate];
            dimensiune = Lista.dimensiune;
            capacitate = Lista.capacitate;
            for (int i = 0; i < dimensiune; i++) {
                elemente[i] = Lista.elemente[i];
            }
        }
        return *this;
    }
    ~Lista() {
        if (elemente) {
            delete[] elemente;
        }
    }
    int get_dimensiune() const {
        return dimensiune;
    }
    int get_capacitate() const {
        return capacitate;
    }
    T& get_element(int pozitie) const {
        return elemente[pozitie];
    }
    void set_element(int pozitie, T element) {
        elemente[pozitie] = element;
    }
    void adauga_element(T element) {
        if (capacitate == 0) {
            capacitate = 1;
            elemente = new T[capacitate];
        }

        if (dimensiune == capacitate) {
            resize(capacitate * 2);
        }

        elemente[dimensiune++] = element;
    }
    void sterge_element(int pozitie) {
        for (int i = pozitie; i < dimensiune - 1; i++) {
            elemente[i] = elemente[i + 1];
        }
        dimensiune--;
    }
    void sterge_ultimul_element() {
        sterge_element(dimensiune - 1);
    }
};

#endif // LISTA_H
