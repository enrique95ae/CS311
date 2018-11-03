//Based on Yoshii's template 
//=========================================================
//HW#: HW1P1 stack
//Your name: Enrique Alonso Esposito
//Complier:  g++
//File type: stack implementation file
//=========================================================

using namespace std;
#include <iostream>
#include "stack.h"

//PURPOSE:  Constructor must initialize top to be -1 to begin with.
stack::stack()
{ top = -1; /* indicate an empty stack  */ }

//PURPOSE:  Destructor does not have to do anything since this is a static array.
stack::~stack()
{ /* nothing to do*/ }

//PURPOSE:  checks top and returns true if empty, false otherwise.
// ** In the comment, make sure you define "empty" in terms of top.
bool stack::isEmpty()
{ if (top == -1) return true; else return false; }

//PURPOSE: checks top and returns true if full, false otherwise.
//** In the comment, make sure you define "full" in terms of top.
bool stack::isFull()
  { if (top == MAX-1 ) return true; else return false; }

//PURPOSE: calls isFull and if true, throws an exception (Overflow)
//   Otherwise, adds an element to el after incrementing top.
//PARAMETER: pass the element (elem) to be pushed
 void stack::push(el_t elem)
 { if (isFull()) throw Overflow();
   else { top++; el[top] = elem; }}

 //PURPOSE: calls isEmpty and if true, throws an exception (Underflow)
 //  Otherwise, removes an element from el and gives it back.
 //PARAMETER: provide a holder (elem) for the element popped (pass by ref)
 void stack::pop(el_t& elem)
 { if (isEmpty()) throw Underflow();
   else { elem = el[top]; top--;}}

// PURPOSE: calls isEmpty and if true, throws an exception (underflow)
//    Otherwise, gives back the top element from el.
//PARAMETER: provide a holder (elem) for the element (pass by ref)
 void stack::topElem(el_t& elem)
 { if (isEmpty()) throw Underflow();
   else { elem = el[top]; } }

//PURPOSE: dislayAll calls isEmpty and if true, displays [ empty ].
//          Otherwise, diplays the elements vertically.
 void stack::displayAll()
 {  if (isEmpty()) cout << "[ empty ]" << endl;
   else for (int i=top; i>=0; i--)
     { cout << el[i] << endl; }
   cout << "--------------" << endl;
 }


//PURPOSE: pops all elements from the stack to make it empty if it is not empty yet.
 void stack::clearIt()
 {
     int x; //variable to hold the popped value
      if (isEmpty()) cout << "Stack is empty" << endl;
   else
   {
     while(isEmpty() == false)
       {
        pop(x);
       }
   }
 }


