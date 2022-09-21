#ifndef MULTIME_H
#define MULTIME_H

#include <vector>

template<class T>
class Multime {
private:
    struct Node {
        T info;
        Node *next;
    };

    Node *head;

public:
    Multime() {
        head = nullptr;
    }

    ~Multime() {
        Node *p = head;
        while (p != nullptr) {
            Node *aux = p;
            p = p->next;
            delete aux;
        }
    }

    void add(T x) {
        Node *p = head;
        Node *prev = nullptr;
        while (p != nullptr && p->info < x) {
            prev = p;
            p = p->next;
        }
        if (p == nullptr || p->info != x) {
            Node *aux = new Node;
            aux->info = x;
            aux->next = p;
            if (prev == nullptr)
                head = aux;
            else
                prev->next = aux;
        }
    }

    void update(T x, T y) {
        Node *p = head;
        while (p != nullptr && p->info != x)
            p = p->next;
        if (p != nullptr)
            p->info = y;
    }

    void remove(T x) {
        Node *p = head;
        Node *prev = nullptr;
        while (p != nullptr && p->info < x) {
            prev = p;
            p = p->next;
        }
        if (p != nullptr && p->info == x) {
            if (prev == nullptr)
                head = p->next;
            else
                prev->next = p->next;
            delete p;
        }
    }

    bool search(T x) {
        Node *p = head;
        while (p != nullptr && p->info < x)
            p = p->next;
        return (p != nullptr && p->info == x);
    }     

    std::vector<T> toVector() {
        std::vector<T> v;
        Node *p = head;
        while (p != nullptr) {
            v.push_back(p->info);
            p = p->next;
        }
        return v;
    }
};

#endif // MULTIME_H
