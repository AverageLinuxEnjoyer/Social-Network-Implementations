#ifndef SERVICE_H
#define SERVICE_H

#include "MultimeOrdonata.h"
#include "Lista.h"
#include "Utilizator.h"
#include "event.h"

template<class T>
class Service {
protected:
    MutlimeOrdonata<T> multime_ordonata;
    
public:
    Service() = default;
    Service(const Service& other) = default;
    ~Service() = default;

    void adaugare(T elem);
    void modificare(int id, T elem);
    void stergere(int id);
    T get(int id);
    Lista<T> getAll();
};

template<class T>
inline void Service<T>::adaugare(T elem) {
    multime_ordonata.inserare(elem);
}

template<class T>
inline void Service<T>::modificare(int id, T elem) {
    this->stergere(id);
    this->adaugare(elem);
}

template<class T>
inline void Service<T>::stergere(int id) {
    T elem = multime_ordonata.min();

    while(elem != T())
    {
        if(elem.getId() == id)
        {
            multime_ordonata.stergere(elem);
            return;
        }
        elem = multime_ordonata.urmatorul(elem);
    }

    throw std::runtime_error("Element not found");
}

template<class T>
inline T Service<T>::get(int id) {
    T elem = multime_ordonata.min();

    while(elem != T())
    {
        if(elem.getId() == id)
        {
            return elem;
        }
        elem = multime_ordonata.urmatorul(elem);
    }

    throw std::runtime_error("Element not found");
}

template<class T>
inline Lista<T> Service<T>::getAll() {
    Lista<T> elems;

    T elem = multime_ordonata.min();

    while(elem != T())
    {
        elems.inserare_sfarsit(elem);
        elem = multime_ordonata.urmatorul(elem);
    }

    return elems;
}



#endif // SERVICE_H
