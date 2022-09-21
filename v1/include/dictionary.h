#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <iostream>

template<class T, class U>
class Dictionary {
    struct Node {
        T key;
        U value;
        Node *next;
    };
public:
    class Iterator {
    public:
        // construieste un iterator pe o pozitie anume
        Iterator(Node *node);

        // operatori de diferentiere/acces
        // pentru a folosi iteratorul ca si un pointer
        U& operator*();
        U* operator->();

        // operatori de incrementare
        // pentru a putea avansa iteratorul la urmatorul element al dictionarului
        Iterator& operator++();
        Iterator operator++(int);

        // operatori de comparare
        bool operator==(const Iterator& other) const;
        bool operator!=(const Iterator& other) const;
    private:
        Node *current;
    };

    // constructor
    Dictionary();

    // destructor
    ~Dictionary();

    // adauga o pereche (cheie, valoare) in dictionar
    void add(T key, U value);

    // sterge perechea cu cheia specificata din dictionar
    void remove(T key);

    // verifica daca dictionarul contine cheia specificata
    bool contains(T key);

    // schimba cheia unei perechi
    bool changeKey(T oldKey, T newKey);

    // returneaza valoarea care se afla la o anumita cheie
    U get(T key);
    
    // operator de acces
    // pentru a putea accesa un element din dictionar dupa cheie
    U& operator[](T key);

    // returneaza un iterator catre primul element din dictionar
    Iterator begin();

    // returneaza un iterator catre locul de dupa ultimul element din dictionar
    Iterator end();

    // returneaza numarul de perechi din dictionar
    int size();

    // printeaza dictionarul
    void print();

private:
    Node *head;
    int count;
};

template<class T, class U>
inline Dictionary<T, U>::Dictionary()
    : head(nullptr),
      count(0)
{}

template<class T, class U>
inline Dictionary<T, U>::~Dictionary()
{
    Node *current = head;
    while (current != nullptr) {
        Node *next = current->next;
        delete current;
        current = next;
    }
}

template<class T, class U>
inline void Dictionary<T, U>::add(T key, U value) {
    if (contains(key)) {
        Node *current = head;
        while (current != nullptr) {
            if (current->key == key) {
                current->value = value;
                return;
            }
            current = current->next;
        }
    }
    
    Node *n = new Node{key, value, head};
    head = n;

    count++;
}

template<class T, class U>
inline void Dictionary<T, U>::remove(T key) {
    Node *current = head;
    Node *prev = nullptr;
    while (current != nullptr) {
        if (current->key == key) {
            if (prev == nullptr) {
                head = current->next;
            } else {
                prev->next = current->next;
            }
            delete current;
            count--;
            return;
        }
        prev = current;
        current = current->next;
    }
}

template<class T, class U>
inline bool Dictionary<T, U>::contains(T key) {
    Node *current = head;
    while (current != nullptr) {
        if (current->key == key) {
            return true;
        }
        current = current->next;
    }
    return false;
}

template<class T, class U>
inline bool Dictionary<T, U>::changeKey(T oldKey, T newKey) {
    if (!contains(oldKey)) {
        return false;
    }
    if (contains(newKey)) {
        return false;
    }

    Node *current = head;
    while (current != nullptr) {
        if (current->key == oldKey) {
            current->key = newKey;
            return true;
        }
        current = current->next;
    }

    return false;
}

template<class T, class U>
inline U Dictionary<T, U>::get(T key) {
    Node *current = head;
    while (current != nullptr) {
        if (current->key == key) {
            return current->value;
        }
        current = current->next;
    }
    return U();
}

template<class T, class U>
inline U& Dictionary<T, U>::operator[](T key) {
    Node *current = head;
    while (current != nullptr) {
        if (current->key == key) {
            return current->value;
        }
        current = current->next;
    }

    if  (!current)
    {
        add(key, U());
        return head->value;
    }

    return current->value;
}

template<class T, class U>
inline typename Dictionary<T, U>::Iterator Dictionary<T, U>::begin() {
    return Iterator(head);
}

template<class T, class U>
inline typename Dictionary<T, U>::Iterator Dictionary<T, U>::end() {
    return Iterator(nullptr);
}

template<class T, class U>
inline int Dictionary<T, U>::size() {
    return count;
}

template<class T, class U>
inline void Dictionary<T, U>::print() {
    Node *current = head;
    while (current != nullptr) {
        std::cout << "{" << current->key << ": " << current->value << ", " << "}";
        current = current->next;
    }
}

template<class T, class U>
inline Dictionary<T, U>::Iterator::Iterator(Node *node)
    : current(node)
{}

template<class T, class U>
inline U& Dictionary<T, U>::Iterator::operator*() {
    return current->value;
}

template<class T, class U>
inline U* Dictionary<T, U>::Iterator::operator->() {
    return &current->value;
}

template<class T, class U>
inline typename Dictionary<T, U>::Iterator& Dictionary<T, U>::Iterator::operator++() {
    current = current->next;
    return *this;
}

template<class T, class U>
inline typename  Dictionary<T, U>::Iterator Dictionary<T, U>::Iterator::operator++(int) {
    Iterator tmp(*this);
    current = current->next;
    return tmp;
}

template<class T, class U>
inline bool Dictionary<T, U>::Iterator::operator==(const Iterator& other) const {
    return current == other.current;
}

template<class T, class U>
inline bool Dictionary<T, U>::Iterator::operator!=(const Iterator& other) const {
    return current != other.current;
}





#endif // DICTIONARY_H
