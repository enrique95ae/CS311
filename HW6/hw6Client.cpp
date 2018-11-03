//HW6
//Enrique Alonso Esposito
//Compiler g++
//File type: Client file

// ====   For the HW6 Client file ====================================
//INSTRUCTION: Complete this file and comment using How to Comment file.

#include "dgraph.h"
using namespace std;


int main()
{

  int exit = 0;
  char key; //vertex looking for
  int degree;
  slist adjacents;
  dgraph TableObj; //0.Declare table object
  int exception = 0;
  
  TableObj.fillTable(); //1.fillTable()
  TableObj.displayGraph(); //2.displayGraph()
  
  while (exit == 0)
    {
      //a.the user will specify which vertex     
      cout << endl;
      cout << "Please enter the vertex: ";
      cin >> key;
      cout << endl;
      try
	{
	  //finding out degree of vertex
	  degree = TableObj.findOutDegree(key);
	}
      catch(dgraph::BadVertex) //catching exception
	{
	  cerr << "ERROR: vertex does not exist! "<< endl;
	  exception = 1;
	}
      
      if(exception == 0)
	{
	  //printting out the degree
	  cout << "The degree is: " << degree << endl;
	}

      cout <<"Please, enter one of the following: " << endl ;
      cout <<"0. if you wish to look for the degree of another vertex." << endl ;
      cout <<"1. if you wish to look for the adjacents of another vertex." << endl ;
      cout <<"2. to quit." << endl ;
      cout <<"Your option: " ;
      cin >> exit;
      cout << endl ;
      exception = 0;
    }


  while (exit == 1)
    {
      cout << "Enter the vertex: " ; //User specifies vertex
      cin >> key;
      cout << endl;
      try
	{
	  adjacents = TableObj.findAdjacency(key); //finding adjacency
	}
      
      catch(dgraph::BadVertex) //catching exception
	{
	  cerr << "ERROR: the vertex does not exist! "<< endl;
	  exception = 1;
	}

      if(exception == 0)
	{
	  cout << "Adjacents are: " ;
	  adjacents.displayAll();
	  cout << endl ;
	}
      
      cout <<"Please, enter one of the following: " << endl ;
      cout <<"1. if you wish to look for the adjacents of another vertex." << endl ;
      cout <<"2. to quit." << endl ;
      cout <<"Your option: " ;
      cin >> exit;
      exception = 0;
    }
}
