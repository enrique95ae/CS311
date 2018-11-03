//INSTRUCTION:
//Llist class - header file template (by Yoshii) based on Notes-6A
//You must complete the ** parts and then complete llist.cpp
// Don't forget PURPOSE and PARAMETERS 
// =======================================================
// HW#: HW3P1 llist
// Your name: Enrique Alonso Esposito
// Compiler:  g++ 
// File type: headher file 
//=======================================================

//----- Globally setting up the alias and struct  ----------------
typedef int el_t ;  // elements will be int

//a list node is defined here as a struct Node
// I could have done class Node and add the data members under public
// but it would use too much space
struct Node
{
  el_t Elem;   // elem is the element stored
  Node *Next;  // next is the pointer to the next node
};
//---------------------------------------------------------

class llist
{
  
 private:
  Node *Front;       // pointer to the front node
  Node *Rear;        // pointer to the rear node
  int  Count;        // counter for the number of nodes
  
 public:

  // Exception handling classes 
  class Underflow{};
  class OutOfRange{};  // thrown when the specified Node is out of range

  llist ();     // constructor to create a list object
  ~llist();     // destructor to destroy all nodes
  
  //PURPOSE: checks if list is empty
  //PARAMETERS: /
  bool isEmpty();
    
  //PURPOSE: prints out all the values that are currently in the list
  //PARAMETERS: /
  void displayAll();

  //PURPOSE: creates a node and adds it to the front of the list
  //PARAMETER: the value of the node to be added
  void addFront(el_t);
    
  //PURPOSE: creates a node and adds it to the rear of the list
  //PARAMETERS: the value of the node to be added
  void addRear(el_t);

  //PURPOSE: deletes the frist element of the list
  //PARAMETERS: the value that is removed
  void deleteFront(el_t&);
    
  //PURPOSE: deletes the last element of the list
  //PARAMETERS: the value that is removed
  void deleteRear(el_t&);
    
  //PURPOSE: deletes the Ith element (Ith = user input)
  //PARAMETERS: the value that is removed
  void deleteIth(int, el_t&);

  //PURPOSE: creates a node and adds it before the Ith element (Ith = user input)
  void addbeforeIth(int, el_t);
    
};
