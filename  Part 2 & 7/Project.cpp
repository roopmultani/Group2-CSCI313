//Group: Fang Luke, Gomes Mikhaiel, Hila Ergys, Ibrat Nazara, Kaur Rupinder
#include <chrono>
#include <iostream>
#include<time.h>
#include "LinkedList.h"
#include "node.h"
#include <string>
#include<utility>
#include<algorithm>
#include "ListIterator.h"
#include "Vector.h"
#include <stdio.h>
#include <stdlib.h>
using std::chrono::system_clock;
using std::chrono::steady_clock;
using std::chrono::duration_cast;
using std::chrono::seconds;
using std::chrono::milliseconds;
using std::chrono::nanoseconds;
using namespace std;

template <typename Func>
long long TimeFunc(Func f)
{
	auto begin = steady_clock::now();
	f();
	auto end = steady_clock::now();

	return duration_cast<nanoseconds>(end - begin).count();
}

//Functions-------------------------------------------------------------------------------------------------------------

bool recursivebinarysearch(int* array, int left, int right, int value)
{
	//find middle index of array 
	int m = (right + left) / 2;


	//if target is found in middle of array return true
	if (array[m] == value)
		return true;

	//after checking entire array base on sorted array, if no target value is found return false
	if (m == right || m == left) {
		return false;
	}

	//if target value is smaller than the middle value of the array, do search of the left side of the array
	if (value < array[m])
		return recursivebinarysearch(array, left, m, value);

	//if target value is bigger than than the middle value of the array, do search on the right side the array
	else
		return recursivebinarysearch(array, m, right, value);

}


bool iterativebinarysearch(int* array, int left, int right, int value)
{

	int m;
	while (left <= right) {					//using loop instead of recursion
	    m = (right + left) / 2;

		if (array[m] == value) {
			return true;
		}
		else if (value > array[m]) {
			left = m + 1;
		}
		else {
			right = m - 1;
		}
	}
	return false;
}
//-----------------------------------------------------------------------------------------

void fillvec() {
	Vector<int> v;
	for (int i = 0; i < 1000; i++)      //fill vector with random numbers from 0-9
	{
		v.push_back(rand() % 10);
	}

}



void filllist() {

	LinkedList<int> list1;

	for (int i = 0; i < 1000; i++)
	{
		list1.add(rand() % 10);     //fill list for random numbers 0-9
	}

}


string RandomString()
{
	int n = ((rand() % 10) + 1); //size 1-10

	string s = "";
	for (int i = 0; i < n; i++)
		s = s + (char)((rand() % (122 - 96)) + 97); //create string of random size with random ascii letters, using ascii decimals 97-122 to char

	return s;
}


int main() {

	srand(time(NULL));

	//question #2
	//--------------------------------------------------------------------------------

	int value = 1;
	LinkedList<int> list2;
	for (int i = 0; i < 1000000; i++)
	{

		int skip = rand() % 10 + 1;
		list2.add(value + skip);           //by random amounts for next number
		value = (value + skip);

	}
	auto begin = steady_clock::now();
	list2.BinarySearch(600000);
	auto end = steady_clock::now();
	                                                            //convert nanoseconds to milliseconds of type double 
	cout << "Linked-Type binary search for random array of size 1mil time:" << " " << (double)(duration_cast<nanoseconds>(end - begin).count())/ 1000000 << "ms" << endl;

	//Array of size 1million filled with random numbers-----------------------------------------------------
	int* array = new int[1000000];



	value = 1;
	for (int i = 0; i < 1000000; i++) {  //Refill with random numbers by starting with a value and incrementing 
		int skip = rand() % 10 + 1;      //by random amounts for next number
		*(array + i) = value + skip;
		value = *(array + i);
	}

	auto g = TimeFunc([&]() {recursivebinarysearch(array, 0, 1000000 - 1, 600000); });
	cout << "Recursive Binary Search for random array of size 1mil time:" << " " << (double)g / 1000000 << "ms" << endl;

	g = TimeFunc([&]() {iterativebinarysearch(array, 0, 1000000 - 1, 600000); });
	cout << "Iterative Binary Search for random array of size 1mil time:" << " " << (double)g / 1000000 << "ms" << endl;



	//Array size 10mil random numbers-------------------------------------------------------
	int* array1 = new int[10000000];


	value = 1;
	for (int i = 0; i < 10000000; i++) {
		int skip = rand() % 10 + 1;         //Fill with random numbers
		*(array1 + i) = value + skip;
		value = *(array1 + i);
	}


	g = TimeFunc([&]() {recursivebinarysearch(array1, 0, 10000000 - 1, 600000); });
	cout << "Recursive Binary Search for random array of size 10mil time:" << " " << (double)g / 1000000 << "ms" << endl;

	g = TimeFunc([&]() {iterativebinarysearch(array1, 0, 10000000 - 1, 600000); });
	cout << "Iterative Binary Search for random array of size 10mil time:" << " " << (double)g / 1000000 << "ms" << endl;



	//Array size 100mil random numbers-------------------------------------------

	int* array2 = new int[100000000];


	value = 1;
	for (int i = 0; i < 100000000; i++) {
		int skip = rand() % 10 + 1;         //Fill with random numbers
		*(array2 + i) = value + skip;
		value = *(array2 + i);
	}

	g = TimeFunc([&]() {recursivebinarysearch(array1, 0, 100000000 - 1, 600000); });
	cout << "Recursive Binary Search for random array of size 100mil time:" << " " << (double)g / 1000000 << "ms" << endl;

	g = TimeFunc([&]() {iterativebinarysearch(array1, 0, 100000000 - 1, 600000); });
	cout << "Iterative Binary search for random array of size 100mil time:" << " " << (double)g / 1000000 << "ms" << endl;

	//---------------------------------------------------------------------------------------------------------
     
    //Question #7

	//--------------------------------------------------------------------------
	//List filled with random numbers
	auto listmilliseconds = TimeFunc([&]() {filllist(); });
	cout << "Random Numbers for list: " << (double)listmilliseconds / 1000000 << "ms" << endl;
	//---------------------------------------------------------------

	//function fills vector of random numbers

	auto vecmilliseconds = TimeFunc([&]() {fillvec(); });

	cout << "Random Numbers for Vectors: " << (double)vecmilliseconds / 1000000 << "ms" << endl;

	//------------------------------------------------------------------------------

	//list filled with random strings
	LinkedList<string> list4;         //create a list
	begin = steady_clock::now();
	for (int i = 0; i < 1000; i++)
	{
		list4.add(RandomString());
	}
     end = steady_clock::now();

	//list4.print();

	cout << "Random String for list: " << (double)(duration_cast<nanoseconds>(end - begin).count()) / 1000000 << "ms" << endl;


	//----------------------------------------------------------------------------

	Vector<string> vec1;
    begin= steady_clock::now();   //time from beginning 
	for (int i = 0; i < 1000; i++)
	{
		vec1.push_back(RandomString());    //insert random string
	}
    end = steady_clock::now();   //end time 

	cout << "Random String for Vector: " << (double)(duration_cast<nanoseconds>(end - begin).count()) / 1000000 << "ms" << endl;

	//--------------------------------------------------------------------

	//move semantics for string list
	begin = steady_clock::now();
	LinkedList<string> list5(move(list4)); //convert list4 to r value
	end = steady_clock::now();


	cout << "Move semantics for list: " << (double)(duration_cast<nanoseconds>(end - begin).count()) / 1000000 << "ms" << endl;


	//move semantics for vector
	begin = steady_clock::now(); //start time
	Vector<string> v1(move(vec1));//convert vec1 to r value
	end = steady_clock::now();//end time


	cout << "Move semantics for Vectors: " << (double)(duration_cast<nanoseconds>(end - begin).count()) / 1000000 << "ms" << endl;


	return 0;
}


