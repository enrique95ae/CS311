// =====================================
// HW# HW3P3 
// Your Name: Enrique Alonso Esposito
// Compiler: g++
// File Type: header file
//======================================

#include "llist.h"

//slist class inherits from llist
class slist: public llist
{
 public:
   
  
  slist(); //CONSTRUCTOR. Creates an empty llist.

  slist(const slist&); //COPY CONSTRUCTOR

  slist& operator=(const slist&);//makes one list the same as some other list.

  bool operator==(const slist&); //checks if two lists are equal.

  int search(el_t); //searches through one list to find the parameter sent.

  void replace(el_t, int); // Replaces the value of the node sent with the second parameter sent.

};

  
