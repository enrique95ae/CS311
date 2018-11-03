//HW6
//Name: Enrique Alonso Esposito
//Compiler g++
//Type File: Implementation File

#include <fstream>
#include "dgraph.h"
#include <iostream>

// ====   For the dgraph.cpp file ====================================
// INSTRUCTION:
// Complete all the functions you listed in dgraph.h
// Comment the file completely using How to Comment file.
//=====================================

//CONSTRUCTOR
//Initializes the elements in the array.
//vertexName to blank
//vist to 0
//countUsed to 0 as well
dgraph::dgraph()
{
  for(int i=0; i<SIZE; i++)
    {
      Gtable[i].vertexName = ' ';
        Gtable[i].visit = 0;
    }
    countUsed = 0;
}

dgraph::~dgraph()
{
  //DESTRUCTOR
}

/* note that Gtable[i].adjacnentOnes is a slist, so you can use
   any slist function on it

Hint on filltable::

Set up fin stream to read from table.txt
while (fin >> Gtable[countUsed].vertexName)  // if I can read the name
{ fin >> Gtable[coutUsed].outDegree;
  // Then for the outDegree times do the following: (use a for-loop)
  {
     fin >> X;
     (Gtable[coutUsed].adjacentOnes).addRear(x); 
                      // this uses a slist function from HW3
  }//end of for
  // increment the countUsed
}//end of while
close fin
*/

//Purpose: Reads information from file and adds the data to the graph
//PArameters: None
void dgraph::fillTable()
{
  char x;
  ifstream fin;
  fin.open("table.txt");
  
  while(fin>>Gtable[countUsed].vertexName) //if can read the name
    {
      fin>>Gtable[countUsed].outDegree;
      //Then for the outDegree times do the following
      for(int i=0; i<Gtable[countUsed].outDegree; i++)
	{
	  fin>>x;
	  (Gtable[countUsed].adjacentOnes).addRear(x); //slist from HW3;
	}
      countUsed++; //incrementing counter.
    }
  fin.close(); //closing file
}

/*
Hint on displaygraph::

Make the following couts better with labels.
for (int i = 0; i < coutUsed; i++}
{  
    cout << Gtable[i].vertexname << endl;
    cout << Gtable[i].outdegree << endl;
    (Gtable[i].adjacentOnes).displayAll();
}

//Purpose: Displays Vertex, degree and adjacents of the vertex in the current gr
aph                                                                             
//Parameters: none                                                             
*/
void dgraph::displayGraph()
{
  for(int i=0; i < countUsed; i++)
    {
      cout << "Vertex is: " << Gtable[i].vertexName << endl;
      cout << "Out Degree: " << Gtable[i].outDegree << endl;
      cout << "Adjacent Values: " << endl;
      (Gtable[i].adjacentOnes).displayAll();
    }
}

  
/*
Instruction on findOutDegree and findAdjacency::

For this HW, you must use a loop.
Do not go through all the slots of the table

*/

//Purpose: Finds the vertex the user entered and displays it´s degree
//Parameters: key which contains the value of the vertex whose degree are to be
//displayed
int dgraph::findOutDegree(char key)
{
    for (int i=0; i < countUsed; i++)
    {
            if(Gtable[i].vertexName == key)
            {
                return Gtable[i].outDegree;
            }
    }
    throw BadVertex();
}

//Purpose: Finds the vertex the user entered and displays it´s adjacents
//Parameters: key which contains the value of the vertex whose adjacents are to be
//displayed 
slist dgraph::findAdjacency(char key)
{
    for (int i=0; i < countUsed; i++)
    {
        if(Gtable[i].vertexName == key)
        {
            return Gtable[i].adjacentOnes;
        }
    }
    throw BadVertex();
}

