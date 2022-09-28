//Breckin Hume
//2143 OOP
//9/19/22

#include <fstream>
#include <iostream>
using namespace std;

//Struct to set up nodes for the linked lists
struct Node {
  int data;
  Node *next;
  Node *previous;

  Node(int d) {
    data = d;
    next = NULL;
    previous = NULL;
  }
};

/*
Class Name: Vector
Protected Values:
Pointer Head(Front of the List)
Pointer Tail(End of the List)
Public Values and Functions:
Vector
Void Frontsert(Function to add a value to the front of the list)
Void Backsert(Function to add a value to the end of the list)
Void InOrdersert(Function to add a value to the list and fitting it in numerical order)
Void Remove(Function that removes an item from the list)
Void Print(Function that prints the entire list)
Void PopHead(Function that removes the value at the front of the list)
Void PopTail(Function that removes the value at the end of the list)
Void Shift(Function that links lists together)
Void Search(Function that seeks out a specific item in the list)

*/
class Vector
{
protected:
  Node *head;
  Node *tail;
public:

  Vector() 
  {
    head = NULL;
    tail = NULL;
  }

  Vector(const Vector &other){
    head = NULL;
    tail = NULL;
    // loop over other and insert its values into THIS instance
  }

  // Function for inserting nodes at the front of the list
  void frontsert(int d) 
  {

    Node *temp = new Node(d);

    if (head == NULL) {

      head = temp;
      tail = temp;
    }

    else {
      temp->next = head;
      head->previous = temp;
      head = temp;
    }
  }

  // function to add nodes to the end of the list
   void backsert(int d) {

    Node *temp = new Node(d);

    if (head == NULL) {

      head = temp;
      tail = temp;
    } else {
      temp->previous = tail;
      tail->next = NULL;
      tail = temp;
    }

    delete temp;
  }

  // In order function
  void inordersert(int d) {

    Node *temp = new Node(d);

    if (head == NULL) {

      head = temp;
      tail = temp;
    }

    else {
      if (temp->data < head->data)
        frontsert(d);

      else {

        Node *traverse = head;
        Node *trailing = NULL;

        while (temp->data > traverse->data && traverse) {
          trailing = traverse;
          traverse = traverse->next;
        }
        if (traverse == NULL)
          backsert(d);
        else {
          temp->next = traverse;
          traverse->previous = temp;
          trailing->next = temp;
          temp->previous = trailing;
        }
      }
    }
  }

  // Remove function
  void remove(int d) {
    if (d == head->data && head == tail) {
      head = NULL;
      tail = NULL;
    } else if (d == head->data) {
      Node *temp = head;

      head = head->next;
      delete temp;
      head->previous = NULL;
      temp = NULL;
    } else if (d == tail->data) {
      tail = tail->previous;

      delete tail->next;
      tail->next = NULL;
    }

    else {
      Node *traverse = head;
      Node *trailing = NULL;
      while (traverse && traverse->data != d) {
        trailing = traverse;
        traverse = traverse->next;
      }
      if (traverse != NULL) {
        trailing->next = traverse->next;
        traverse->next->previous = trailing;
        delete traverse;
        
      }
    }
  }
  // Printout function
  void print() {
     ofstream outfile;
    outfile.open("output.dat");
    Node *traverse = head;
    while (traverse) {
      cout << traverse->data << " "  ;
      outfile << traverse->data << " " ;
      traverse = traverse->next;
   
    
    }
  }

  void pophead() {
    if (head != NULL) {

      Node *temp = head;
      head = head->next;

      temp = NULL;
      if (head != NULL)
       delete head->previous;
    }
  }

  void poptail() {
    if (head != NULL) {
      if (head->next == NULL) {
        head = NULL;
      } else {
        Node *temp = head;
        while (temp->next->next != NULL)
          temp = temp->next;
        Node *lastNode = temp->next;
        delete temp->next;
        free(lastNode);
      }
    }
  }
 

  void shift(Vector A) {
   Node *traverse = head;
    while (traverse) {
      // cout << traverse->data << " ";
      backsert(traverse->data);
      traverse = traverse->next;
      }
  }

  void search(int searchValue) {

    Node *temp = head;
    cout << " " << endl;
    int found = 0;
    int i = 0;
    if (temp != NULL) {
      while (temp != NULL) {
        i++;
        if (temp->data == searchValue) {
          found++;
          break;
        }
        temp = temp->next;
      }
      if (found == 1) {
        cout << searchValue << " is found at index = " << i << ".\n";
      } else {
        cout << searchValue << " is not found in the list.\n";
      }
    } else {
      cout << "The list is empty.\n";
    }
  }
};
  //=================================================================================================
  //=================================================================================================
  //=================================================================================================
  //=================================================================================================
  //=================================================================================================
  //=================================================================================================
  //=================================================================================================

  int main() {
    cout << "Breckin Hume\n 2143 OOP\n Program 1\n" << endl;
    ofstream outfile;
    
    ifstream infile;
    infile.open("input.dat");
    int x = 0;
    ifstream fin;

    Vector v1;
    v1.frontsert(18);
    v1.frontsert(20);
    v1.frontsert(25);
    v1.backsert(18);
    v1.backsert(20);
    v1.backsert(25);
    v1.print();
  
    int arr[] = {11, 25, 33, 47, 51};
    Vector v2;
    v2.backsert(arr[x]);
    v2.print();
    

    v2.frontsert(9);
 
    v2.backsert(63);
    v2.print();
 
    v1.shift(v2);
    v1.print();

    v1.pophead();
    v1.pophead();
    v1.pophead();
    v1.print();


    v1.poptail();
    v1.poptail();
    v1.poptail();
    v1.print();
   
    v2.remove(3);
    v2.print();
  
    v2.search(51);
    

    v2.search(99);
  

    Vector v3(v1);

    while (!fin.eof()) {
      fin >> x;
      v3.frontsert(x);
      v3.print();
    

      v3.shift(v2);
      v3.print();
     

      Vector v4;

      v4.shift(v3);
      v4.print();
      outfile.close();
      
    }
  }
