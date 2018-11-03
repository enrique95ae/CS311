//=========================================================
//HW#: HW3EC operator overload ==
//Your name: Enrique Alonso Esposito
//Complier:  g++
//File type: client program (tester)
//===========================================================

#include <iostream>
#include "slist.h"
using namespace std;

int main()
{
  //BOTH LISTS
  slist L1;
  slist L2;
  
  //USED VARIABLES. 
  int temp;


  //TEST CASES:

  //L1 is empty and L2 is empty ------------------------> TRUE
  cout << endl << endl;
  cout << "CASE 1: " << endl ;
  cout << "Result:                                    ";
  if(L1 == L2)
    {
      cout << "TRUE." ;
    }
  else
    {
      cout << "FALSE." ;
    }
  cout << endl;
  cout << "----------------------------------------------------" << endl << endl << endl;

  //L1 is empty and L2 has two elements ------------------------> FALSE
  cout << "CASE 2: " << endl ;
  cout << "Result:                                    ";
  L2.addRear(1);
  L2.addRear(2);
  if(L1 == L2)
    {
      cout << "TRUE." ; //
    }
  else
    {
      cout << "FALSE.";
    }
  cout << endl;
  cout << "----------------------------------------------------" << endl << endl << endl;

  //L1 has 2 elements and L2 is empty
  cout << "CASE 3: " << endl ;
  cout << "Result:                                    ";
  L1.addRear(1);
  L1.addRear(2);
  L2.deleteRear(temp);
  L2.deleteRear(temp);
  if(L1 == L2)
    {
      cout << "TRUE." ; 
    }
  else
    {
      cout << "FALSE.";
    }
  cout << endl;
  cout << "----------------------------------------------------" << endl << endl << endl;

  //L1 has 1,2,3 and L2 has 1,2,3
  cout << "CASE 4: " << endl ;
  cout << "Result:                                    ";
  L1.addRear(3);
  // L1.addRear(2);
  L2.addRear(1);
  L2.addRear(2);
  L2.addRear(3);
  if(L1 == L2)
    {
      cout << "TRUE." ;
    }
  else
    {
      cout << "FALSE.";
    }
  cout << endl;
  cout << "----------------------------------------------------" << endl << endl << endl;
  

  //L1 has 1,2,3 and L2 has 1,2
  cout << "CASE 5: " << endl ;
  cout << "Result:                                    ";
  L2.deleteRear(temp);
  if(L1 == L2)
    {
      cout << "TRUE." ;
    }
  else
    {
      cout << "FALSE.";
    }
  cout << endl;
  cout << "----------------------------------------------------" << endl << endl << endl;

  //L1 has 1,2,3 and L2 has 1,2,3,4
  cout << "CASE 6: " << endl ;
  cout << "Result:                                    ";
  L2.addRear(3);
  L2.addRear(4);
  if(L1 == L2)
    {
      cout << "TRUE." ;
    }
  else
    {
      cout << "FALSE.";
    }
  cout << endl;
  cout << "----------------------------------------------------" << endl << endl << endl;

  //L1 has 1,2,3 and L2 has 1,2,4
  cout << "CASE 6: " << endl ;
  cout << "Result:                                    ";
  L2.deleteRear(temp);
  L2.deleteRear(temp);
  L2.addRear(4);
  if(L1 == L2)
    {
      cout << "TRUE." ;
    }
  else
    {
      cout << "FALSE.";
    }
  cout << endl;
  cout << "----------------------------------------------------" << endl << endl << endl;


}
