
#include "entry.h"
//Shannon Meyer

journal_entry::journal_entry(void)
{
  title = notes = NULL;
}
journal_entry::~journal_entry(void)
{
   if(title)
       delete [] title;
   if(notes)
       delete [] notes;
 
   title = notes = NULL;
}
int journal_entry::create_entry(char * title2, char * notes2)
{
  title = new char[strlen(title2) +1];
  strcpy(title, title2);
  
  notes = new char[strlen(notes2) +1];
  strcpy(notes, notes2);
}
int journal_entry::display(void)
{
  
}

//Step #7: Implement this function
//This function takes the argument and copies it into
//the journal's data members
int journal_entry::copy_entry(const journal_entry & copy_from)
{

       //Place your code here
   if(title)
       delete [] title;
   if(notes)
       delete [] notes;
 
   title = notes = NULL;
    
  if(copy_from.title)
  {
        title = new char[strlen(copy_from.title) +1];
        strcpy(title, copy_from.title);
  }
  if(copy_from.notes)
  {
        
        notes  = new char[strlen(copy_from.notes) +1];
        strcpy(notes, copy_from.notes);
  }
  
  return 1;
}



//Step #8: Implement this function
//This function will return non-zero if the title sent
//in as an argument matches the data member. It supplies
//the matching journal back as an argument
int journal_entry::retrieve(char * matching_title, journal_entry & found)
{

      //Place your code here 
    // avoid NULL pointers
    if(!title || !matching_title) return 0;
    
    if(found.title)
        delete [] found.title;
    if(found.notes)
        delete [] found.notes;
    found.notes=found.title = NULL;
    
    if(title)
    {
        found.title = new char[strlen(title) +1];
        strcpy(found.title, title);
    }
    if(notes)
    {
        found.notes = new char[strlen(notes) +1];
        strcpy(found.notes, notes);
    }
    
    
    
    return 0;//will be true when strcmp
}
























