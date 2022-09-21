#ifndef ORDERED_SET_H
#define ORDERED_SET_H

#include <iostream>

template<class T>
class Node
{
public:
    T Key;
    Node * Left;
    Node * Right;
    Node * Parent;
    int Height;
};

template<class T>
class OrderedSet
{
private:
    Node<T> * root;

protected:
    Node<T> * Insert(Node<T> * node, T key);
    void PrintTreeInOrder(Node<T> * node);
    Node<T> * Search(Node<T> * node, T key);
    T FindMin(Node<T> * node);
    T FindMax(Node<T> * node);
    T Successor(Node<T> * node);
    T Predecessor(Node<T> * node);
    Node<T> * Remove(Node<T> * node, T v);

public:
    OrderedSet();

    void Insert(T key);
    void PrintTreeInOrder();
    bool Search(T key);
    T FindMin();
    T FindMax();
    T Successor(T key);
    T Predecessor(T key);
    void Remove(T v);
};

template<class T>
OrderedSet<T>::OrderedSet() : root(NULL)
{
}

template<class T>
Node<T> * OrderedSet<T>::Insert(Node<T> * node, T key)
{
    if(node == NULL)
    {
        node = new Node<T>;
        node->Key = key;
        node->Left = NULL;
        node->Right = NULL;
        node->Parent = NULL;
    }
    
    else if(node->Key < key)
    {
        node->Right = Insert(node->Right, key);
        node->Right->Parent = node;
    }
    
    else
    {
        node->Left = Insert(node->Left, key);
        node->Left->Parent = node;
    }

    return node;
}

template<class T>
void OrderedSet<T>::Insert(T key)
{
    root = Insert(root, key);
}

template<class T>
void OrderedSet<T>::PrintTreeInOrder(Node<T> * node)
{
    if(node == NULL)
        return;

    PrintTreeInOrder(node->Left);

    std::cout << node->Key << " ";


    PrintTreeInOrder(node->Right);
}

template<class T>
void OrderedSet<T>::PrintTreeInOrder()
{
    
    PrintTreeInOrder(root);
    std::cout << std::endl;
}

template<class T>
Node<T> * OrderedSet<T>::Search(Node<T> * node, T key)
{
    
    if (node == NULL)
        return NULL;
    else if(node->Key == key)
        return node;
    else if(node->Key < key)
        return Search(node->Right, key);
    else
        return Search(node->Left, key);
}

template<class T>
bool OrderedSet<T>::Search(T key)
{
    Node<T> * result = Search(root, key);

    return result == NULL ?
        false :
        true;
}

template<class T>
T OrderedSet<T>::FindMin(Node<T> * node)
{
    if(node == NULL)
        return T();
    else if(node->Left == NULL)
        return node->Key;
    else
        return FindMin(node->Left);
}

template<class T>
T OrderedSet<T>::FindMin()
{
    return FindMin(root);
}

template<class T>
T OrderedSet<T>::FindMax(Node<T> * node)
{
    if(node == NULL)
        return T();
    else if(node->Right == NULL)
        return node->Key;
    else
        return FindMax(node->Right);
}

template<class T>
T OrderedSet<T>::FindMax()
{
    return FindMax(root);
}

template<class T>
T OrderedSet<T>::Successor(Node<T> * node)
{
    if (node->Right != NULL)
    {
        return FindMin(node->Right);
    }
    else
    {
        Node<T> * parentNode = node->Parent;
        Node<T> * currentNode = node;

        while ((parentNode != NULL) &&
            (currentNode == parentNode->Right))
        {
            currentNode = parentNode;
            parentNode = currentNode->Parent;
        }

        return parentNode == NULL ?
            T() :
            parentNode->Key;
    }
}

template<class T>
T OrderedSet<T>::Successor(T key)
{
    Node<T> * keyNode = Search(root, key);

    return keyNode == NULL ?
        T() :
        Successor(keyNode);
}

template<class T>
T OrderedSet<T>::Predecessor(Node<T> * node)
{
    if (node->Left != NULL)
    {
        return FindMax(node->Left);
    }
    else
    {
        Node<T> * parentNode = node->Parent;
        Node<T> * currentNode = node;

        while ((parentNode != NULL) &&
            (currentNode == parentNode->Left))
        {
            currentNode = parentNode;
            parentNode = currentNode->Parent;
        }

        return parentNode == NULL ?
            T() :
            parentNode->Key;
    }
}

template<class T>
T OrderedSet<T>::Predecessor(T key)
{
    Node<T> * keyNode = Search(root, key);

    return keyNode == NULL ?
        T() :
        Predecessor(keyNode);
}

template<class T>
Node<T> * OrderedSet<T>::Remove(Node<T> * node, T key)
{
    
    if (node == NULL)
        return NULL;

    if (node->Key == key)
    {
        if (node->Left == NULL && node->Right == NULL)
            node = NULL;
        else if (node->Left == NULL && node->Right != NULL)
        {
            node->Right->Parent = node->Parent;

            node = node->Right;
        }
        else if (node->Left != NULL && node->Right == NULL)
        {
            node->Left->Parent = node->Parent;

            node = node->Left;
        }
        else
        {
            T successorKey = Successor(key);

            node->Key = successorKey;

            node->Right = Remove(node->Right, successorKey);
        }
    }
    else if (node->Key < key)
        node->Right = Remove(node->Right, key);
    else
        node->Left = Remove(node->Left, key);

    return node;
}

template<class T>
void OrderedSet<T>::Remove(T key)
{
    root = Remove(root, key);
}


#endif // ORDERED_SET_H
