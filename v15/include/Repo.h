#ifndef REPO_H
#define REPO_H

#include "Lista.h"
#include <iostream>

template<class T>
class Repo {
public:
    Repo() = default;
    Repo(const Repo<T>& repo) = default;
    virtual ~Repo() = default;

    void addElem(const T& elem);
    void delElem(const T& elem);
    void updateElem(const T& elem, const T& newElem);
    T& getElem(int pos);
    int getSize() const;
    Lista<T>& getAll();

protected:
    Lista<T> elems;
};

template<class T>
inline void Repo<T>::addElem(const T& elem) {
    elems.push_back(elem);
}

template<class T>
inline void Repo<T>::delElem(const T& elem) {
    for (int i = 0; i < elems.size(); i++) {
        if (elems[i] == elem) {
            elems.erase(i);
            break;
        }
    }
}

template<class T>
inline void Repo<T>::updateElem(const T& elem, const T& newElem) {
    for (int i = 0; i < elems.size(); i++) {
        if (elems[i] == elem) {
            elems[i] = newElem;
            break;
        }
    }
}

template<class T>
inline T& Repo<T>::getElem(int pos) {
    return elems[pos];
}

template<class T>
inline int Repo<T>::getSize() const {
    return elems.size();
}

template<class T>
inline Lista<T>& Repo<T>::getAll(){
    return elems;
}

#endif // REPO_H
