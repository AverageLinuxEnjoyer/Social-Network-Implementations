#ifndef LIST_H
#define LIST_H

template<class T>
class List {
    int size_;
    T* data;
public:
    List() {
        size_ = 0;
        data = new T[size_];
    }

    List(int size) {
        this->size_ = size;
        data = new T[size];
    }

    List(const List<T>& list) {
        size_ = list.size_;
        data = new T[size_];
        for (int i = 0; i < size_; i++) {
            data[i] = list.data[i];
        }
    }   

    ~List() {
        delete[] data;
    }

    List<T>& operator=(const List<T>& list) {
        if (this != &list) {
            delete[] data;
            size_ = list.size;
            data = new T[size_];
            for (int i = 0; i < size_; i++) {
                data[i] = list.data[i];
            }
        }
        return *this;
    }

    void add(T element) {
        T* newData = new T[size_ + 1];
        for (int i = 0; i < size_; i++) {
            newData[i] = data[i];
        }
        newData[size_] = element;
        delete[] data;
        data = newData;
        size_++;
    }

    void add(int index, T element) {
        if (index < 0 || index > size_) {
            throw "Index invalid.";
        }
        T* newData = new T[size_ + 1];
        for (int i = 0; i < index; i++) {
            newData[i] = data[i];
        }
        newData[index] = element;
        for (int i = index; i < size_; i++) {
            newData[i + 1] = data[i];
        }
        delete[] data;
        data = newData;
        size_++;
    }

    void remove(int index) {
        if (index < 0 || index >= size_) {
            throw "Index invalid.";
        }
        T* newData = new T[size_ - 1];
        for (int i = 0; i < index; i++) {
            newData[i] = data[i];
        }
        for (int i = index; i < size_ - 1; i++) {
            newData[i] = data[i + 1];
        }
        delete[] data;
        data = newData;
        size_--;
    }

    T& get(int index) {
        if (index < 0 || index >= size_) {
            throw "Index invalid.";
        }
        return data[index];
    }

    void set(int index, T element) {
        if (index < 0 || index >= size_) {
            throw "Index invalid.";
        }
        data[index] = element;
    }

    int size() {
        return size_;
    }

    void clear() {
        delete[] data;
        size_ = 0;
    }
};


#endif
