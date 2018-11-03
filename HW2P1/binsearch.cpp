
//===========================================================
//HW#: HW2P1 analysis
//Your name: Enrique Alonso Esposito
//Complier:  g++
//File type: client program
//===========================================================

using namespace std;
#include <iostream>

/*
  ALGORITHM:
  Using binary search, the program goes through a previously established array of intergers and looks for a match witha user input.
  The function "binarySearch" checks the middle element of the array and does the following:
      -Match :  returns the position of the element.
      -Middle element < User Input :  adjust first bound. serches again.
      -Middle element > User Input :  adjust last bound. searches again.
      (recursively calls it self until one element is left or there is not matching elements)
     
*/


int binarySearch(int[], int, int, int); //binarySearch function prototype. Implemented after main.


int main()
{
 
  int n = 10;
  int loop = 1; // while this value == 1 the loop will keep being executed.
  int input; // holds the value entered by the user.
  int myFirst = 0; //holds the first slot of the array
  int myLast = n-1; //holds the last slot of the aray.
  
  int array[10] = { 1, 3, 5, 7, 9, 11, 13, 15, 17, 19 };

  
  //Welcome message.
  cout << "Welcome to the binary search program: " << endl;
  cout << "--------------------------------------" << endl;
  cout << endl;

  //User input of the number to be searched.
  cout << "Enter the number you are looking for: " ;
  cin >> input;
  cout << endl;


  int resultLoc = binarySearch(array, input, myFirst, myLast);

  if(resultLoc == -1)
    {
      cout << "User input: " << input << " was not found in the array. Try again. " << endl;
    }

  else
    {
      cout << "User input: " << input << " was found in position: " << resultLoc + 1 << endl;
    }
 


 return 0;
}


int binarySearch(int array[], int input, int myFirst, int myLast){
  
  int middle;

  middle = (myFirst+myLast)/2; //getting the position of the middle element.

  //Implementint the different cases.

  //If the input is = to the middle element then it is found so we return the position of the middle element.
  if(input == array[middle])
    {
      return middle;
    }

  //If the input is less than the middle element means it is in the first half. Adjusting bounds for future checking.
  else if(input < array[middle])
    {
      myLast = middle - 1; //First element doesn't change. Last bound is one less than the middle element (checking the first half).
    }
  
  //If the input is greater than the middle element means it is in the second half. Adjusting bounds for future checking.
  else if(input > array[middle])
    {
      myFirst = middle + 1; //Last element doesn't change. First bound is one greater thant the middle element (checking second half)
    }
  
  //If last == first means that the input wasn't found in the array. Returning -1.
  else if(myFirst == myLast)
    {
      cout << "User input: " << input << " was not found in the array. Try again. " << endl;
      return -1;
    }

  //calling the function recursively. It now uses the new bounds. 
  return binarySearch(array, input, myFirst, myLast);

}

      
