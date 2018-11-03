CS 311:   Data Structures and algorithms.  

</br>
</br>
</br>

<b>HW1:  </b>
//Purpose of the program: User enters a postfix operation to be solved and the program determines wheter or not the expression is valid and prints the result if it is.    
//Algorithm: There is a stack in which intergers are pushed, as soon as one operand is found the last two elements are popped and the result is calculated. The loop keeps going until there is no more intergers in the stack.    

</br>
</br>
<b>HW2P1:  </b>
 ALGORITHM:    
  Using binary search, the program goes through a previously established array of intergers and looks for a match witha user input.    
  The function "binarySearch" checks the middle element of the array and does the following:    
      -Match :  returns the position of the element.    
      -Middle element < User Input :  adjust first bound. serches again.    
      -Middle element > User Input :  adjust last bound. searches again.    
      (recursively calls it self until one element is left or there is not matching elements).   


</br>
</br>
<b>HW2P2:  </b>
//Program ALGORITHM:  

//Three vectors are declared. Along with a size and input variable.    
//We then ask for the sie of the vectors and for the elements that will be pushed into each vectors in a ascending order.    
//We push the elements into each vector.    
//The combine function is then called and we pass the vectors as well as the size to it.    
//This function will sort the elements as described below.    
//Lastly the result vector, once is sorted, is outputed.    


</br>
</br>
<b>HW3:  </b>
Linked Lists creation and manipulation.  

</br>
</br>
<b>HW4:  </b>
Binary Search Tree.  

</br>
</br>
<b>HW6:  </b>
Graphs.  

</br>
</br>
<b>HW7:  </b>
More graphs practice.    
//Purpose of the program: Read a graph stored ina text file and do a DFS.    
//Algorithm:    
//    -Data is read into an object (type dgraph) from the file.   
//    -We then initizialice a link list and a stack to hold adjacent values.    
//    -Then while there is something in the stack we pop elements from it.   
//        -We check the popped element in order to see if it has already been marked (visited).   
//        -If not (visit == 0) we mark it, find its adjacents and add them to the stack.   
//           (making sure we have previously removed the already marked vertex).   
//        -We also give the vertex a UNIQUE visit number.    
//        -Then we display the current Stack.    
//        -Once we have gone through all the verteces, we dislay the final graph after the DFS.    

