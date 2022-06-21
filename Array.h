
#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include "defs.h"

using namespace std;
/*  Class purpose: Handles the Array template object.

            Class functions: Holds an array of any data type.

            Variables:  int size, T* elements
*/


template <class T>
class Array {

	template <class V>
	friend ostream& operator<<(ostream&, Array<V>&);
	public:
		//Constructor
		Array();

		//Destructor
		~Array();

		//Other
		void add(T);
		T operator[](int index);
		int getSize();
		bool isFull();

	private:
		int size;
		T* elements;

};

template <class T>
Array<T>::Array(){
	elements = new T[MAX_ARR];
	size = 0;
}

template <class T>
Array<T>::~Array(){
	delete [] elements;
}

template <class T>
void Array<T>::add(T t){
	if (size >= MAX_ARR)   return;
  	elements[size++] = t;
}

template <class T>
int Array<T>::getSize(){
	return size;
}

template <class T>
bool Array<T>::isFull(){
	return size >= MAX_ARR;
}

template <class T>
T Array<T>::operator[](int index){
	if (index < 0 || index >= size) {
		cerr<<"Array index out of bounds"<<endl;
		exit(1);
	}
	return elements[index];
}

template <class v>
ostream& operator<<(ostream& ost, Array<v>& t) {

	for (int i = 0; i < t.size; i++) {

		ost<<*(t.elements[i])<<endl;
	}

	return ost;
}
#endif
