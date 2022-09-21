//#define LIST_H
#ifndef LIST_H
#define LIST_H

template<class T>
class List {
    int size;
    T* data;
public:
    List() {
        size = 0;
        data = new T[size];
    }

    List(int size) {
        this->size = size;
        data = new T[size];
    }

    List(const List<T>& list) {
        size = list.size;
        data = new T[size];
        for (int i = 0; i < size; i++) {
            data[i] = list.data[i];
        }
    }   

    ~List() {
        delete[] data;
    }

    List<T>& operator=(const List<T>& list) {
        if (this != &list) {
            delete[] data;
            size = list.size;
            data = new T[size];
            for (int i = 0; i < size; i++) {
                data[i] = list.data[i];
            }
        }
        return *this;
    }

    void add(T element) {
        T* newData = new T[size + 1];
        for (int i = 0; i < size; i++) {
            newData[i] = data[i];
        }
        newData[size] = element;
        delete[] data;
        data = newData;
        size++;
    }

    void add(int index, T element) {
        if (index < 0 || index > size) {
            throw "Index invalid.";
        }
        T* newData = new T[size + 1];
        for (int i = 0; i < index; i++) {
            newData[i] = data[i];
        }
        newData[index] = element;
        for (int i = index; i < size; i++) {
            newData[i + 1] = data[i];
        }
        delete[] data;
        data = newData;
        size++;
    }

    void remove(int index) {
        if (index < 0 || index >= size) {
            throw "Index invalid.";
        }
        T* newData = new T[size - 1];
        for (int i = 0; i < index; i++) {
            newData[i] = data[i];
        }
        for (int i = index; i < size - 1; i++) {
            newData[i] = data[i + 1];
        }
        delete[] data;
        data = newData;
        size--;
    }

    T get(int index) {
        if (index < 0 || index >= size) {
            throw "Index invalid.";
        }
        return data[index];
    }

    void set(int index, T element) {
        if (index < 0 || index >= size) {
            throw "Index invalid.";
        }
        data[index] = element;
    }

    int getSize() {
        return size;
    }

    void clear() {
        delete[] data;
        size = 0;
    }
};


#endif

#define LIST2
#ifndef LIST2
#define LIST2

#include <vector>

template<class T>
class List
{
private:
    std::vector<T> data;

public:
    List() {
    }

    List(int capacity) {
        data.reserve(capacity);
    }

    List(const List& other) {
        data = other.data;
    }

    List& operator=(const List& other) {
        if (this != &other) {
            data = other.data;
        }
        return *this;
    }

    ~List() {
    }

    void add(T element) {
        data.push_back(element);
    }

    void add(int index, T element) {
        if (index < 0 || index > getSize()) {
            throw "Index invalid.";
        }
        data.insert(data.begin() + index, element);
    }

    void remove(int index) {
        if (index < 0 || index >= getSize()) {
            throw "Index invalid.";
        }
        data.erase(data.begin() + index);
    }

    T get(int index) {
        if (index < 0 || index >= getSize()) {
            throw "Index invalid.";
        }
        return data[index];
    }

    void set(int index, T element) {
        if (index < 0 || index >= getSize()) {
            throw "Index invalid.";
        }
        data[index] = element;
    }

    int getSize() {
        return data.size();
    }
};

#endif
