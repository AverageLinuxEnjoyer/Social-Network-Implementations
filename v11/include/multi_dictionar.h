#ifndef MULTI_DICTIONAR_H
#define MULTI_DICTIONAR_H

#include <vector>

template<class T, class U>
class MultiDict {
private:
    struct NodLista {
        U data;
        NodLista *urmatorul;
    };

    struct NodDict {
        T cheie;
        NodLista* data;
        NodDict *urmatorul;
    };

    NodDict* cautare(T cheie) {
        NodDict* curent = head;
        while (curent != nullptr) {
            if (curent->cheie == cheie) {
                return curent;
            }
            curent = curent->urmatorul;
        }
        return nullptr;
    }
public:
    MultiDict() : head(nullptr) {}
    ~MultiDict() {
        NodDict *curr = head;
        while (curr != nullptr) {
            NodDict *urmatorul = curr->urmatorul;
            delete curr->data;
            delete curr;
            curr = urmatorul;
        }
    }

    void adauga(T cheie, U data) {
        NodDict *curent = cautare(cheie);
        if (curent == nullptr) {
            NodDict *newNode = new NodDict;
            newNode->cheie = cheie;
            newNode->data = new NodLista;
            newNode->data->data = data;
            newNode->data->urmatorul = nullptr;
            newNode->urmatorul = head;
            head = newNode;
        } else {
            NodLista *newNode = new NodLista;
            newNode->data = data;
            newNode->urmatorul = curent->data;
            curent->data = newNode;
        }
    }

    std::vector<U> sterge(T cheie) {
        std::vector<U> datas;
        NodDict *curent = cautare(cheie);
        if (curent == nullptr) {
            return datas;
        } else {
            NodLista *prev = nullptr;
            NodLista *curr = curent->data;
            while (curr != nullptr) {
                datas.push_back(curr->data);
                prev = curr;
                curr = curr->urmatorul;
                delete prev;
            }
        }

        if (curent->urmatorul == nullptr) {
            delete curent;
            head = nullptr;
        }

        return datas;
    }

    void sterge(T cheie, U data) {
        NodDict *curent = cautare(cheie);
        if (curent == nullptr) {
            return;
        } else {
            NodLista *curr = curent->data;
            NodLista *prev = nullptr;
            while (curr != nullptr) {
                if (curr->data == data) {
                    if (prev == nullptr) {
                        curent->data = curr->urmatorul;
                    } else {
                        prev->urmatorul = curr->urmatorul;
                    }
                    delete curr;
                    return;
                }
                prev = curr;
                curr = curr->urmatorul;
            }
        }
    }

    std::vector<U> get(T cheie) {
        NodDict *curent = cautare(cheie);
        if (curent == nullptr) {
            return std::vector<U>();
        } else {
            NodLista *curr = curent->data;
            std::vector<U> rezultat;
            while (curr != nullptr) {
                rezultat.push_back(curr->data);
                curr = curr->urmatorul;
            }

            return rezultat;
        }
    }

    bool exista(T cheie) {
        return cautare(cheie) != nullptr;
    }

    bool exista(T cheie, U data) {
        NodDict *curent = cautare(cheie);
        if (curent == nullptr) {
            return false;
        } else {
            NodLista *curr = curent->data;
            while (curr != nullptr) {
                if (curr->data == data) {
                    return true;
                }
                curr = curr->urmatorul;
            }
            return false;
        }
    }

private:
    NodDict *head;
};



#endif // MULTI_DICTIONAR_H
