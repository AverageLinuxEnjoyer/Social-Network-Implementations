#ifndef MultiDictionar_HPP
#define MultiDictionar_HPP

#include <vector>
#include "Lista.h"

template<class T, class U>
class MultiDictionar {
private:
    struct ListNode {
        U value;
        ListNode *next;
    };

    struct MapNode {
        T key;
        ListNode* value;
        MapNode *next;
    };

    MapNode* searchAddress(T key);
public:
    MultiDictionar(); 
    ~MultiDictionar();

    void put(T key, U value);
    Lista<U> remove(T key);
    void remove(T key, U value);
    Lista<U> get(T key);
    bool contains(T key);
    bool contains(T key, U value);
    Lista<std::pair<T, U>> getAll();

private:
    MapNode *head;
};

template<class T, class U>
inline typename MultiDictionar<T,U>::MapNode* MultiDictionar<T, U>::searchAddress(T key) {
    MapNode* current = head;
    while (current != nullptr) {
        if (current->key == key) {
            return current;
        }
        current = current->next;
    }
    return nullptr;
}

template<class T, class U>
inline MultiDictionar<T, U>::MultiDictionar()
    : head(nullptr)
{}

template<class T, class U>
inline MultiDictionar<T, U>::~MultiDictionar()
{
    MapNode *curr = head;
    while (curr != nullptr) {
        MapNode *next = curr->next;
        delete curr->value;
        delete curr;
        curr = next;
    }
}

template<class T, class U>
inline void MultiDictionar<T, U>::put(T key, U value) {
    MapNode *current = searchAddress(key);
    if (current == nullptr) {
        MapNode *newNode = new MapNode;
        newNode->key = key;
        newNode->value = new ListNode;
        newNode->value->value = value;
        newNode->value->next = nullptr;
        newNode->next = head;
        head = newNode;
    } else {
        ListNode *newNode = new ListNode;
        newNode->value = value;
        newNode->next = current->value;
        current->value = newNode;
    }
}

template<class T, class U>
inline Lista<U> MultiDictionar<T, U>::remove(T key) {
    Lista<U> values;
    MapNode *current = searchAddress(key);
    if (current == nullptr) {
        return values;
    } else {
        ListNode *prev = nullptr;
        ListNode *curr = current->value;
        while (curr != nullptr) {
            values.push_front(curr->value);
            prev = curr;
            curr = curr->next;
            delete prev;
        }
    }

    if (current->next == nullptr) {
        delete current;
        head = nullptr;
    }

    return values;
}

template<class T, class U>
inline void MultiDictionar<T, U>::remove(T key, U value) {
    MapNode *current = searchAddress(key);
    if (current == nullptr) {
        return;
    } else {
        ListNode *curr = current->value;
        ListNode *prev = nullptr;
        while (curr != nullptr) {
            if (curr->value == value) {
                if (prev == nullptr) {
                    current->value = curr->next;
                } else {
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

template<class T, class U>
inline Lista<U> MultiDictionar<T, U>::get(T key) {
    MapNode *current = searchAddress(key);
    if (current == nullptr) {
        return Lista<U>();
    } else {
        ListNode *curr = current->value;
        Lista<U> result;
        while (curr != nullptr) {
            result.push_front(curr->value);
            curr = curr->next;
        }

        return result;
    }
}

template<class T, class U>
inline bool MultiDictionar<T, U>::contains(T key) {
    return searchAddress(key) != nullptr;
}

template<class T, class U>
inline bool MultiDictionar<T, U>::contains(T key, U value) {
    MapNode *current = searchAddress(key);
    if (current == nullptr) {
        return false;
    } else {
        ListNode *curr = current->value;
        while (curr != nullptr) {
            if (curr->value == value) {
                return true;
            }
            curr = curr->next;
        }
        return false;
    }
}

template<class T, class U>
inline Lista<std::pair<T, U>> MultiDictionar<T, U>::getAll() {
    Lista<std::pair<T, U>> result;
    MapNode *current = head;
    while (current != nullptr) {
        ListNode *curr = current->value;
        while (curr != nullptr) {
            result.push_back(std::make_pair(current->key, curr->value));
            curr = curr->next;
        }
        current = current->next;
    }
    return result;
}

#endif // MultiDictionar_HPP
