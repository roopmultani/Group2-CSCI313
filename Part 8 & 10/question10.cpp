//Question 10
  //Group:Nazara Ibrat, Rupinder Kaur, Mikhaiel Gomes, Luke Fang, Ergys Hila
#include <iostream>  
using namespace std;  
  
// Linked List Node (singly linked list) 
class Node {  
public: 
    int data;  
	  Node* next;  
};  
  
// This function is used to create a new node  
	Node* newNode(int num) {  
    Node *temp = new Node;  
    temp->data = num;  
    temp->next = nullptr;  
    return temp;  
}  
  
// this will order a given list of numbers  
Node *Order (Node *number)  {  
    if (number == nullptr)  
        return nullptr;  
         Node *odd = number;  
         Node *even = number->next;  
  
    // The first node of even list so that we can connect the even list at the end of odd list.  
    Node *evenSecond = even;  
  
   /* while- need a while loop to implent the linked list 
    {  
      // the data structure for the while function will be first used to separate the odd numbers
	  // then it will include the even numbers from least to greatest. 
        }  
  
        // ordering the even nodes after odd nodes  
        even->next = odd->next;  
        even = odd->next;  
    }  
  
    return number;  
}  
 */

//This is used function to print the linked list  
void printlist(Node * x)  {  
    while (x != nullptr) {  
        cout << x->data << "->";  //
        x = x->next;  
    }  
    cout << "Done" << endl; 
   
}  

//make a sort function

// main function   
int main()  {  
    Node *number = newNode(1);  
    number->next = newNode(2);  
    number->next->next = newNode(3);  
    number->next->next->next = newNode(4);  
    number->next->next->next->next = newNode(5);
    number->next->next->next->next->next = newNode(6);  
    number->next->next->next->next->next->next = newNode(7);
  
    cout << "Original Linked List"; 
    cout << endl; 
    printlist(number);  
    //sortlist(number);
    number = Order (number);  
  
    cout << "Ordered Linked List";  
    cout << endl;
    printlist(number);  
    //sortlist(number);
    return 0;  
} 