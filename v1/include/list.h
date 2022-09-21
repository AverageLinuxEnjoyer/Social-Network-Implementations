#ifndef LIST_H
#define LIST_H

#include <iostream>

template<class T>
class List {
public:
    // Constructor fara parametrii
    // initializeaza lista
    List();

    // Constructor de copiere
    // copiaza fiecare element din lista other in lista curenta
    List(const List& other);

    // operator de atribuire
    // copiaza fiecare element din lista other in lista curenta si o returneaza
    List<T>& operator=(const List& other);

    // destructor
    // distruge lista si elibereaza memoria alocata pentru elementele ei
    ~List();

    // operatori de indexare (pentru elemente normale sau constante)
    // folosita pentru a accesa un element din lista ca si intr-un array normal
    T& operator[](int index);
    const T& operator[](int index) const;

    // operator pentru afisarea elementelor din lista
    template<class U>
    friend std::ostream& operator<<(std::ostream& os, const List<U>& list);
    
    // returneaza marimea listei
    int size() const;

    // insereaza un element la un index specificat
    void insert(int index, const T& value);

    // insereaza un element la sfarsitul listei
    void push_back(const T& value);

    // sterge ultimul element din lista
    void pop_back();

    // insereeaza un element la incepuul listei
    void push_front(const T& value);

    // sterge primul element din lista
    void pop_front();

    // sterge un element din lista la un index specificat
    void remove(int index);

    // sterge toate elementele listei
    void clear();

    // verifica daca lista e goala
    bool isEmpty() const;

    // operator de egalitate
    // verifica daca lista are aceleasi elemente cu o alta listas
    bool operator==(const List<T>& other) const;

private:
    int capacity = 10;
    int count = 0;
    T* data = nullptr;

    friend void test_list();
};

template<class T>
inline List<T>::List() 
    : capacity(10), count(0), data(new T[capacity]) {};

template<class T>
inline List<T>::List(const List& other) 
    : count(other.count), capacity(other.capacity), data(new T[other.capacity]) {
    for (int i = 0; i < other.count; i++)
        this->data[i] = other.data[i];
}

template<class T>
inline List<T>& List<T>::operator=(const List& other)  {
    if (this != &other) {
        if (this->data)
            delete[] this->data;

        this->count = other.count;
        this->data = new T[other.count];
        for (int i = 0; i < other.count; i++) {
            this->data[i] = other.data[i];
        }
    }
    return *this;
}


template<class T>
inline List<T>::~List() {
    this->clear();
}

template<class T>
inline T& List<T>::operator[](int index) {
    return this->data[index];
}

template<class T>
inline const T& List<T>::operator[](int index) const {
    return this->data[index];
}

template<class U>
inline std::ostream& operator<<(std::ostream& os, const List<U>& list) {
    os << "List(s=" << list.count << ", c=" << list.capacity << ")=[";
    for (int i = 0; i < list.count; i++) {
        os << list.data[i] << ",";
    }
    os << "]";
    return os;
}

template<class T>
inline int List<T>::size() const {
    return count;
}

template<class T>
inline void List<T>::insert(int index, const T& value) {
    if (data == nullptr)
        data = new T[capacity];
    
    if (index < 0 || index > this->count)
        throw "Index out of range";

    if (this->count == this->capacity) {
        this->capacity *= 2;
        T* newData = new T[this->capacity];
        for (int i = 0; i < this->count; i++) {
            newData[i] = this->data[i];
        }
        delete[] this->data;
        this->data = newData;
    }
    for (int i = this->count; i > index; i--) {
        this->data[i] = this->data[i - 1];
    }
    this->data[index] = value;
    this->count++;
}

template<class T>
inline void List<T>::push_back(const T& value) {
    this->insert(this->count, value);
}

template<class T>
inline void List<T>::pop_back() {
    if (count > 0)
        count--;
}

template<class T>
inline void List<T>::push_front(const T& value) {
    this->insert(0, value);
}

template<class T>
inline void List<T>::pop_front() {
    if (count > 0)
        this->remove(0);
}

template<class T>
inline void List<T>::remove(int index) {
    if (index < 0 || index >= this->count) {
        throw "index gresit";
    }
    for (int i = index; i < this->count - 1; i++) {
        this->data[i] = this->data[i + 1];
    }
    this->count--;
}

template<class T>
inline void List<T>::clear() {
    if (this->data)
        delete[] this->data;
        
    this->capacity = 10;
    this->count = 0;
    this->data = nullptr;
}

template<class T>
inline bool List<T>::isEmpty() const {
    return this->count == 0;
}

template<class T>
inline bool List<T>::operator==(const List<T>& other) const {
    if (this->count != other.count)
        return false;
    if (this->capacity != other.capacity)
        return false;

    for (int i = 0; i < this->count; i++) {
        if (this->data[i] != other.data[i])
            return false;
    }
    return true;
}

#endif // LIST_H
