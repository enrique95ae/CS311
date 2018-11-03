//INSTRUCTION
//Look for ** to complete all of them
//The output should match my assingment sheet

//=========================================================
//HW#: HW3P3 slist
//Your name: Enrique Alonso Esposito
//Complier:  g++
//File type: client program (tester)
//===========================================================

using namespace std;
#include <iostream>
#include "slist.h"

//PURPOSE: This function simply tests the copy constructor of the slist class
//and adds 6 to a the rear of copiedList and displays the list
//PARAMETER: list passed by value becomes copiedList
void CopyTest(slist copiedList)
{
  cout << "in copy test" << endl;
  
  copiedList.addRear(6);
  copiedList.displayAll();

  cout << "finished" << endl;
}


//PURPOSE of the Program: **
//Algorithm/Design: **
int main()
{
  slist L1, L2;
  int temp;
  int counter = 1;

 //1.Create a 5 element list with  1,2,3,4,5 (L1)
  cout << counter << endl; counter++;
  for(int i = 1; i < 6; i++) 
    {
      L1.addRear(i);
    }
  cout << endl;
  //2.Pass the list to a client function called CopyTest to 
  //test your copy constructor.
  cout << counter << endl; counter++;
  CopyTest(L1);
  cout << endl;

  cout << "-- After copytest --- " << endl;
  //3.Display L1 (this should still be a 5 element list)
  cout << counter << endl; counter++;
  L1.displayAll();
  cout << endl;

  cout << "-- Testing operator overloading ---" << endl;

  //4.Do L1 = L1;
  cout << counter << endl; counter++;
  L1 = L1;
  cout << endl;

  //5.Display L1    (this should still be 1 2 3 4 5)
  cout << counter << endl; counter++;
  L1.displayAll();
  cout << endl;

  //6.Create a 4 element list L2 with 7,8,9,10.
  cout << counter << endl; counter++;
  for(int k = 7; k < 11; k++) 
    {
      L2.addRear(k);
    }
  cout << endl;

  //7.Display L2
  cout << counter << endl; counter++;
  L2.displayAll();
  cout << endl;

  //8.Do L2 = L1;  (L2 becomes 5 elements 1,2,3,4,5)
  cout << counter << endl; counter++;
  L2 = L1;
  cout << endl;

  //9.Display L2.
  cout << counter << endl; counter++;
  L2.displayAll();
  cout << endl;

  //10.Remove a rear node from L1. (This should not affect L2).
  cout << counter << endl; counter++;
  L1.deleteRear(temp);
  cout << endl;

  //11.Display L1.   (L1 is 1,2,3,4)
  cout << counter << endl; counter++;
  L1.displayAll();
  cout << endl;

  //12.Display L1 again. (4 elements . just to make sure)
  cout << counter << endl; counter++;
  L1.displayAll();
  cout << endl;

  //13.Display L2 again. (still 5 elements 1,2,3,4,5)
  cout << counter << endl; counter++;
  L2.displayAll();
  cout << endl;

 }//end of program

