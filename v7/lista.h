#pragma once

template <class T>
class Lista
{
private:
	T* elems;
	int capacitate;
	int marime;
public:
	Lista();
	void resize(int noua_capacitate);
	T& operator[](int index);
	void adauga(T element, int index);
	void stergere(int index);
	int getMarime();
};

template <class T>
inline Lista<T>::Lista()
{
	capacitate = 10;
	marime = 0;
	elems = new T[capacitate];
}

template <class T>
inline void Lista<T>::resize(int noua_capacitate) {
	T* nou = new T[noua_capacitate];
	for (int i = 0; i < marime; i++)
		nou[i] = elems[i];
	delete[] elems;
	elems = nou;
	capacitate = noua_capacitate;
}

template <class T>
inline T& Lista<T>::operator[](int index) {
	return elems[index];
}

template <class T>
inline void Lista<T>::adauga(T element, int index) {
	if (marime == capacitate)
		resize(capacitate * 2);
	for (int i = marime; i > index; i--)
		elems[i] = elems[i - 1];
	elems[index] = element;
	marime++;
}

template <class T>
inline void Lista<T>::stergere(int index) {
	for (int i = index; i < marime - 1; i++)
		elems[i] = elems[i + 1];
	marime--;
}

template <class T>
inline int Lista<T>::getMarime() {
	return marime;
}
