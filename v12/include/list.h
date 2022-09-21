#ifndef LIST_H
#define LIST_H

template<class T>
class List {
private:
    T* data;
    int size;
    int capacity;

    void resize(int new_capacity) {
        T* new_data = new T[new_capacity];
        for (int i = 0; i < size; i++) {
            new_data[i] = data[i];
        }
        delete[] data;
        data = new_data;
        capacity = new_capacity;
    }

public:
    List() : data(new T[5]), size(0), capacity(5) {}
    List(int capacity) : data(new T[capacity]), size(0), capacity(capacity) {}
    List(const List& other) : data(new T[other.capacity]), size(other.size), capacity(other.capacity) {
        for (int i = 0; i < size; i++) {
            data[i] = other.data[i];
        }
    }

    ~List() {
        delete[] data;
    }

    int getSize() const {
        return size;
    }

    void erase(int index) {
        if (index < 0 || index >= size) {
            throw "Index out of range";
        }
        for (int i = index; i < size - 1; i++) {
            data[i] = data[i + 1];
        }
        size--;
    }

    void insert(int index, T value) {
        if (index < 0 || index > size) {
            throw "Index out of range";
        }
        if (size == capacity) {
            resize(capacity * 2);
        }
        for (int i = size; i > index; i--) {
            data[i] = data[i - 1];
        }
        data[index] = value;
        size++;
    }

    void push_back(T elem) {
        if (size == capacity) {
            resize(capacity * 2);
        }
        data[size++] = elem;
    }

    void pop_back() {
        if (size > 0) {
            size--;
        }
    }

    T& operator[](int index) {
        return data[index];
    }

    const T& operator[](int index) const {
        return data[index];
    }

    List& operator=(const List& other) {
        if (this != &other) {
            delete[] data;
            data = new T[other.capacity];
            size = other.size;
            capacity = other.capacity;
            for (int i = 0; i < size; i++) {
                data[i] = other.data[i];
            }
        }
        return *this;
    }
};

#endif // LIST_H
