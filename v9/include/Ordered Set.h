#ifndef ORDERED_SET_H
#define ORDERED_SET_H

#include <iostream>
#include <vector>
using namespace std;

template<class T>
class OrderedSet {
private:
    struct Node {
        Node* left;
        Node* right;
        T data;
    };

    Node* root;

    void insert(Node*& node, T data) {
        if (node == nullptr) {
            node = new Node();
            node->data = data;
            node->left = nullptr;
            node->right = nullptr;
        } else if (data < node->data) {
            insert(node->left, data);
        } else if (data > node->data) {
            insert(node->right, data);
        }
    }

    void destroy(Node* node) {
        if (node == nullptr) {
            return;
        }

        destroy(node->left);
        destroy(node->right);
        delete node;
    }

    Node* find(Node* node, T data) {
        if (node == nullptr) {
            return nullptr;
        }

        if (data < node->data) {
            return find(node->left, data);
        } else if (data > node->data) {
            return find(node->right, data);
        } else {
            return node;
        }
    }

    Node* findMin(Node* node) {
        if (node == nullptr) {
            return nullptr;
        }

        if (node->left == nullptr) {
            return node;
        }

        return findMin(node->left);
    }

    Node* findMax(Node* node) {
        if (node == nullptr) {
            return nullptr;
        }

        if (node->right == nullptr) {
            return node;
        }

        return findMax(node->right);
    }

    Node* remove(Node*& node, T data) {
        if (node == nullptr) {
            return nullptr;
        }

        if (data < node->data) {
            node->left = remove(node->left, data);
        } else if (data > node->data) {
            node->right = remove(node->right, data);
        } else {
            if (node->left == nullptr) {
                Node* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == nullptr) {
                Node* temp = node->left;
                delete node;
                return temp;
            }

            Node* temp = findMin(node->right);
            node->data = temp->data;
            node->right = remove(node->right, temp->data);
        }

        return node;
    }

    void inorder_print(Node* node) {
        if (node == nullptr) {
            return;
        }

        inorder_print(node->left);
        cout << node->data << endl;
        inorder_print(node->right);
    }

    void to_vector(Node* node, vector<T> &vec) {
        if (node == nullptr) {
            return;
        }

        to_vector(node->left, vec);
        vec.push_back(node->data);
        to_vector(node->right, vec);
    }
public:
    OrderedSet() {
        root = nullptr;
    }

    ~OrderedSet() {
        destroy(root);
    }

    void insert(T data) {
        insert(root, data);
    }

    bool find(T data) {
        return find(root, data) != nullptr;
    }

    T findMin() {
        Node* node = findMin(root);
        if (node == nullptr) {
            return T();
        }

        return node->data;
    }

    T findMax() {
        Node* node = findMax(root);
        if (node == nullptr) {
            return T();
        }

        return node->data;
    }

    void remove(T data) {
        root = remove(root, data);
    }

    void inorder_print() {
        inorder_print(root);
    }

    vector<T> to_vector() {
        vector<T> vec;
        to_vector(root, vec);
        return vec;
    }
};

#endif // ORDERED_SET_H
