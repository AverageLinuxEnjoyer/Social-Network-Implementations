#ifndef LIST_H
#define LIST_H


#include <vector>
using namespace std;

template <class T>
class List
{
public:

    typedef T* iterator;

    List();
    List(const vector<T> &vector);
    List(unsigned int size);
    List(unsigned int size, const T & initial);
    List(const List<T> & v);      
    ~List();

    unsigned int capacity() const;
    unsigned int size() const;
    bool empty() const;
    iterator begin();
    iterator end();
    T & front();
    T & back();
    void push_back(const T & value); 
    void pop_back();  
    void erase(int index);

    void reserve(unsigned int capacity);   
    void resize(unsigned int size);   

    T & operator[](unsigned int index);  
    List<T> & operator=(const List<T> &);
    void clear();
private:
    unsigned int my_size;
    unsigned int my_capacity;
    T * buffer;
};


template<class T>
List<T>::List()
{
    my_capacity = 0;
    my_size = 0;
    buffer = 0;
}

template <class T>
inline List<T>::List(const vector<T> &vector)
{
    my_capacity = vector.size();
    my_size = vector.size();
    buffer = new T[my_capacity];
    for (unsigned int i = 0; i < my_size; i++)
    {
        buffer[i] = vector[i];
    }
}

template<class T>
List<T>::List(const List<T> & v)
{
    my_size = v.my_size;
    my_capacity = v.my_capacity;
    buffer = new T[my_size];  
    for (unsigned int i = 0; i < my_size; i++)
        buffer[i] = v.buffer[i];
}

template<class T>
List<T>::List(unsigned int size)
{
    my_capacity = size;
    my_size = size;
    buffer = new T[size];
}

template<class T>
List<T>::List(unsigned int size, const T & initial)
{
    my_size = size;
    my_capacity = size;
    buffer = new T [size];
    for (unsigned int i = 0; i < size; i++)
        buffer[i] = initial;
}

template<class T>
List<T> & List<T>::operator = (const List<T> & v)
{
    delete[ ] buffer;
    my_size = v.my_size;
    my_capacity = v.my_capacity;
    buffer = new T [my_size];
    for (unsigned int i = 0; i < my_size; i++)
        buffer[i] = v.buffer[i];
    return *this;
}

template<class T>
typename List<T>::iterator List<T>::begin()
{
    return buffer;
}

template<class T>
typename List<T>::iterator List<T>::end()
{
    return buffer + size();
}

template<class T>
T& List<T>::front()
{
    return buffer[0];
}

template<class T>
T& List<T>::back()
{
    return buffer[my_size - 1];
}

template<class T>
void List<T>::push_back(const T & v)
{
    if (my_size >= my_capacity)
        reserve(my_capacity +5);
    buffer [my_size++] = v;
}

template<class T>
void List<T>::pop_back()
{
    my_size--;
}

template <class T>
void List<T>::erase(int index) {
    for (int i = index; i < my_size - 1; i++) {
        buffer[i] = buffer[i + 1];
    }
    my_size--;
}

template<class T>
void List<T>::reserve(unsigned int capacity)
{
    if(buffer == 0)
    {
        my_size = 0;
        my_capacity = 0;
    }    
    T * Newbuffer = new T [capacity];
    
    unsigned int l_Size = capacity < my_size ? capacity : my_size;\

    for (unsigned int i = 0; i < l_Size; i++)
        Newbuffer[i] = buffer[i];

    my_capacity = capacity;
    delete[] buffer;
    buffer = Newbuffer;
}

template<class T>
unsigned int List<T>::size()const//
{
    return my_size;
}

template<class T>
void List<T>::resize(unsigned int size)
{
    reserve(size);
    my_size = size;
}

template<class T>
T& List<T>::operator[](unsigned int index)
{
    return buffer[index];
}  

template<class T>
unsigned int List<T>::capacity()const
{
    return my_capacity;
}

template<class T>
List<T>::~List()
{
    delete[ ] buffer;
}
template <class T>
void List<T>::clear()
{
    my_capacity = 0;
    my_size = 0;
    buffer = 0;
}

#endif // LIST_H
