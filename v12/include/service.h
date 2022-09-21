#ifndef SERVICE_H
#define SERVICE_H

#include "ordered_set.h"
#include "list.h"
#include "user.h"
#include "event.h"

template<class T>
class Service {
public:
    Service() = default;
    Service(const Service& other) = default;
    ~Service() = default;

    void add(T elem);
    void update(int code, T elem);
    void remove(int code);
    T get(int code);
    List<T> getAll();
    
protected:
    OrderedSet<T> ordered_set;
};

template<class T>
inline void Service<T>::add(T elem) {
    ordered_set.Insert(elem);
}

template<class T>
inline void Service<T>::update(int code, T elem) {
    this->remove(code);
    this->add(elem);
}

template<class T>
inline void Service<T>::remove(int code) {
    T elem = ordered_set.FindMin();

    while(elem != T())
    {
        if(elem.getCode() == code)
        {
            ordered_set.Remove(elem);
            return;
        }
        elem = ordered_set.Successor(elem);
    }

    throw std::runtime_error("Element not found");
}

template<class T>
inline T Service<T>::get(int code) {
    T elem = ordered_set.FindMin();

    while(elem != T())
    {
        if(elem.getCode() == code)
        {
            return elem;
        }
        elem = ordered_set.Successor(elem);
    }

    throw std::runtime_error("Element not found");
}

template<class T>
inline List<T> Service<T>::getAll() {
    List<T> elems;

    T elem = ordered_set.FindMin();

    while(elem != T())
    {
        elems.push_back(elem);
        elem = ordered_set.Successor(elem);
    }

    return elems;
}



#endif // SERVICE_H
