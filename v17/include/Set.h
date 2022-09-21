#ifndef SET_H
#define SET_H

#include <iostream>
#include <vector>

template<class T>
class Set {
private:
    struct Node {
        T value;
        Node *next;
    };
    
    Node* head;
    int count;

public:
    Set();
    ~Set();

    std::vector<T*> getAll();
    void add(T value);
    void remove(T value);
    bool contains(T value);
    int size();

    void print();


};

template<class T>
inline Set<T>::Set()
    : head(nullptr),
      count(0)
{}

template<class T>
inline Set<T>::~Set() {
    Node *current = head;
    while (current != nullptr) {
        Node *next = current->next;
        delete current;
        current = next;
    }
}

template<class T>
inline std::vector<T*> Set<T>::getAll() {
    std::vector<T*> result;
    Node *current = head;
    while (current != nullptr) {
        result.push_back(&current->value);
        current = current->next;
    }
    return result;
}

template<class T>
inline void Set<T>::add(T value) {
    if (contains(value)) {
        return;
    }

    Node *n = new Node{value, head};
    head = n;

    count++;
}

template<class T>
inline void Set<T>::remove(T value) {
    Node *current = head;
    Node *prev = nullptr;
    while (current != nullptr) {
        if (current->value == value) {
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

template<class T>
inline bool Set<T>::contains(T value) {
    Node *current = head;
    while (current != nullptr) {
        if (current->value == value) {
            return true;
        }
        current = current->next;
    }
    return false;
}

template<class T>
inline int Set<T>::size() {
    return count;
}

template<class T>
inline void Set<T>::print() {
    Node *current = head;
    while (current != nullptr) {
        std::cout << current->value << " ";
        current = current->next;
    }
}

#endif // SET_H
