#ifndef MULTIMEORDONATA_H
#define MULTIMEORDONATA_H


template<class T>
class MultimeOrdonata {
private:
    struct Node {
        T value;
        Node* left;
        Node* right;
        Node(T value, Node* left = nullptr, Node* right = nullptr) {
            this->value = value;
            this->left = left;
            this->right = right;
        }
    };

    Node* root;

    Node* insert(Node* node, T value) {
        if (node == nullptr) {
            return new Node(value);
        }
        if (value < node->value) {
            node->left = insert(node->left, value);
        }
        else {
            node->right = insert(node->right, value);
        }
        return node;
    }

    Node* remove(Node* node, T value) {
        if (node == nullptr) {
            return nullptr;
        }
        if (value < node->value) {
            node->left = remove(node->left, value);
        }
        else if (value > node->value) {
            node->right = remove(node->right, value);
        }
        else {
            Node* left = node->left;
            Node* right = node->right;
            delete node;
            if (right == nullptr) {
                return left;
            }
            Node* min = findMin(right);
            min->right = removeMin(right);
            min->left = left;
            return min;
        }
        return node;
    }

    Node* findMin(Node* node) {
        if (node->left == nullptr) {
            return node;
        }
        return findMin(node->left);
    }

    Node* removeMin(Node* node) {
        if (node->left == nullptr) {
            return node->right;
        }
        node->left = removeMin(node->left);
        return node;
    }

    bool contains(Node* node, T value) {
        if (node == nullptr) {
            return false;
        }
        if (value < node->value) {
            return contains(node->left, value);
        }
        else if (value > node->value) {
            return contains(node->right, value);
        }
        else {
            return true;
        }
    }

    void removeAll(Node* node) {
        if (node == nullptr) {
            return;
        }
        removeAll(node->left);
        removeAll(node->right);
        delete node;
    }

    int get_size(Node* node) {
        if (node == nullptr) {
            return 0;
        }
        return get_size(node->left) + get_size(node->right) + 1;
    }

public:
    MultimeOrdonata() {
        root = nullptr;
    }

    ~MultimeOrdonata() {
        removeAll(root);
    }

    void insert(T value) {
        root = insert(root, value);
    }

    void remove(T value) {
        root = remove(root, value);
    }

    bool contains(T value) {
        return contains(root, value);
    }

    int get_size() {
        return get_size(root);
    }
};


#endif // MULTIMEORDONATA_H
