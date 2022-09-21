#ifndef MULTI_DICTIONAR_H
#define MULTI_DICTIONAR_H

#include <vector>

template<class T, class U>
class MultiDictionar {
private:
    struct NodLista {
        U elem;
        NodLista *next;
    };

    struct NodDict {
        T cheie;
        NodLista* elem;
        NodDict *next;
    };

    NodDict* cautare(T cheie) {
        NodDict* curent = head;
        while (curent != nullptr) {
            if (curent->cheie == cheie) {
                return curent;
            }
            curent = curent->next;
        }
        return nullptr;
    }
public:
    MultiDictionar() : head(nullptr) {}
    ~MultiDictionar() {
        NodDict *curr = head;
        while (curr != nullptr) {
            NodDict *next = curr->next;
            delete curr->elem;
            delete curr;
            curr = next;
        }
    }

    void adauga(T cheie, U elem) {
        NodDict *curent = cautare(cheie);
        if (curent == nullptr) {
            NodDict *newNode = new NodDict;
            newNode->cheie = cheie;
            newNode->elem = new NodLista;
            newNode->elem->elem = elem;
            newNode->elem->next = nullptr;
            newNode->next = head;
            head = newNode;
        } else {
            NodLista *newNode = new NodLista;
            newNode->elem = elem;
            newNode->next = curent->elem;
            curent->elem = newNode;
        }
    }

    std::vector<U> sterge(T cheie) {
        std::vector<U> elems;
        NodDict *curent = cautare(cheie);
        if (curent == nullptr) {
            return elems;
        } else {
            NodLista *prev = nullptr;
            NodLista *curr = curent->elem;
            while (curr != nullptr) {
                elems.push_back(curr->elem);
                prev = curr;
                curr = curr->next;
                delete prev;
            }
        }

        if (curent->next == nullptr) {
            delete curent;
            head = nullptr;
        }

        return elems;
    }

    void sterge(T cheie, U elem) {
        NodDict *curent = cautare(cheie);
        if (curent == nullptr) {
            return;
        } else {
            NodLista *curr = curent->elem;
            NodLista *prev = nullptr;
            while (curr != nullptr) {
                if (curr->elem == elem) {
                    if (prev == nullptr) {
                        curent->elem = curr->next;
                    } else {
                        prev->next = curr->next;
                    }
                    delete curr;
                    return;
                }
                prev = curr;
                curr = curr->next;
            }
        }
    }

    std::vector<U> get(T cheie) {
        NodDict *curent = cautare(cheie);
        if (curent == nullptr) {
            return std::vector<U>();
        } else {
            NodLista *curr = curent->elem;
            std::vector<U> rezultat;
            while (curr != nullptr) {
                rezultat.push_back(curr->elem);
                curr = curr->next;
            }

            return rezultat;
        }
    }

    bool exista(T cheie) {
        return cautare(cheie) != nullptr;
    }

    bool exista(T cheie, U elem) {
        NodDict *curent = cautare(cheie);
        if (curent == nullptr) {
            return false;
        } else {
            NodLista *curr = curent->elem;
            while (curr != nullptr) {
                if (curr->elem == elem) {
                    return true;
                }
                curr = curr->next;
            }
            return false;
        }
    }

private:
    NodDict *head;
};



#endif // MULTI_DICTIONAR_H
