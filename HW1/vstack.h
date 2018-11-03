//INSTRUCTION:
//Stack class - header file template (by Yoshii) based on Notes-1
//You must complete the ** parts and then complete stack.cpp
//EMACS HINT:
//  control-S does searches
//  Tab on each line will indent perfectly for C++

// =======================================================
// HW#: HW1P2 vector stack
// Your name: Enrique Alonso Esposito
// Compiler:  g++
// File type: headher file vstack.h
//=======================================================

#include <vector>

//----- Globally setting up the aliases ----------------

typedef int el_t;      // the el_t type is ** for now
                      // el_t is unknown to the client
//-------------------------------------------------------


class stack
{
 private: // to be hidden from the client

  vector<el_t> vectorStack;     // el is  an array of el_t's

 public: // prototypes to be used by the client
  // Note that no parameter variables are given

  // exception handling classes
  class Overflow{};   // thrown when the stack overflows
  class Underflow{};  // thrown when the stack underflows

  stack();   // constructor to create an object
  ~stack();  // destructor  to destroy an object

  // PURPOSE: if not full, enters an element at the top;
  //          otherwise throws an exception - Overflow
  // PARAMETER: pass the element to be pushed
  void push(el_t);

  // PURPOSE: if not empty, removes and gives back the top element;
  //          otherwise throws an exception - Underflow
  // PARAMETER: provide variable to receive the popped element (pass by ref)
  void pop(el_t&);

  // PURPOSE: if not empty, gives the top element without removing it;
  //          otherwise, throws an exception - Underflow
  // PARAMETER: provide a holder (elem) for the element (pass by ref)
  void topElem(el_t&);

  // ** Must add good comments for each function - See Notes1B

  //PURPOSE:  checks top and returns true if empty, false otherwise.
  bool isEmpty();
  //PURPOSE: checks top and returns true if full, false otherwise.
  bool isFull();
  //PURPOSE:always returns false.
  void displayAll();
  //PURPOSE: pops all elements from the stack to make it empty if it is not empty yet.
  void clearIt();

};

// Note: semicolon is needed at the end of the header file

