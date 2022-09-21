#pragma once

template<typename T>
class Set {
private:
    struct Node {
        T info;
        Node *next = nullptr;
    };

    Node *head;

public:
    Set() {
        head = nullptr;
    }

    ~Set() {
        Node *p = head;
        while (p != nullptr) {
            Node *tmp = p;
            p = p->next;
            delete tmp;
        }
    }

    void add(T info) {
        // don't add duplicates
        if (contains(info))
            return;

        Node *p = new Node{};
        p->info = info;
        p->next = head;
        head = p;
    }

    void remove(T info) {
        Node *p = head;
        Node *prev = nullptr;
        while (p != nullptr && p->info < info) {
            prev = p;
            p = p->next;
        }
        if (p != nullptr && p->info == info) {
            if (prev == nullptr) {
                head = p->next;
            } else {
                prev->next = p->next;
            }
            delete p;
        }
    }

    bool contains(T info) {
        Node *p = head;
        while (p != nullptr && p->info < info) {
            p = p->next;
        }
        return p != nullptr && p->info == info;
    }

    T& getAt(int index) {
        Node *p = head;
        for (int i = 0; i < index; i++) {
            p = p->next;
        }
        return p->info;
    }

    int size() {
        int size = 0;
        Node *p = head;
        while (p != nullptr) {
            size++;
            p = p->next;
        }
        return size;
    }
};