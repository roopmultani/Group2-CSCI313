#pragma once
#include "node.h"
#include <string>
#include <iostream>
using namespace std;

template<class T>
class ListIterator {  //iterator to transverse through list
private:
	node<T>* curr;

public:
	//constructors
	ListIterator() { 
		curr = nullptr; 
	}
	ListIterator(node<T>* ptr) { 
		curr = ptr; 
	}

	//operator overloads
	T operator*() {
		return curr->info;
	}

	ListIterator<T> operator++() {    //tranverse through list using operator ++
		curr = curr->link;
		return *this;
	}
	bool operator==(const ListIterator<T>& obj) const {
		return (curr == obj.curr);
	}
	bool operator!=(const ListIterator<T>& obj) const {
		return (curr != obj.curr);
	}
};
