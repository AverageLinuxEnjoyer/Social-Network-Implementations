#ifndef TAD_MULTIMEORDONATA_H
#define TAD_MULTIMEORDONATA_H

#include <vector>

template<class T>
class MultimeOrdonata {
private:
    struct Node {
        T info;
        Node* left = nullptr;
        Node* right = nullptr;
    };

    Node* root;

    void destroy(Node* node) {
        if (node != nullptr) {
            destroy(node->left);
            destroy(node->right);
            delete node;
        }
    }

    void copy(Node*& dest, Node* src) {
        if (src != nullptr) {
            dest = new Node;
            dest->info = src->info;
            copy(dest->left, src->left);
            copy(dest->right, src->right);
        }
    }

    void add(Node*& node, T element) {
        if (node == nullptr) {
            node = new Node;
            node->info = element;
            node->left = nullptr;
            node->right = nullptr;
        } else if (element < node->info) {
            add(node->left, element);
        } else if (element > node->info) {
            add(node->right, element);
        }
    }

    void remove(Node*& node, T element) {
        if (node != nullptr) {
            if (element < node->info) {
                remove(node->left, element);
            } else if (element > node->info) {
                remove(node->right, element);
            } else {
                if (node->left == nullptr) {
                    Node* aux = node->right;
                    delete node;
                    node = aux;
                } else if (node->right == nullptr) {
                    Node* aux = node->left;
                    delete node;
                    node = aux;
                } else {
                    Node* aux = node->right;
                    while (aux->left != nullptr) {
                        aux = aux->left;
                    }
                    node->info = aux->info;
                    remove(node->right, aux->info);
                }
            }
        }
    }

    int size(Node* node) {
        if (node == nullptr) {
            return 0;
        } else {
            return 1 + size(node->left) + size(node->right);
        }
    }

    void to_vector(Node* node, std::vector<T>& v) {
        if (node != nullptr) {
            to_vector(node->left, v);
            v.push_back(node->info);
            to_vector(node->right, v);
        }
    }

public:
    MultimeOrdonata() {
        root = nullptr;
    }

    MultimeOrdonata(const MultimeOrdonata& other) {
        copy(root, other.root);
    }

    MultimeOrdonata& operator=(const MultimeOrdonata& other) {
        if (this != &other) {
            destroy(root);
            copy(root, other.root);
        }
        return *this;
    }

    ~MultimeOrdonata() {
        destroy(root);
    }

    void add(T element) {
        add(root, element);
    }

    void remove(T element) {
        remove(root, element);
    }

    bool contains(T element) {
        Node* node = root;
        while (node != nullptr) {
            if (element < node->info) {
                node = node->left;
            } else if (element > node->info) {
                node = node->right;
            } else {
                return true;
            }
        }
        return false;
    }

    int size() {
        return size(root);
    }

    std::vector<T> to_vector() {
        std::vector<T> v;
        to_vector(root, v);
        return v;
    }
};

#endif // TAD_MULTIMEORDONATA_H
