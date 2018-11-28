#ifndef LIST_H
#define LIST_H


#include <iostream>
#include "other.h"


template<typename T>
class List {
	size_t size;
	T* data;

public:
	List(size_t length = 0): size(length), data(new T[size]) { }

	~List() { delete[] data; }
	size_t length() { return size; }

	void setLen();
  void Reader();
	void Search(const String& str); 

	T& operator[](size_t index) { return data[index]; }
	const T& operator[](size_t index) const { return data[index]; }

	// Iterátor belső osztály
	class iterator {
		T* pointer;																	// Az aktuális elem pointere
	public:
		iterator(T* ptr = NULL) : pointer(ptr) { }											// Konstruktorban megkapjuk a kezdőcímet
		T& operator*() { return *pointer; }											// Dereferáljuk az aktuális elemet
		iterator operator++() { pointer++; return *this; }							// Prefix inkremetálás: ++it használatához
		iterator operator++(int) { iterator i = *this; pointer++; return i; }		// Postfix inkrementálás: it++ használatához
		bool operator==(const iterator& rhs) { return pointer == rhs.pointer; }		// Két iterátor összehasonlítása
		bool operator!=(const iterator& rhs) { return pointer != rhs.pointer; }		// Két iterátor negált összehasonlítása
	};

	iterator begin() { return iterator(data); }										// Első elem iterátora
	iterator end() { return iterator(data+size); }									// Utolsó utáni elem iterátora

};

#endif //LIST_H
