#ifndef LISTA_H
#define LISTA_H

template<class T>
class List {
public:
    int size_;
    int capacity_;
    T *data_;

public:
    List();
    ~List();
    void append(T);
    void insert(T, int);
    void remove(int);
    void remove(T);
    void removeAll();
    bool isEmpty();
    int size();
    T& get(int);
    int indexOf(T);
};

template<class T>
List<T>::List() {
    size_ = 0;
    capacity_ = 0;
    data_ = new T[0];
}

template<class T>
List<T>::~List() {
    delete[] data_;
}

template<class T>
void List<T>::append(T value) {
    if (size_ == capacity_) {
        T *data = new T[capacity_ * 2];
        for (int i = 0; i < capacity_; i++) {
            data[i] = data_[i];
        }
        delete[] data_;
        data_ = data;
        capacity_ *= 2;
    }
    data_[size_] = value;
    size_++;
}

template<class T>
void List<T>::insert(T value, int index) {
    if (index < 0 || index > size_) {
        return;
    }
    if (size_ == capacity_) {
        T *data = new T[capacity_ * 2];
        for (int i = 0; i < capacity_; i++) {
            data[i] = data_[i];
        }
        delete[] data_;
        data_ = data;
        capacity_ *= 2;
    }
    for (int i = size_; i > index; i--) {
        data_[i] = data_[i - 1];
    }
    data_[index] = value;
    size_++;
}

template<class T>
void List<T>::remove(int index) {
    if (index < 0 || index >= size_) {
        return;
    }
    for (int i = index; i < size_ - 1; i++) {
        data_[i] = data_[i + 1];
    }
};

template<class T>
inline void List<T>::remove(T value) {
    remove(indexOf(value));
}

template<class T>
inline void List<T>::removeAll() {
    size_ = 0;
}

template<class T>
inline bool List<T>::isEmpty() {
    return size_ == 0;
}

template<class T>
inline int List<T>::size() {
    return size_;
}

template<class T>
inline T& List<T>::get(int index) {
    return data_[index];
}

template<class T>
inline int List<T>::indexOf(T value) {
    for (int i = 0; i < size_; i++) {
        if (data_[i] == value) {
            return i;
        }
    }
    return -1;
}

#endif //LISTA_H