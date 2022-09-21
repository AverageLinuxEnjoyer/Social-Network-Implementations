#pragma once

template <class K, class V>
class Dictionary
{
private:
	struct nod
	{
		K key; V value;
		nod* next;
	};
	nod* head;
	int marime;
public:
	Dictionary() {
		head = nullptr;
		marime = 0;
	}
	~Dictionary() {
		nod* current = head;
		while (current)
		{
			nod* next = current->next;
			delete current;
			current = next;
		}
	}
	void adaugare(K key, V value)
	{
		if (contains(key))
		{
			nod* current = head;
			while (current)
			{
				if (current->key == key)
				{
					current->value = value;
					return;
				}
				current = current->next;
			}
		}
		nod* n = new nod{ key, value, head };
		head = n;
		marime++;
	}
	void remove(K key)
	{
		nod* current = head;
		nod* previous = nullptr;
		while (current)
		{
			if (current->key == key)
			{
				if (previous == nullptr)
					head = current->next;
				else
					previous->next = current->next;
				delete current;
				marime--;
				return;
			}
			previous = current;
			current = current->next;
		}
	}
	V& operator[](K key)
	{
		nod* current = head;
		while (current)
		{
			if (current->key == key)
				return current->value;
			current = current->next;
		}
		if (current == nullptr)
		{
			adaugare(key, V());
			return head->value;
		}
		return current->value;
	}
	bool contains(K key)
	{
		nod* current = head;
		while (current)
		{
			if (current->key == key)
				return true;
			current = current->next;
		}
		return false;
	}

};