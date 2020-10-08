#pragma once
#include <iostream>
#include <string>
#include <math.h>
#include <fstream>
#include <time.h>
#include <iomanip>
#include "ListIterator.h"
#include "node.h"
using namespace std;

template<class T>
class LinkedList{
private:
	int count;      //create variables for list object
	node<T>* first;
	node<T>* last;

public:


	//list constructor
	LinkedList() {
		first = last = nullptr;
		count = 0;
	}


	void print() {
		node<T>* curr = first; //start from beginning
		    
		while (curr != nullptr) {       //traverse the list and print contents
			cout << curr->info << " ";
			curr= curr->link;
		}
	}

	void insert(const T& index, const T& value) {  //insert a node of choosen element before a target node
		if (first->info = index) {
			inserthead(value);
		}

		node<T>* prev = first;
	    node<T>* curr = curr->link;
			while (curr->info != index){//traverse the list to find the the location to insert node before the index
				prev = curr;
				curr = curr->link;
			}
			node<T>* node;
			node->info = value;

			prev->link = node;
			node->link = curr;

	}


	T   front() {
		assert(first != nullptr);  //print first node of list, otherwise show error if there
     	                           //there is no first node
		return first->info;       //return first node element of type
	}

	T size() {         //return the size of list of type
		return count;
	}

	T back() {
		assert(last != nullptr);  //show error if there is no last node 
		                            
		return last->info; //return the last element of list, 
	}

	void deleteList() {
		node<T>* temp;  //create temporary node
		                            
		while (first != nullptr) {//continue until all node are deleted from first node
			temp = first;          //take first node
			first = first->link;   //change first node to the next node
			delete temp;           //delete the first node
		}
		last = nullptr;          
		count = 0;
	}

	bool CheckEmpty() const {
		return (first == nullptr);  //return bool if first node is empty
	}

	void initializeList() {
		deleteList();          //reset the list
	}



	//iterator starts at the beginning of the list
	ListIterator<T> begin() {
		ListIterator<T> temp(first);
		return temp;
	}
	//iterator starts at the end of the list
	ListIterator<T> end() {
		ListIterator<T> temp(last);
		return temp;
	}


	//assignment operator
	const LinkedList<T>& operator=(const LinkedList<T>& otherList) {
		if (this != &otherList) {
			copyList(otherList);
		}
		return *this;
	}

	//copy constructor
	LinkedList(const LinkedList<T>& otherList) {
		first = nullptr;
		copy(otherList); 
	}


	//copy for copy constructor and assignment operator
	void copy(const LinkedList <T>& other) {
		node<T>* n;
		node<T>* curr;

		//recreate list if list is not empty
		if (first != nullptr) {
			deleteList();      
		}

		if (other.first == nullptr) {  //if the copied list is empty
			first = last = nullptr;
			count = 0;
		}
		else {
			curr = other.first;      
			count = other.count;

			first = new node<T>;     //create and copy first node 
			first->info = curr->info;
			first->link = nullptr;

			last = first;

			curr = curr->link;

			while (curr != nullptr) {   //continue copying throughout list
				n = new node<T>;      //copy next node
				n->info = curr->info;
				n->link = nullptr;

				last->link = n;   //connect to end of lidt
				last = n;

				curr = curr->link;
			}
		}
	}

	//move constructor
	LinkedList(LinkedList&& other) noexcept {
			
			
			count = other.count; //let current object's variables point to the list, and assume its values
			other.count = 0;
			first = other.first;
			other.first = nullptr;//remove pointers and values of the replaced object so there are no copies
			last = other.last;
			other.last = nullptr;
	}


	//move assignemnt operator
	LinkedList& operator=(LinkedList&& other)
	{
		if (this != &other)  //if the objects are not in the same location, continue
		{
			
			
			deleteList();   //delete current list that exists
			count = other.count;    //let current object's variables point to the other list, and assume its values
			other.count = 0;
			first = other.first;
			other.first = nullptr;//remove pointers of the replaced object so there are no copies
			last = other.last;
			other.last = nullptr;
			
		}
		return *this;
	}




	bool LinearSearch(const T& element) const {
		node<T>* curr;

		curr = first;                //start from beginning
		while (curr != nullptr) {     //go through list to find the element
			if (curr->info == element) //check contents
				return true;        //return true if found
				curr = curr->link;   //go to next node, if not found yet
		}
		return false;     //return false if nothing is found after end of list
	}

	


	void inserthead(const T& newnode) {
		node<T>* n= new node<T>;  //create new node
		n->info = newnode;       //add new node content

		n->link = first;     //connect the new node to the first node
		first = n;      //change the first node to be the new node
		count++;

		//if the list was empty then newNode would also be the last node in the list
		if (last == nullptr) {
			last = n;
		}
	}

	T at(int target)       //find target index, from list index from nodes 0->count-1
	{

		node<T>* curr = first;   //start with first node

		int count = 0;           //keep track of index
		while (curr != NULL)     //
		{
			if (count == target) {  //if the target index is found
				return curr->info;   //return the index location node contents
			}
			else {
				curr = curr->link;   //go to next node
				count++;             //keep track and proceed to next index
			}
		}


	}
	bool BinarySearch(int target)
	{

		int mid;         //create mid for storing elements at index
		int left = 0, right = count - 1;  //take index of first and last node in list
		while (left <= right) {
			int n = (right + left) / 2;  //find middle index

			mid = at(n);      //get index element

			if (mid == target)   //if the elemnt matches target, return true
				return true;

			else if (mid < target)  //if target is smaller than target search the left of list
				left = n + 1;

			else 
				right = n - 1;   //otherwise search right
		}
		return false;      //return false if not found after end of loop

	}




	void add(const T& info) {
		node<T>* n= new node<T>;  //create new node
		n->info = info;          //insert element into node
		n->link = nullptr;

		//if empty create new head 
		if (first == nullptr) {
			first = last = n;
			count++;        //keep track of list size
		}
		else {
			last->link = n;  //else add new node at the end
			last = n;
			count++;        //keep track of list size
		}
	}


	void erase(const T& value) {
		node<T>* curr;
		node<T>* prev;
		bool found;

		if (first == nullptr) {                 //if list is empty
			cout << "List is empty" << endl;
		}
		else {
			if (first->info == value) {   //if the value is in the firt node
				curr = first;           //unattached the first node from list and make the next node first
				first = first->link;
				count--;

				if (first == nullptr) 
				last = nullptr; //if the list has only one node
				delete curr;
			}
			else {
				found = false;
				prev = first;

				curr = first->link;

				while (curr != nullptr && !found) {  
					if (curr->info != value) {
						prev= curr;                 
						curr= curr->link;
					}
					else {
						found = true;
					}
				}

				if (found) {
					prev->link = curr->link;  //take the node before the node that to be deleted and attach it to the node after it
					count--;

					if (last == curr) last = prev; //if deleted node was the last node, make the node before it as last
					delete curr;  //delete the unattached node
				}
				else {
					cout << "Value not found" << endl;
				}
			}
		}
	}
		
	

};