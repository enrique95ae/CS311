//HW2P2
//Name: Enrique Alonso Esposito
//Compiler Used: g++
//File type: client file

#include <iostream>
#include <vector>
using namespace std;


//Program ALGORITHM:

//Three vectors are declared. Along with a size and input variable.
//We then ask for the sie of the vectors and for the elements that will be pushed into each vectors in a ascending order.
//We push the elements into each vector.
//The combine function is then called and we pass the vectors as well as the size to it.
//This function will sort the elements as described below.
//Lastly the result vector, once is sorted, is outputed.

//Function prototype
void Combine(vector<int> , vector<int> , vector<int> &, int);


main()
{

  //Used variables
  int size = 0;   //size of the input vectors
  int input;      //user input that will be checked and pushed into the vector

  //Vectors declaration
  vector <int> L1;// user input 1 (A)
  vector <int> L2;// user input 2 (B)
  vector <int> L3;// result / output (R)


  cout << "Enter the number of elements for the lists: ";
  cin >> size;
  cout << endl;

  for (int i = 0; i < size; i++) //This loop will ask for user inputs as many times as the size the user previously entered.
    {
      cout << "Enter integers in ascending order: ";
      cin >> input;

      L1.push_back(input); //pushing into vector 1
    }

  cout << endl;
  cout << "Inputs for the second list." << endl;
  cout << endl;

  for (int i = 0; i < size; i++) //This loop will ask for user inputs as many times as the size the user previously entered.
    {
      cout << "Enter integers in ascending order: ";
      cin >> input;

      L2.push_back(input); //pushing into vector 2
    }

  cout << endl;
  Combine(L1, L2, L3, size); //calling the combine function and passing the vectors to it.
  cout << endl;

  //printing the result vector L3.
  for(int i = 0; i < L3.size(); i++)
    {
      cout << L3[i] << " ";
    }
}


//Combine function ALGORITHM.
//This function receives three vectors and the size of the first two as an int.
//First we establish an index int for each vector and set it to 0.
//We then compare each to the size of the vectors if both are different it means that there is still elements in the vectors (since we initialized the indexes to 0).
//Then the function is divided in 2 phases:
//PHASE 1.
//Starting at the beginning of each vector we compare the elements.
//The smallest one of each comparison goes into the result vector.
//The other element remains in the vector L1 or L2.
//Repeat until there is no more elements in the vectors.
//STEP 2.
//Once all the elements have been compared it means that the result vector has the first half of the elements already sorted.
//Other half is still in either vector L1 or vector L2.
//We now check which vector has the elements and since they are already sorted we directly add it to the result vector.




void Combine(vector<int> L1, vector<int> L2, vector<int> &L3, int size) //This function receives the three vectors and the size of the first 2.
{
  int index1 = 0, index2 = 0, index3 = 0;

  //STEP 1.
  //Starting at the beginning of each vector we compare the elements.
  //The smallest one of each comparison goes into the result vector.
  //The other element remains in the vector L1 or L2.
  //Repeat until there is no more elements in the vectors.

  while(index1 != size && index2 != size) //comparing size and indexes to check if there is elements left
    {
      if(L1[index1] < L2[index2]){ //This if statement compares which element is smallest and so which element has to be added to the result vector first.
	L3.push_back(L1[index1]); cout << "comparison" << endl; //adding the smallest element into the result vector and displaying "comparison".
	index1++;
      }else{
	L3.push_back(L2[index2]); cout << "comparison\n" << endl; //adding the smallest element into the result vector and displaying "comparison".
	index2++;
      }

      index3++;
    }


  //STEP 2.
  //Once all the elements have been compared it means that the result vector has the first half of the elements already sorted.
  //Other half is still in either vector L1 or vector L2.
  //We now check which vector has the elements and since they are already sorted we directly add it to the result vector.


  //Checking vector L1
  if(L1.size() != index1)
    {
      while(L1.size() != index1){
	L3.push_back(L1[index1]);
	index1++;
	index3++;
      }
    }

  //Checking vector L2
  else if (L2.size() != index2)
    {
      while(L2.size() != index2){
	L3.push_back(L2[index2]);
	index2++;
	index3++;
      }
    }
}
