//==============================
// HW#: HW3P2
// Your name: Enrique Alonso Esposito
// Compiler: g++
// File type: implementation file
//==============================

using namespace std;

#include <iostream>
#include "slist.h"

//Purpose: Creates an empty llist
//Parameters: /
slist::slist()
{
  //  llist();
}

//Purpose: COPY CONTRUCTOR. creates a copy of a list
//Parameter: list that is being copied.
slist::slist(const slist& copyingList)
{
  Node *x;
  x = copyingList.Front;
  while(x!=NULL)
    {
      this->addRear(x->Elem);
      x = x->Next;
    }
}

//Purpose: makes one list equal to another
//Parameters: first list being copied. second list to be copied over.
slist& slist::operator=(const slist& CpOvList)
{
  int temp;
  if(&CpOvList != this)
    {
      while(!this->isEmpty()) //Deletes nodes while the list is not empty
	{
	  this->deleteRear(temp); 
	}
      Node *x;
      x = CpOvList.Front;
      
      while(x != NULL) //adding element by element to the list.
	{
	  this->addRear(x->Elem);
	  x = x->Next;
	}
    }
  return *this;
}

//Purpose: compares two lists
//Parameter: both lists to be compared
bool slist::operator==(const slist& compList)
{
  if(this->Count != compList.Count) //Easier case. If counters are different lists are therefor differen so,
    {
      return false; //returning false. if not:
    }
  //creating nodes that will be compared
  Node *x;
  Node *y;

  //setting both nodes to both fronts of both lists
  x = this->Front;
  y = compList.Front;

  while(x!=NULL)//since both lists have the same lenght we only need to check that one of them is not == NULL
    {
      if(x->Elem != y->Elem) //if some elements are not equal
	{
	  return false;
	}
      //going to the next two nodes.
      x = x->Next;
      y = y->Next;
    }
  return true; //once everything has been checked and there is no diferences we return true.
}

//Purpose: Find a value in the given list
//Parameter: Value to be found
int slist::search(el_t find)
{
  if(isEmpty())
    {
      cout << " [ empty ] " << endl ;
    }
  else
    {
      int pos = 1;
      Node *x = Front;
      while(x != NULL)
	{
	  if(x->Elem == find)
	    {
	      return pos;
	    }
	  x = x->Next;
	  pos++ ;
	}
      return 0;
    }
}  

//Purpose: To replace a value into the specified pos from the llist
//Parameter: positions and value.
void slist::replace(el_t Elem, int val)
{
  int temp;
  if(val < 1 || val > Count)
    {
      throw "OutOfRange";
    }
  if(val == 1)
    {
      deleteFront(temp);
      addFront(Elem);
    }
  else if(val == Count)
    {
      deleteRear(Count);
      addRear(Elem);
    }
  else
    {
      deleteIth(val, temp);
      addbeforeIth(val, Elem);
    }
}
