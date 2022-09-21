#ifndef MULTIMEORDONATA_H
#define MULTIMEORDONATA_H

#include <iostream>
#include <stack>

// Multime ordonata implementata folosind un arbore binar de cautare
template<class T>
class MultimeOrdonata {
    struct Node {
        T value;
        Node* left;
        Node* right;
        Node* parent;
    };

public:
    // iterator pentru elementele multimii ordonate
    // parcurge elementele in ordine crescatoare
    // foarte util pentru a itera prin niste utilizatori in ordine alfabetica
    class Iterator {
    public:
        // constructori cu parametrii si de copiere
        Iterator(Node* node, Node* root);
        Iterator(const Iterator& other);

        // supraincarcare operator ++ (folosit in iterare pentru a merge la urmatorul element)
        Iterator& operator++();
        Iterator operator++(int);

        // supraincarcare operatori de comparatie
        bool operator==(const Iterator& other) const;
        bool operator!=(const Iterator& other) const;

        // supraincarcare operatori de acces, pentru a face iteratorul sa functioneze exact ca un pointer
        T& operator*();
        T* operator->();
    private:
        // functie ajutatoare pentru a umple stack-ul ce ajuta la parcurgerea elementelor
        void fillStack(Node* node);
        bool hasNext();
        Node* getNode();

    private:
        // stack folosit pentru a itera mai usor prin elementele binary tree-ului
        std::stack<Node*> stack;
        Node* node;
        Node* root;

        friend class MultimeOrdonata;
    };

    // constructor si destructor
    MultimeOrdonata();
    ~MultimeOrdonata();

   /**
    * @brief  Insereaza un element in multimea ordonata
    * @note TREBUIE ca tipul de date folosit sa aiba supraincarcat operatorul >
    * @param  value: elementul inserat
    */
    void insert(const T& value);

   /**
    * @brief  Sterge un element din multimea ordonata
    * @param  value: elementul sters
    */
    void remove(const T& value);

   /**
    * @brief  Verifica daca un element exista in multimea ordonata
    * @param  value: elementul
    * @retval true daca exista, false in caz contrar
    */
    bool contains(const T& value) const;

   /**
    * @brief  Returneaza elementul minim din multimea ordonata
    * @note ex: primul elev (alfabetic) in catalog, cel mai mic numar intr-o multime
    * @retval elementul minim
    */
    T getMin() const; 

   /**
    * @brief  Returneaza elementul maxim din multimea ordonata
    * @note ex: ultimul elev (alfabetic) in catalog, cel mai mare numar intr-o multime
    * @retval elementul maxim
    */
    T getMax() const;

   /**
    * @brief  Verifica daca multimea este vida
    * @retval true daca nu exista elemente, false in caz contrar
    */
    bool isEmpty() const;

   /**
    * @brief  Returneaza numarul de elemente
    * @retval numarul de elemente
    */
    int getSize() const;

   /**
    * @brief  Sterge toate elementele din multime
    */
    void clear();

   /**
    * @brief  Returneaza un iterator catre primul element din multime (cel mai mic)
    * @retval iteratorul returnat
    */ 
    Iterator begin();

    /**
    * @brief  Returneaza un iterator catre elementul aflat dupa ultimul element din multime
    * @retval iteratorul returnat
    */ 
    Iterator end();

private:
    // functii ajutatoare

    // pointer catre nodul cu cel mai mic element
    Node* getMinNode() const;

    // sterge recursiv copii unui node
    void removeChildren(Node* node);

private:
    Node* root;
    int size;
};

template<class T>
inline MultimeOrdonata<T>::MultimeOrdonata()
    : root(nullptr),
      size(0)
{}

template<class T>
inline MultimeOrdonata<T>::~MultimeOrdonata()
{
    clear();
}

template<class T>
inline void MultimeOrdonata<T>::insert(const T& value) {
    if (isEmpty()) {
        root = new Node;
        root->value = value;
        root->left = nullptr;
        root->right = nullptr;
        root->parent = nullptr;
        size++;
        return;
    }

    Node* current = root;
    while (true) {
        if (value < current->value) {
            if (current->left == nullptr) {
                current->left = new Node;
                current->left->value = value;
                current->left->left = nullptr;
                current->left->right = nullptr;
                current->left->parent = current;
                size++;
                return;
            }

            current = current->left;
        } else if (value > current->value) {
            if (current->right == nullptr) {
                current->right = new Node;
                current->right->value = value;
                current->right->left = nullptr;
                current->right->right = nullptr;
                current->right->parent = current;
                size++;
                return;
            }

            current = current->right;
        } else {
            return;
        }
    }
}

template<class T>
inline void MultimeOrdonata<T>::remove(const T& value) {
    if (isEmpty()) {
        return;
    }

    Node* current = root;
    while (true) {
        if (value < current->value) {
            if (current->left == nullptr) {
                return;
            }

            current = current->left;
        } else if (value > current->value) {
            if (current->right == nullptr) {
                return;
            }

            current = current->right;
        } else {
            break;
        }
    }

    if (current->left == nullptr && current->right == nullptr) {
        if (current == root) {
            delete root;
            root = nullptr;
        } else {
            if (current->parent->left == current) {
                current->parent->left = nullptr;
            } else {
                current->parent->right = nullptr;
            }

            delete current;
        }

        size--;
        return;
    }

    if (current->left == nullptr) {
        if (current == root) {
            root = current->right;
            root->parent = nullptr;
            delete current;
        } else {
            if (current->parent->left == current) {
                current->parent->left = current->right;
                current->right->parent = current->parent;
            } else {
                current->parent->right = current->right;
                current->right->parent = current->parent;
            }

            delete current;
        }

        size--;
        return;
    }

    if (current->right == nullptr) {
        if (current == root) {
            root = current->left;
            root->parent = nullptr;
            delete current;
        } else {
            if (current->parent->left == current) {
                current->parent->left = current->left;
                current->left->parent = current->parent;
            } else {
                current->parent->right = current->left;
                current->left->parent = current->parent;
            }

            delete current;
        }

        size--;
        return;
    }
}

template<class T>
inline bool MultimeOrdonata<T>::contains(const T& value) const {
    if (isEmpty()) {
        return false;
    }

    Node* current = root;
    while (true) {
        if (value < current->value) {
            if (current->left == nullptr) {
                return false;
            }

            current = current->left;
        } else if (value > current->value) {
            if (current->right == nullptr) {
                return false;
            }

            current = current->right;
        } else {
            return true;
        }
    }
}

template<class T>
inline T MultimeOrdonata<T>::getMin() const {
    if (isEmpty()) {
        throw std::runtime_error("MultimeOrdonata is empty");
    }
    
    Node* current = root;
    while (current->left != nullptr) {
        current = current->left;
    }

    return current->value;
}

template<class T>
inline T MultimeOrdonata<T>::getMax() const {
    if (isEmpty()) {
        throw std::runtime_error("MultimeOrdonata is empty");
    }
    
    Node* current = root;
    while (current->right != nullptr) {
        current = current->right;
    }

    return current->value;
}

template<class T>
inline bool MultimeOrdonata<T>::isEmpty() const {
    return size == 0;
}

template<class T>
inline int MultimeOrdonata<T>::getSize() const {
    return size;
}

template<class T>
inline void MultimeOrdonata<T>::clear() {
    if (isEmpty()) {
        return;
    }

    removeChildren(root);
    delete root;
    root = nullptr;
    size = 0;
}

template<class T>
inline typename MultimeOrdonata<T>::Iterator MultimeOrdonata<T>::begin() {
    return Iterator(getMinNode(), root);
}

template<class T>
inline typename MultimeOrdonata<T>::Iterator MultimeOrdonata<T>::end() {
    return Iterator(nullptr, root);
}

template<class T>
inline typename MultimeOrdonata<T>::Node* MultimeOrdonata<T>::getMinNode() const {
    if (isEmpty()) {
        return nullptr;
    }
    
    Node* current = root;
    while (current->left != nullptr) {
        current = current->left;
    }

    return current;
}

template<class T>
inline void MultimeOrdonata<T>::removeChildren(Node* node) {
    if (node->left != nullptr) {
        removeChildren(node->left);
        delete node->left;
        node->left = nullptr;
    }

    if (node->right != nullptr) {
        removeChildren(node->right);
        delete node->right;
        node->right = nullptr;
    }
}


template<class T>
MultimeOrdonata<T>::Iterator::Iterator(Node* node, Node* root)
    : node(node),
      root(root)
{
    this->fillStack(node);
}

template<class T>
inline MultimeOrdonata<T>::Iterator::Iterator(const Iterator& other)
    : Iterator(other.node, other.root)
{
    this->stack = other.stack;
}

template<class T>
inline typename MultimeOrdonata<T>::Iterator& MultimeOrdonata<T>::Iterator::operator++() {
    if (this->node == nullptr) {
        return *this;
    }

    if (this->node->right != nullptr) {
        this->node = this->node->right;
        this->fillStack(this->node);
    } else {
        while (this->node->parent != nullptr && this->node->parent->right == this->node) {
            this->node = this->node->parent;
        }

        if (this->node->parent == nullptr) {
            this->node = nullptr;
        } else {
            this->node = this->node->parent;
        }
    }

    return *this;
}

template<class T>
inline typename MultimeOrdonata<T>::Iterator MultimeOrdonata<T>::Iterator::operator++(int) {
    Iterator result = *this;
    ++(*this);
    return result;
}

template<class T>
inline bool MultimeOrdonata<T>::Iterator::operator==(const Iterator& other) const {
    return node == other.node;
}

template<class T>
inline bool MultimeOrdonata<T>::Iterator::operator!=(const Iterator& other) const {
    return node != other.node;
}

template<class T>
inline T& MultimeOrdonata<T>::Iterator::operator*() {
    return node->value;
}

template<class T>
inline T* MultimeOrdonata<T>::Iterator::operator->() {
    return &node->value;
}

template<class T>
inline void MultimeOrdonata<T>::Iterator::fillStack(Node* node) {
    if (node == nullptr) {
        return;
    }

    stack.push(node);
    fillStack(node->left);
    fillStack(node->right);
}

template<class T>
inline typename MultimeOrdonata<T>::Node* MultimeOrdonata<T>::Iterator::getNode() {
    return node;
}


#endif // MULTIMEORDONATA_H
