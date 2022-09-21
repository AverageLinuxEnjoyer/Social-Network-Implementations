#ifndef TAD_LISTA_H
#define TAD_LISTA_H

template<class T>
class Lista {
private:
    T* v;
    int dim;
    int cap;
public:
    Lista() {
        cap = 10;
        dim = 0;
        v = new T[cap];
    }
    void add(T element) {
        if (dim == cap) {
            cap *= 2;
            T* aux = new T[cap];
            for (int i = 0; i < dim; i++) {
                aux[i] = v[i];
            }
            delete[] v;
            v = aux;
        }
        v[dim++] = element;
    }
    void remove(T element) {
        int i = 0;
        while (i < dim && v[i] != element) {
            i++;
        }
        if (i < dim) {
            for (int j = i; j < dim - 1; j++) {
                v[j] = v[j + 1];
            }
            dim--;
        }
    }
    void remove(int index) {
        if (index < dim) {
            for (int j = index; j < dim - 1; j++) {
                v[j] = v[j + 1];
            }
            dim--;
        }
    }
    void removeAll() {
        while (size() > 0) {
            remove(0);
        }
    }
    bool contains(T element) {
        for (int i = 0; i < dim; i++) {
            if (v[i] == element) {
                return true;
            }
        }
        return false;
    }
    int size() {
        return dim;
    }
    T get(int index) {
        return v[index];
    }
};

#endif // TAD_LISTA_H
