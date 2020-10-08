#pragma once
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <cassert>    
#include <iostream>

using namespace std;
template <typename T>
class Vector {
private:
    T* arr= nullptr;  //pointer to array
    int size;    //number of elements in array
    int addsize; //size of array
public:
   
    using iterator = T*; //iterator of pointer vector array of type T*
 
    
    //default constuctor
    Vector() {                             
        arr = nullptr;
        size = 0;
        addsize = 0;
    };

    //copy constructor
    Vector(const Vector& v)
    {
        arr = new T[size];              

        addsize = v.addsize;
        size = v.size;     
                                
    
        for (int i = 0; i < size; i++)  {
            arr[i] = v.arr[i];
        }
    }

    // move constructor
    Vector(Vector&& v) noexcept {
        size = v.size; // copy number of elements
        addsize = v.addsize;   //copy capacity
        arr = v.arr;         // point to existing elements

        // empty the passed in vector 
        v.size = 0;
        v.addsize = 0;
        v.arr = nullptr;
    }

    T getsize() {
        return size; //return size of vector
    }

    // constructor that accepts an integer value for initial size

    Vector(int initialsize) {
        size = addsize = initialsize; // set initial size
        arr = new T[size];          // create array of that size

        // initialize values of array
        for (int i = 0; i < initialsize; ++i) {
            arr[i] = T();       
        }
    }

    T back() {
        return arr[size - 1]; //return top of stack
    }


    T front() {
        return arr[0]; //return bottom of stack
    }



    void swap(Vector& v) {
       int* temp = arr;      //save first vector content
       int  tem = size;
       int te = addsize;
         
        arr = v.arr;       //change first vector content to second vector
        size = v.size;
        addsize = v.addsize;

        v.arr = temp;     //used saved content of first to other vector
        v.size = tem;
        v.addsize = te;

    }

    void pop_back() {
        arr[size] = NULL;    //delete eleemnt of top of stack
        size--;               //subtract size to keep track of size
    }


    void push_back(T item) {
        if (addsize == 0)             // if array empty, add size
            reserve(1);               // start with size of 1
        else if (size == addsize)   // if array full, add resizable memory
            reserve(2*addsize);      // double size         

        arr[size] = item;      // add item
        ++size;                 // increment for next element array to keep track of array index
    }
  

    void reserve(int add) {
        if (add <= addsize)         //make sure the add is bigger, for added space
            return;
        T* array = new T[add];          //set new size capicity
        for (int i = 0; i < size; ++i) {
            array[i] = arr[i];
        }
        delete[] arr;                  //delete current array      
        arr = array;                    //replace array with cahnge capacity
        addsize = add;                 //change capicity variable  
    }




    // destructor
    ~Vector() {
        delete[] arr;  
    }
   
    // copy assignment
    Vector& operator=(const Vector& v) {
        size = v.size; // copy number of elements
        addsize = v.size;    //copy space of array
        T* array = new T[size];
      
       

        //recreate and copy elements of other array
        for (int i = 0; i < size; ++i) {
            array[i] = v.arr[i];
        } 

        //delete current array
        delete[] arr;

        arr= array;

        return *this;   //return a self reference of vector
    }

    //move assignment
    Vector<T>& operator=(Vector&& v) {
        if (this != &v) {       //if the vectors are not the same location
            size = v.size;     // copy number of elements and space in array
            addsize = v.addsize;           

           
            delete[] arr;   //delete current array
            arr= v.arr;     //current array pointer points to other array

            
            v.size = 0;      //reset the copied vector
            v.addsize = 0;
            v.arr = nullptr;
        }

      
        return *this;  // return a self reference of vector
    }
 
    

    T at(int i) {
        if (i < 0 || i >= size)
            throw std::out_of_range("Index out of range");
        else
            return arr[i];
    }
    
  

  
    void resize(int addspace) {
        reserve(addspace);    //make capicity larger
        for (int i = size; i < addspace; ++i) {  // fill array with initial values (0)
            arr[i] = T();
        }

        // reset number of elements (size)
        if (addspace > size)
            size = addspace;    
    }

      void print() {
        for (int i = 0; i < size; i++) { //tranverse the vector and print contents
            cout << arr[i] << endl;
        }
    }



    iterator begin() { return arr; }            //return array of vector to traverse through                        
    iterator end() { return arr +size; }         //last element of array by adding size     
    

};

