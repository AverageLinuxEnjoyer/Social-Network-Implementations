#ifndef ORDERED_SET_H
#define ORDERED_SET_H

#include <iostream>

template<class T>
struct Nod {
    T Cheie;
    Nod* Stange;
    Nod* Dreapta;
    Nod* Parinte;
    int Inaltime;
};

template<class T>
class MutlimeOrdonata
{
private:
    Nod<T> * radacina;

protected:
    Nod<T> * inserare(Nod<T> * nod, T key);
    void afisare_in_ordine(Nod<T> * nod);
    Nod<T> * cautare(Nod<T> * nod, T key);
    T min(Nod<T> * nod);
    T max(Nod<T> * nod);
    T urmatorul(Nod<T> * nod);
    T anteriorul(Nod<T> * nod);
    Nod<T> * stergere(Nod<T> * nod, T v);

public:
    MutlimeOrdonata();

    void inserare(T key);
    void afisare_in_ordine();
    bool cautare(T key);
    T min();
    T max();
    T urmatorul(T key);
    T anteriorul(T key);
    void stergere(T v);
};

template<class T>
MutlimeOrdonata<T>::MutlimeOrdonata() : radacina(NULL)
{
}

template<class T>
Nod<T> * MutlimeOrdonata<T>::inserare(Nod<T> * nod, T key)
{
    if(nod == NULL)
    {
        nod = new Nod<T>;
        nod->Cheie = key;
        nod->Stange = NULL;
        nod->Dreapta = NULL;
        nod->Parinte = NULL;
    }
    else if(nod->Cheie < key)
    {
        nod->Dreapta = inserare(nod->Dreapta, key);
        nod->Dreapta->Parinte = nod;
    }
    else
    {
        nod->Stange = inserare(nod->Stange, key);
        nod->Stange->Parinte = nod;
    }

    return nod;
}

template<class T>
void MutlimeOrdonata<T>::inserare(T key)
{
    radacina = inserare(radacina, key);
}

template<class T>
void MutlimeOrdonata<T>::afisare_in_ordine(Nod<T> * nod)
{
    if(nod == NULL)
        return;

    afisare_in_ordine(nod->Stange);

    std::cout << nod->Cheie << " ";

    afisare_in_ordine(nod->Dreapta);
}

template<class T>
void MutlimeOrdonata<T>::afisare_in_ordine()
{
    afisare_in_ordine(radacina);
    std::cout << std::endl;
}

template<class T>
Nod<T> * MutlimeOrdonata<T>::cautare(Nod<T> * nod, T key)
{
    if (nod == NULL)
        return NULL;
    else if(nod->Cheie == key)
        return nod;
    else if(nod->Cheie < key)
        return cautare(nod->Dreapta, key);
    else
        return cautare(nod->Stange, key);
}

template<class T>
bool MutlimeOrdonata<T>::cautare(T key)
{
    Nod<T> * result = cautare(radacina, key);

    return result == NULL ?
        false :
        true;
}

template<class T>
T MutlimeOrdonata<T>::min(Nod<T> * nod)
{
    if(nod == NULL)
        return T();
    else if(nod->Stange == NULL)
        return nod->Cheie;
    else
        return min(nod->Stange);
}

template<class T>
T MutlimeOrdonata<T>::min()
{
    return min(radacina);
}

template<class T>
T MutlimeOrdonata<T>::max(Nod<T> * nod)
{
    if(nod == NULL)
        return T();
    else if(nod->Dreapta == NULL)
        return nod->Cheie;
    else
        return max(nod->Dreapta);
}

template<class T>
T MutlimeOrdonata<T>::max()
{
    return max(radacina);
}

template<class T>
T MutlimeOrdonata<T>::urmatorul(Nod<T> * nod)
{
    if (nod->Dreapta != NULL)
    {
        return min(nod->Dreapta);
    }
    else
    {
        Nod<T> * parentNode = nod->Parinte;
        Nod<T> * currentNode = nod;

        while ((parentNode != NULL) &&
            (currentNode == parentNode->Dreapta))
        {
            currentNode = parentNode;
            parentNode = currentNode->Parinte;
        }

        return parentNode == NULL ?
            T() :
            parentNode->Cheie;
    }
}

template<class T>
T MutlimeOrdonata<T>::urmatorul(T key)
{
    Nod<T> * keyNode = cautare(radacina, key);

    return keyNode == NULL ?
        T() :
        urmatorul(keyNode);
}

template<class T>
T MutlimeOrdonata<T>::anteriorul(Nod<T> * nod)
{
    if (nod->Stange != NULL)
    {
        return max(nod->Stange);
    }
    else
    {
        Nod<T> * parentNode = nod->Parinte;
        Nod<T> * currentNode = nod;

        while ((parentNode != NULL) &&
            (currentNode == parentNode->Stange))
        {
            currentNode = parentNode;
            parentNode = currentNode->Parinte;
        }

        return parentNode == NULL ?
            T() :
            parentNode->Cheie;
    }
}

template<class T>
T MutlimeOrdonata<T>::anteriorul(T key)
{
    Nod<T> * keyNode = cautare(radacina, key);

    return keyNode == NULL ?
        T() :
        anteriorul(keyNode);
}

template<class T>
Nod<T> * MutlimeOrdonata<T>::stergere(Nod<T> * nod, T key)
{
    if (nod == NULL)
        return NULL;

    if (nod->Cheie == key)
    {
        if (nod->Stange == NULL && nod->Dreapta == NULL)
            nod = NULL;
        else if (nod->Stange == NULL && nod->Dreapta != NULL)
        {
            nod->Dreapta->Parinte = nod->Parinte;

            nod = nod->Dreapta;
        }
        else if (nod->Stange != NULL && nod->Dreapta == NULL)
        {
            nod->Stange->Parinte = nod->Parinte;

            nod = nod->Stange;
        }
        else
        {
            T successorKey = urmatorul(key);

            nod->Cheie = successorKey;

            nod->Dreapta = stergere(nod->Dreapta, successorKey);
        }
    }
    else if (nod->Cheie < key)
        nod->Dreapta = stergere(nod->Dreapta, key);
    else
        nod->Stange = stergere(nod->Stange, key);

    return nod;
}

template<class T>
void MutlimeOrdonata<T>::stergere(T key)
{
    radacina = stergere(radacina, key);
}


#endif // ORDERED_SET_H
