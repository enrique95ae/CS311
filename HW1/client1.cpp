//=========================================================
//HW#: HW1P1 stack
//Your name: Enrique Alonso Esposito
//Complier:  g++
//File type: client program
//===========================================================

using namespace std;

#include <iostream>
#include <stdlib.h>
#include <string>
#include "stack.h"

//Purpose of the program: User enters a postfix operation to be solved and the program determines wheter or not the expression is valid and prints the result if it is.
//Algorithm: There is a stack in which intergers are pushed, as soon as one operand is found the last two elements are popped and the result is calculated. The loop keeps going until there is no more intergers in the stack.
int main()
{
  stack postfixstack;  // integer stack
  string expression;   // user entered expression
  
  cout << "type a postfix expression: " ;
  cin >> expression;
  
  int i = 0;  // character position within expression
  char item;  // one char out of the expression

  int result; //stores the result of the appropiated operation
  
  int box1;  // receive things from pop
  int box2;  // receive things from pop
  
  while (expression[i] != '\0')
    {
      try
	{
	  item = expression[i];  // current char
	  
	  if (item >= '0' && item <= '9')
	    {
	      postfixstack.push(item - 48);
	      postfixstack.displayAll();
	    }

	  
	  //3.  else if it is an operator,
	  //    pop the two operands (you might get Underflow exception), and
	  //	apply the operator to the two operands, and
	  //    push the result.
	  else if ( (item == '+') || (item == '-') || (item == '*'))
	    {
	      postfixstack.pop(box1);
	      postfixstack.pop(box2);
	      //cases for different operators follow:
	      if (item == '-') 
		{
		  result = box2-box1;
		}
	      else if (item == '+')
		{ 
		  result = box2 + box1;
		}
	      else if (item == '*')
		{
		  result = box1 * box2;
		}
	      
	      //after doing the appropiated operation we push it to the stack.
	      postfixstack.push(result);
	      //and then the whole stack is displayed.
	      postfixstack.displayAll();
	    }
	  else throw "invalid item";
	} // this closes try
      
      // Catch exceptions and report problems and quit the program now. 
      // Error messages describe what is wrong with the expression.
      catch (stack::Overflow) 
	{
	  cerr << " ERROR! Expression too long! " << endl;
	}
      catch (stack::Underflow) // for too few operands
	{
	  cerr << " ERROR! too few operands! " << endl;
	}
      catch (char const* errorcode) // for invalid item
	{
	  cerr << " ERROR! Invalid Expression. " << endl;
	}
      // go back to the loop after incrementing i
      i++;
    }// end of while
  
  // After the loop successfully completes: 
  // The result will be at the top of the stack. Pop it and show it.
  postfixstack.pop(result);
  cout << "The result is: " << result << endl;

  // If anything is left on the stack, an incomplete expression was found.
  // Inform the user.
  
  if ( postfixstack.isEmpty() == false)
    {
      cerr << " ERROR! Incomplete expression was found. "<< endl ;
    }

}// end of the program
