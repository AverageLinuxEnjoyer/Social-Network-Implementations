#ifndef Lista_H
#define Lista_H

#include <iostream>

template<class T>
class Lista {
public:
   /**
    * @brief  Constructor implicit
    * @note seteaza capacitatea la 10, lungimea la 0, si aloca dinamic un array de 10 elemente
    */
    Lista();

   /**
    * @brief  Constructor de copiere
    * @note copiaza capacitatea, lungimea si toate elementele unei alte liste
    * @param  other: o alta lista
    */
    Lista(const Lista& other);

   /**
    * @brief  Constructor de mutare
    * @note copiaza capacitatea si lungimea, iar elementele sunt mutate dintr-o alta lista in lista acesata (pentru a nu realoca memorie, daca nu e nevoie)
    * @param  other: O alta lista (a caror elemente vor fi mutate)
    */
    Lista(Lista&& other);

   /**
    * @brief Operator de atribuire (prin copiere)
    * @note copiaza capacitatea, lungimea si toate elementele unei alte liste
    * @param  other: o alta lista
    * @retval Lista aceasta (*this)
    */
    Lista<T>& operator=(const Lista& other);

   /**
    * @brief Operator de atribuire (prin mutare)
    * @note copiaza capacitatea si lungimea, iar elementele sunt mutate dintr-o alta lista in lista acesata (pentru a nu realoca memorie, daca nu e nevoie)
    * @param  other: o alta lista
    * @retval Lista aceasta (*this)
    */
    Lista<T>& operator=(Lista&& other);
    ~Lista();

   /**
    * @brief Operator de indexare
    * @note Supraincarca operatorul [] pentru a folosi lista ca un array normal 
    * @param  index: indexul elementului dorit
    * @retval elementul cautat
    */
    T& operator[](int index);

    /**
    * @brief Operator de indexare (pentru constante)
    * @note Supraincarca operatorul [] pentru a folosi lista ca un array normal 
    * @param  index: indexul elementului dorit
    * @retval elementul cautat
    */
    const T& operator[](int index) const;
    
   /**
    * @brief  Returneaza lungimea liste
    * @retval lungimea listei
    */
    int size() const;

   /**
    * @brief  Insereaza un obiect la un index dorit
    * @param  index: indexul
    * @param  value: obiectul introdus
    */
    void insert(int index, const T& value);

   /**
    * @brief  Sterge un obiect la un anumit inde
    * @param  index: indexul
    */
    void remove(int index);

   /**
    * @brief  Sterge toate elementele din lista
    */
    void clear();

   /**
    * @brief  Verifica daca lista e sau nu goala
    * @note   
    * @retval true daca e goala, false in caz contrar
    */
    bool isEmpty() const;

   /**
    * @brief  Verifica daca doua liste sunt egale
    * @param  other: O alta lista
    * @retval true daca au aceleasi elemente, false in caz contrar
    */
    bool operator==(const Lista<T>& other) const;

private:
    int capacity = 10;
    int count = 0;
    T* data = nullptr;

    friend void test_Lista();
};

template<class T>
inline Lista<T>::Lista() 
    : capacity(10), count(0), data(new T[capacity]) {};

template<class T>
inline Lista<T>::Lista(const Lista& other) 
    : count(other.count), capacity(other.capacity), data(new T[other.capacity]) {
    for (int i = 0; i < other.count; i++)
        this->data[i] = other.data[i];
}

template<class T>
inline Lista<T>::Lista(Lista&& other) 
    : data(other.data), count(other.count), capacity(other.capacity) {
    other.capacity = 10;
    other.count = 0;
    other.data = nullptr;
}

template<class T>
inline Lista<T>& Lista<T>::operator=(const Lista& other)  {
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
inline Lista<T>& Lista<T>::operator=(Lista&& other) {
    if (this != &other) {
        if (this->data)
            delete[] this->data;

        this->data = other.data;
        this->count = other.count;
        this->capacity = other.capacity;

        other.capacity = 10;
        other.count = 0;
        other.data = nullptr;
    }
    return *this;
}

template<class T>
inline Lista<T>::~Lista() {
    this->clear();
}

template<class T>
inline T& Lista<T>::operator[](int index) {
    return this->data[index];
}

template<class T>
inline const T& Lista<T>::operator[](int index) const {
    return this->data[index];
}

template<class T>
inline int Lista<T>::size() const {
    return count;
}

template<class T>
inline void Lista<T>::insert(int index, const T& value) {
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
inline void Lista<T>::remove(int index) {
    if (index < 0 || index >= this->count) {
        throw "index gresit";
    }
    for (int i = index; i < this->count - 1; i++) {
        this->data[i] = this->data[i + 1];
    }
    this->count--;
}

template<class T>
inline void Lista<T>::clear() {
    if (this->data)
        delete[] this->data;
        
    this->capacity = 10;
    this->count = 0;
    this->data = nullptr;
}

template<class T>
inline bool Lista<T>::isEmpty() const {
    return this->count == 0;
}

template<class T>
inline bool Lista<T>::operator==(const Lista<T>& other) const {
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

#endif // Lista_H
