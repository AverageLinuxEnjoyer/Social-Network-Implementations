#ifndef ORDEREDSET_H
#define ORDEREDSET_H

#include <vector>
#include <iostream>
using namespace std;

template<class T>
class OrderedSet {
public:
    OrderedSet();
    
    OrderedSet(const OrderedSet &other);
    
    ~OrderedSet();
    
    OrderedSet &operator=(const OrderedSet &other);
    
    void Insert(const T &value);
    
    void Remove(const T &value);
    
    bool Find(const T &value) const;
    
    int Size() const;
    
    bool IsEmpty() const;
    
    vector<T> ToVector() const;

    bool operator==(const OrderedSet &other) const;
    
    bool operator!=(const OrderedSet &other) const;
    
private:
    struct Node {
        T value;
        Node *left;
        Node *right;
        
        Node(const T &value) {
            this->value = value;
            this->left = NULL;
            this->right = NULL;
        }
    };
    
    Node *root;
    int size;
    
    void Insert(const T &value, Node *&root);
    
    void Remove(const T &value, Node *&root);
    
    bool Find(const T &value, Node *root) const;
    
    int Size(Node *root) const;
    
    void ToVector(Node *root, vector<T> &vector) const;
    
    bool Equals(Node *root1, Node *root2) const;
    
    void Copy(Node *&root1, Node *root2);
    
    void Clear(Node *&root);
    
    void Print(ostream &out, Node *root) const;
};

template<class T>
inline void OrderedSet<T>::Insert(const T &value, Node *&root) {
    if (root == NULL) {
        root = new Node(value);
        size++;
    } else if (value < root->value) {
        Insert(value, root->left);
    } else if (value > root->value) {
        Insert(value, root->right);
    }
}

template<class T>
inline void OrderedSet<T>::Remove(const T &value, Node *&root) {
    if (root == NULL) {
        return;
    } else if (value < root->value) {
        Remove(value, root->left);
    } else if (value > root->value) {
        Remove(value, root->right);
    } else {
        if (root->left == NULL && root->right == NULL) {
            delete root;
            root = NULL;
            size--;
        } else if (root->left == NULL) {
            Node *temp = root;
            root = root->right;
            delete temp;
            size--;
        } else if (root->right == NULL) {
            Node *temp = root;
            root = root->left;
            delete temp;
            size--;
        } else {
            Node *temp = root->right;
            while (temp->left != NULL) {
                temp = temp->left;
            }
            root->value = temp->value;
            Remove(temp->value, root->right);
        }
    }
}

template<class T>
inline bool OrderedSet<T>::Find(const T &value, Node *root) const {
    if (root == NULL) {
        return false;
    } else if (value < root->value) {
        return Find(value, root->left);
    } else if (value > root->value) {
        return Find(value, root->right);
    } else {
        return true;
    }
}

template<class T>
inline int OrderedSet<T>::Size(Node *root) const {
    if (root == NULL) {
        return 0;
    } else {
        return 1 + Size(root->left) + Size(root->right);
    }
}

template<class T>
inline void OrderedSet<T>::ToVector(Node *root, vector<T> &vector) const {
    if (root == NULL) {
        return;
    } else {
        ToVector(root->left, vector);
        vector.push_back(root->value);
        ToVector(root->right, vector);
    }
}

template<class T>
inline bool OrderedSet<T>::Equals(Node *root1, Node *root2) const {
    if (root1 == NULL && root2 == NULL) {
        return true;
    } else if (root1 == NULL || root2 == NULL) {
        return false;
    } else {
        return root1->value == root2->value &&
               Equals(root1->left, root2->left) &&
               Equals(root1->right, root2->right);
    }
}

template<class T>
inline void OrderedSet<T>::Copy(Node *&root1, Node *root2) {
    if (root2 == NULL) {
        root1 = NULL;
    } else {
        root1 = new Node(root2->value);
        Copy(root1->left, root2->left);
        Copy(root1->right, root2->right);
    }
}

template<class T>
inline void OrderedSet<T>::Clear(Node *&root) {
    if (root == NULL) {
        return;
    } else {
        Clear(root->left);
        Clear(root->right);
        delete root;
        root = NULL;
    }
}

template<class T>
inline void OrderedSet<T>::Print(ostream &out, Node *root) const {
    if (root == NULL) {
        return;
    } else {
        Print(out, root->left);
        out << root->value << " ";
        Print(out, root->right);
    }
}

template<class T>
inline OrderedSet<T>::OrderedSet()
{
    root = NULL;
    size = 0;
}

template<class T>
inline OrderedSet<T>::OrderedSet(const OrderedSet &other)
{
    Copy(root, other.root);
    size = other.size;
}

template<class T>
inline OrderedSet<T>::~OrderedSet()
{
    Clear(root);
}

template<class T>
inline OrderedSet<T> &OrderedSet<T>::operator=(const OrderedSet<T> &other) {
    if (this != &other) {
        Clear(root);
        Copy(root, other.root);
        size = other.size;
    }
    return *this;
}

template<class T>
inline void OrderedSet<T>::Insert(const T &value) {
    Insert(value, root);
}

template<class T>
inline void OrderedSet<T>::Remove(const T &value) {
    Remove(value, root);
}

template<class T>
inline bool OrderedSet<T>::Find(const T &value) const {
    return Find(value, root);
}

template<class T>
inline int OrderedSet<T>::Size() const {
    return size;
}

template<class T>
inline bool OrderedSet<T>::IsEmpty() const {
    return size == 0;
}

template<class T>
inline vector<T> OrderedSet<T>::ToVector() const {
    vector<T> vector;
    ToVector(root, vector);
    return vector;
}

template<class T>
inline bool OrderedSet<T>::operator==(const OrderedSet<T> &other) const {
    return Equals(root, other.root);
}

template<class T>
inline bool OrderedSet<T>::operator!=(const OrderedSet<T> &other) const {
    return !(*this == other);
}


#endif