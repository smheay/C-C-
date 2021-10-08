
#include "list.h"
using namespace std;
list::list(void)
{
  head = tail = NULL;
}

list::~list(void)
{
 
}


//Implement these three functions
//Add to the end of the LLL as efficiently as possible
int list::add(journal_entry & to_add)
{
           //Implement this function using the
           //journal entry functions we just wrote!


   int success;
   
   if(!head)
   {
       head = tail = new node;
       tail-> next = NULL;
       success = tail->entry.copy_entry(to_add); 
   }
   
   else
   {
       tail->next = new node;
       tail = tail -> next;
       tail -> next = NULL;
       success = tail->entry.copy_entry(to_add); 
   }
   
return success;
}

//Determine if there is a match with the title passed in
//and if so provide the matching journal entry back to the
//client program through the second argument.
//Return a zero if no match is found
int list::find(char matching_title[], journal_entry & found)
{
	//Your code goes here!           
  
  if(!head) return 0;
  
  node * current = head;
  bool success = false;
  while(current && !success)
  {
    success = current->entry.retrieve(matching_title, found);
  }
  
  return success;
}


//Display all journal entries
//Return false if there are no entries
int list::display(void)
{
         //Your code goes here!
  if(!head)return 0; 
       
 node * current = head;
 
 cout << " HELLO "<< endl;
 
 while(current)
 { 
   cout << current -> entry << endl;
   current = current -> next;
 }    

cout << " HELLO "<< endl;
return 1;
}


//Copy the list passed in as an argument
//and add the nodes to the end of the current list
int list::append(list & source)
{
 if(!source.head)return 0;
 
 node * current = source.head;
 bool success = 1;
 while(current && success)
 {
   success = add(current->entry);
   current = current -> next;
 }
 
 
        //Your code goes here!
return success;
}























