//Name: Enrique Alonso Esposito
//Type of file: Client File for HW7
//Compiler: g++
//Date: 12/01/2017

//Purpose of the program: Read a graph stored ina text file and do a DFS.
//Algorithm:
//    -Data is read into an object (type dgraph) from the file
//    -We then initizialice a link list and a stack to hold adjacent values.
//    -Then while there is something in the stack we pop elements from it
//        -We check the popped element in order to see if it has already been marked (visited)
//        -If not (visit == 0) we mark it, find its adjacents and add them to the stack
//           (making sure we have previously removed the already marked vertex)
//        -We also give the vertex a UNIQUE visit number.
//        -Then we display the current Stack.
//        -Once we have gone through all the verteces, we dislay the final graph after the DFS.



#include <iostream>
#include "dgraph.h"
#include "stack.h"
using namespace std;


int main()
{
  //variables and initializations
  dgraph TableObj;
  stack adjacentStack;
  slist adjacentList;
  char vertexTemp;
  int traverse = 2;

  //from tavle.txt into tableObj.
  TableObj.fillTable();
  TableObj.displayGraph();

  TableObj.visit(1, 'A'); //A gets the first visit number

  cout << endl;
  cout << "DFS in progress..." << endl;
  cout << "--------------------------" << endl ;
  cout << endl ;
  cout << endl ;

  cout << "visited A";
  cout << endl ;
  adjacentList = TableObj.findAdjacency('A');

  //if the ll is not empty 
  while(!adjacentList.isEmpty())
    {
      adjacentList.deleteRear(vertexTemp); //store the last element in the ll into temp
      adjacentStack.push(vertexTemp); //push it into the stack
    }

  adjacentStack.displayAll();
  cout << endl;

  //if the stack is not empty
  while(!adjacentStack.isEmpty())
    {
      cout << "ACTION: Removing a vertex from the stack" << endl ;
      adjacentStack.pop(vertexTemp); //poping from stack into temp
      cout << "Vertex Name: " << vertexTemp << endl ;
      
      //checking if temp has been previously visited
      if(!TableObj.isMarked(vertexTemp) == 1)
	{//if not
	  TableObj.visit(traverse, vertexTemp);
	  cout << "The vertex: " << vertexTemp << " has now been visited. " << endl;
	  adjacentList = TableObj.findAdjacency(vertexTemp);
	  
	  //from slist to stack
	  while(!adjacentList.isEmpty())
	    {
	      adjacentList.deleteRear(vertexTemp);
	      cout << "ACTION: Pushing " << vertexTemp << " (is adjacent) into stack" << endl;
	      adjacentStack.push(vertexTemp);
	    }
	  cout << "STACK IS: " << endl;
	  adjacentStack.displayAll();
	  cout << endl ;
	  traverse++;
	}
      else
	{//if it has been already visited
	  cout << "NOTE: Vertex:" << vertexTemp << " has already been visited before" << endl ;
	}
    }
  cout << endl ;
  cout << endl ;
  
  cout << "Graph AFTER DFS: " << endl;
  cout << "-----------------------" << endl ;
  cout << endl ;

  //displying the resulting graph.
  TableObj.displayGraph();

  return 0;
}
