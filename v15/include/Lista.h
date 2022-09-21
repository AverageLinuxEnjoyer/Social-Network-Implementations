#define TESTUTZ
#ifndef TESTUTZ
#define TESTUTZ
#include <vector>

template<class T>
class Lista {
public:
    Lista() = default;
    Lista(const Lista<T>& lista) = default;
    ~Lista() = default;
    Lista<T>& operator=(const Lista<T>& lista) = default;

    bool operator==(const Lista<T>& lista) const {
        return elems == lista.elems;
    }

    int size() const { 
        return elems.size();
    }

    T& operator[](int index) {
        return elems[index];
    }
    const T& operator[](int index) const {
        return elems[index];
    }

    void insert(int index, const T& value) {
        elems.insert(elems.begin() + index, value);
    }
    void push_back(const T& value) {
        elems.push_back(value);
    }
    void push_front(const T& value) {
        elems.insert(elems.begin(), value);
    }

    void erase(int index) {
        elems.erase(elems.begin() + index);
    }
    void pop_back() {
        elems.pop_back();
    }
    void pop_front() {
        elems.erase(elems.begin());
    }
    
    void clear() {
        elems.clear();
    }
    bool isEmpty() const {
        return elems.empty();
    };

private:
    std::vector<T> elems;
};
#endif

//#define LISTA_H
#ifndef LISTA_H
#define LISTA_H

#include <iostream>
#include <vector>

template<class T>
class Lista {
public:
    Lista();
    Lista(const Lista& other);
    Lista(Lista&& other);
    Lista<T>& operator=(const Lista& other);
    Lista<T>& operator=(Lista&& other);
    ~Lista();

    bool operator==(const Lista<T>& other) const;

    int size() const;
    T& operator[](int index);
    const T& operator[](int index) const;

    void insert(int index, const T& value);
    void push_back(const T& value);
    void push_front(const T& value);

    void erase(int index);
    void pop_back();
    void pop_front();
    
    void clear();
    bool isEmpty() const;

private:
    struct Node {
        T value;
        Node *next;
    };

    Node *head;
    int count;

    friend void test_linked_list();
};

template<class T>
inline Lista<T>::Lista()
    : head(nullptr),
      count(0)
{
    
}

template<class T>
inline Lista<T>::Lista(const Lista& other)
    : head(nullptr),
      count(0)
{
    Node *current = other.head;
    while (current != nullptr) {
        push_back(current->value);
        current = current->next;
    }

    count = other.count;
}

template<class T>
inline Lista<T>::Lista(Lista&& other)
    : head(other.head),
      count(other.count)
{
    other.head = nullptr;
    other.count = 0;
}

template<class T>
inline Lista<T>& Lista<T>::operator=(const Lista& other) {
    if (this != &other) {
        Node* current = other.head;
        while (current != nullptr) {
            push_back(current->value);
            current = current->next;
        }

        count = other.count;
    }

    return *this;
}

template<class T>
inline Lista<T>& Lista<T>::operator=(Lista&& other) {
    if (this != &other) {
        head = other.head;
        count = other.count;

        other.head = nullptr;
        other.count = 0;
    }

    return *this;
}

template<class T>
inline Lista<T>::~Lista()
{
    clear();
}

template<class T>
inline bool Lista<T>::operator==(const Lista<T>& other) const {
    if (count != other.count) {
        return false;
    }

    Node *current = head;
    Node *otherCurrent = other.head;
    while (current != nullptr) {
        if (current->value != otherCurrent->value) {
            return false;
        }

        current = current->next;
        otherCurrent = otherCurrent->next;

        if (current != otherCurrent) {
            return false;
        }
    }

    return true;
}

template<class T>
inline int Lista<T>::size() const {
    return count;
}

template<class T>
inline T& Lista<T>::operator[](int index) {
    Node *current = head;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }

    return current->value;
}

template<class T>
inline const T& Lista<T>::operator[](int index) const {
    Node *current = head;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }

    return current->value;
}

template<class T>
inline void Lista<T>::insert(int index, const T& value) {
    if (index < 0 || index > count) {
        throw "Index out of range";
    }

    Node *newNode = new Node;
    newNode->value = value;
    newNode->next = nullptr;

    if (index == 0) {
        newNode->next = head;
        head = newNode;
    } else {
        Node *current = head;
        for (int i = 0; i < index - 1; i++) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }

    count++;
}

template<class T>
inline void Lista<T>::push_back(const T& value) {
    insert(count, value);
}

template<class T>
inline void Lista<T>::push_front(const T& value) {
    insert(0, value);
}

template<class T>
inline void Lista<T>::erase(int index) {
    if (index < 0 || index > count) {
        throw "Index out of range";
    }

    if (index == 0) {
        Node *current = head;
        head = head->next;
        delete current;
    } else {
        Node *current = head;
        for (int i = 0; i < index - 1; i++) {
            current = current->next;
        }
        Node *next = current->next->next;
        delete current->next;
        current->next = next;
    }

    count--;

    if (count == 0) {
        head = nullptr;
    }

    if (count == 1) {
        head->next = nullptr;
    }

}

template<class T>
inline void Lista<T>::pop_back() {
    erase(count - 1);
}

template<class T>
inline void Lista<T>::pop_front() {
    erase(0);
}

template<class T>
inline void Lista<T>::clear() {
    while (head != nullptr) {
        Node *current = head;
        head = head->next;
        delete current;

        count--;
    }
}

template<class T>
inline bool Lista<T>::isEmpty() const {
    return count == 0;
}


#endif // LISTA_H
