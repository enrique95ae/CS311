//INSTRUCTION:
//Use the provided text to help create llist.cpp
//based on Yoshii  CS311  Notes-6A

//- Make sure PURPOSE and PARAMETER comments are given
//  DO NOT DELETE my descriptions but USE them.
//- Make sure all if-then-else are commented describing which case it is
//- Make sure all local variables are described fully with their purposes
//EMACS HINT:
//  control-K cuts and control-Y pastes
//  Esc X replace-str does string replacements
//  Esc > goes to the end of the file; Esc < to the beginning
//  Tab on each line will indent perfectly for C++
// ====================================================
//HW#: HW3P1 llist
//Your name: Enrique Alonso Esposito
//Complier:  g++
//File type: llist implementation file
//=====================================================

using namespace std;

#include<iostream>
#include"llist.h" 

/*
Constructor
- initialize Front and Rear to be NULL and Count = 0.
- This does not create any node.  The new list is empty.
*/
// PURPOSE:     To construct the object. Sets rear and front to NULL and count to 0.
llist::llist()
{
  Front = NULL;
  Rear = NULL;
  Count = 0;
}

/*
Destructor  
- while the list is not empty, call deleteFront repeatedly to delete all nodes.
- Please place a cout in this function "calling the llist desctructor."
*/
// PURPOSE:     // destructor to destroy all nodes
llist::~llist()
{
  int rm;
  while(!(isEmpty()))
    {
      deleteFront(rm);
    }
}

//Purpose: to check if the list is empty
//Parameters: None
bool llist::isEmpty()
{
  if(Front == NULL && Rear == NULL && Count == 0)
    {
      return true; // - return true if Front and Rear are both pointing to NULL and Count is 0.

    }else{
      return false;
    }
}
// - (all 3 conditions must be checked)

//Purpose: to display all values in the list
//Parameters: None
void llist::displayAll()
{
  if(isEmpty())      //- Special case: if the list is empty, display [ empty ] ).

    {
      cout << " [ empty ] " << endl;
    }else{           //  - Regular: displays each element of the list horizontally starting from Front in [ ].

    Node *x = Front;
    cout << "[ ";
    while(x != NULL)
      {
	cout << x->Elem << " ";
	x = x->Next;
      }
    cout << "]";
  }
}
 
//Purpose: to add a node to the rear
//Parameters: value to be added at the rear
void llist::addRear(el_t NewNum) 
{
    if (isEmpty())
      {
          Node* temp = new Node;
          temp->elem = NewNum;
          temp->Next = NULL;
          
          Front = Temp;
          Rear = Temp;
          Count++;
      }
    else
      {
	  //Regular case: adds a new node at the rear and puts NewNum in the Elem field of this new node. Count is updated.
        Rear->Next = new Node;
        Rear = Rear->Next;
        Rear->Elem = NewNum;
        Rear->Next = NULL;
        Count++
      }
}

//Purpose: to add a node to the front.
//Parameters: value to be added at the front
void llist::addFront(el_t NewNum)
{
  if(isEmpty())  
    {
      // Special case: if this is going to be the very first node, you must create a new node and make Front and Rear point to it. Place NewNum and Count is updated.
        Node* temp = new Node;
        temp->elem = NewNum;
        temp->Next = NULL;
        
        Front = Temp;
        Rear = Temp;
        Count++;
        
  }else{
    // Regular case: add a new node to the front of the list and Count is updated.
      Node *x;
      x = new Node;
      x->Next = Front;
      Front = x;
      Front->Elem = NewNum;
      
      Count++;
  }
}

//Purpose: deleters the front node
//Parameters: value to be removed
void llist::deleteFront(el_t& OldNum)
{
     if(isEmpty()) // Error case: if the List is empty, throw Underflow
       {
	 throw Underflow();
       }else if (Count == 1)  // Special case: if currently only one Node, give back the front node element through OldNum (pass by reference) and make sure both Front and Rear become NULL. Count is updated.
       { 
	 OldNum = Front->Elem;
	 delete Front;
	 Front = Rear = NULL;
	 Count--;  
       }else // Regular: give back the front node element through OldNum (pass by reference) and also removes the front node.  Count is updated.
       {
	 OldNum = Front->Elem;
	 Node *Second;
	 Second = Front->Next;
	 delete Front;
	 Front = Second;
	 Count--;
       }
}

//Purpose: to delete the last node
//Parameters: value to be removed
void llist::deleteRear(el_t& OldNum)
{
   if(isEmpty()) // Error case: if empty, throw Underflow
     {  
       throw Underflow();
     }  else if (Count == 1) //Special case: if currently only one node, give back the rear node element through OldNum (pass by reference) and make sure both Front and Rear become NULL. Count is updated.
     { 
       OldNum = Rear->Elem;
       delete Rear;
       Front = NULL; 
       Rear = NULL;
       Count--; 
     }else //Regular: give back the rear node element through OldNum (pass by reference) and also remove the rear node. Count is updated.
     {
       OldNum = Rear->Elem;
       Node *p = Front;
       while(p->Next != Rear) 
	 {
	   p = p->Next;
	 }
       delete Rear;
       Rear = p;
       Rear->Next = NULL;
       Count--;
     }
}

//Purpose: deletes the Ith element ( ith = user input)
//Parameters: value removed
void llist::deleteIth(int I, el_t& OldNum)
{
  if(I > Count || I < 1) // Error case: If I is an illegal value (i.e. > Count or < 1) throw OutOfRange.
    { 
      throw OutOfRange();
    }
  else if(I == 1) //Special cases: this should simply call deleteFront when I is 1 or deleteRear when I is Count
    {
      deleteFront(OldNum); 
    } 
  else if(I == Count) //Special cases: this should simply call deleteFront when I is 1 or deleteRear when I is Count
    { 
      deleteRear(OldNum);
    } 

  else //Regular: delete the Ith node (I starts out at 1).  Count is updated. <see the template loops in the notes to move 2 pointers to the right nodes;and make sure you indicate the purposes of these local pointers>
    { 
      Node *p = Front;
      Node *q = Front->Next;
      for(int K = 1; K < I-1; K++)
	{ 
	  p = p->Next; 
	  q = q->Next;
	}

      p->Next = q->Next;
      OldNum = q->Elem;
      delete q;
      Count--;
    }
}


//Purpose: adds a element befor the Ith elem (Ith = user input)
//Parameters: value to be added.
void llist::addbeforeIth(int I, el_t newNum)
{
  if(I > Count+1 || I < 1) // Error case: If I is an illegal value (i.e. > Count+1 or < 1) throw OutOfRange.
    {
      throw OutOfRange();
    }
  else if(I == 1) // Special cases: this should simply call addFront when I is 1 or addRear when I is Count+1
    {
      addFront(newNum); 
    }
  else if(I == Count+1) // Special cases: this should simply call addFront when I is 1 or addRear when I is Count+1
    {
      addRear(newNum); 
    }

  else // Regular: add right before the Ith node. Count if updated.<see the template loops in the notes to move 2 pointers to the right nodes and make sure you indicate the purposes of these local pointers>
    {
      Node *p = Front;

      for(int K = 1; K < I-1; K++)
	{
	  p = p->Next;
	}
      
      Node *temp = p->Next;
      p->Next = new Node;
      p->Next->Next = temp;
      p->Next->Elem = newNum;
      Count++;
    }
}
