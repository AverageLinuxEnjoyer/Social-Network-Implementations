#ifndef MULTIME_ORDONATA_H
#define MULTIME_ORDONATA_H

#include "list.h"

template<class T>
class MultimeOrdonata {
private:
    struct Node {
        T value;
        Node *left;
        Node *right;
    };

    Node *root;

    void add(Node *&node, T value) {
        if (node == nullptr) {
            node = new Node;
            node->value = value;
            node->left = nullptr;
            node->right = nullptr;
        } else if (value < node->value) {
            add(node->left, value);
        } else if (value > node->value) {
            add(node->right, value);
        }
    }

    void remove(Node *&node, T value) {
        if (node == nullptr) {
            return;
        } else if (value < node->value) {
            remove(node->left, value);
        } else if (value > node->value) {
            remove(node->right, value);
        } else {
            if (node->left == nullptr && node->right == nullptr) {
                delete node;
                node = nullptr;
            } else if (node->left == nullptr) {
                Node *temp = node;
                node = node->right;
                delete temp;
            } else if (node->right == nullptr) {
                Node *temp = node;
                node = node->left;
                delete temp;
            } else {
                Node *temp = node->right;
                while (temp->left != nullptr) {
                    temp = temp->left;
                }
                node->value = temp->value;
                remove(node->right, temp->value);
            }
        }
    }

    void clear(Node *&node) {
        if (node == nullptr) {
            return;
        }
        clear(node->left);
        clear(node->right);
        delete node;
        node = nullptr;
    }

    void toList(Node *node, List<T> &list) const {
        if (node == nullptr) {
            return;
        }
        toList(node->left, list);
        list.add(node->value);
        toList(node->right, list);
    }

    bool contains(Node *node, T value) {
        if (node == nullptr) {
            return false;
        } else if (value < node->value) {
            return contains(node->left, value);
        } else if (value > node->value) {
            return contains(node->right, value);
        } else {
            return true;
        }
    }

    int size(Node *node) {
        if (node == nullptr) {
            return 0;
        }
        return size(node->left) + size(node->right) + 1;
    }

public:
    MultimeOrdonata() {
        root = nullptr;
    }

    ~MultimeOrdonata() {
        clear(root);
    }

    void add(T value) {
        add(root, value);
    }

    void remove(T value) {
        remove(root, value);
    }

    bool contains(T value) {
        return contains(root, value);
    }

    int size() {
        return size(root);
    }

    void clear() {
        clear(root);
    }

    List<T> toList() const {
        List<T> list;
        toList(root, list);
        return list;
    }
};

#endif // MULTIME_ORDONATA_H
