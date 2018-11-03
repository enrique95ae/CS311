
 ALGORITHM:  
  Using binary search, the program goes through a previously established array of intergers and looks for a match witha user input.  
  The function "binarySearch" checks the middle element of the array and does the following:  
      -Match :  returns the position of the element.  
      -Middle element < User Input :  adjust first bound. serches again.  
      -Middle element > User Input :  adjust last bound. searches again.  
      (recursively calls it self until one element is left or there is not matching elements). 
