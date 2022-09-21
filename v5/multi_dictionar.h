#ifndef MULTI_DICTIONAR_H
#define MULTI_DICTIONAR_H

#include <vector>

template<typename T, typename U>
class Multi_Dictionar 
{
    struct ListNode 
    {
        U data;
        ListNode *next;
    };

    struct DictNode 
    {
        T cheie;
        ListNode* data;
        DictNode *next;
    };

    DictNode* cautare(T cheie) 
    {
        DictNode* curent = head;

        while (curent != nullptr) 
        {
            if (curent->cheie == cheie)
                return curent;

            curent = curent->next;
        }
        return nullptr;
    }
public:
    Multi_Dictionar()
    {
        head = nullptr;
    }

    ~Multi_Dictionar() 
    {
        DictNode *curr = head;

        while (curr != nullptr) 
        {
            DictNode *next = curr->next;

            delete curr->data;
            delete curr;

            curr = next;
        }
    }

    void add(T cheie, U data) 
    {
        DictNode *curent = cautare(cheie);

        if (curent == nullptr) 
        {
            DictNode *newNode = new DictNode;

            newNode->cheie = cheie;

            newNode->data = new ListNode;
            newNode->data->data = data;
            newNode->data->next = nullptr;

            newNode->next = head;
            
            head = newNode;
        } 
        else 
        {
            ListNode *newNode = new ListNode;

            newNode->data = data;
            newNode->next = curent->data;

            curent->data = newNode;
        }
    }

    std::vector<U> remove(T cheie) 
    {
        std::vector<U> datas;
        DictNode *curent = cautare(cheie);

        if (curent == nullptr) 
        {
            return datas;
        } 
        else 
        {
            ListNode *prev = nullptr;
            ListNode *curr = curent->data;

            while (curr != nullptr) 
            {
                datas.push_back(curr->data);

                prev = curr;
                curr = curr->next;

                delete prev;
            }
        }

        if (curent->next == nullptr) 
        {
            delete curent;
            head = nullptr;
        }

        return datas;
    }

    void remove(T cheie, U data) 
    {
        DictNode *curent = cautare(cheie);

        if (curent == nullptr) 
        {
            return;
        } 
        else 
        {
            ListNode *curr = curent->data;
            ListNode *prev = nullptr;

            while (curr != nullptr) 
            {
                if (curr->data == data) 
                {
                    if (prev == nullptr) 
                    {
                        curent->data = curr->next;
                    } 
                    else 
                    {
                        prev->next = curr->next;
                    }

                    delete curr;
                    return;
                }

                prev = curr;
                curr = curr->next;
            }
        }
    }

    std::vector<U> get(T cheie) 
    {
        DictNode *curent = cautare(cheie);

        if (curent == nullptr) 
        {
            return std::vector<U>();
        } 
        else 
        {
            ListNode *curr = curent->data;
            std::vector<U> rezultat;

            while (curr) 
            {
                rezultat.push_back(curr->data);
                curr = curr->next;
            }

            return rezultat;
        }
    }

    bool search(T cheie) 
    {
        return cautare(cheie) != nullptr;
    }

    bool search(T cheie, U data) 
    {
        DictNode *curent = cautare(cheie);

        if (curent == nullptr) 
        {
            return false;
        } 
        else 
        {
            ListNode *curr = curent->data;

            while (curr != nullptr) 
            {
                if (curr->data == data) 
                {
                    return true;
                }

                curr = curr->next;
            }

            return false;
        }
    }

private:
    DictNode *head;
};



#endif // MULTI_DICTIONAR_H
