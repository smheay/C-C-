#include <iostream>
#include <cctype>   // toupper isalpha isdigit
#include <cstring>  // strlen, strcmpm strcpy
using namespace std;

//Shannon Meyer
// CS 162

bool is_it_upper(char test);
bool is_it_upper(char array[]);

int main ()
{
  char upper, array1[15];
  
    
  cout <<"\nType a letter " ;
  cin >> upper;
  cin.ignore(100, '\n');
  
  if(is_it_upper(upper) == true)
    cout << "\nTHE LETTER IS CAP TRUE";
  else
    cout << "\nTHE LETTER IS NOT CAP FALSE";
 
  cout <<"\nType an array of letters " ;
  cin.get(array1, 15, '\n');
  cin.ignore(100, '\n');


  if(is_it_upper(array1) == true)
    cout << "\nARRAY IS ALL UPPER TRUE";
  else
    cout << "\nNOTTTTT ALL UPPER FALSE";

return 0;
}
////////////////////////////////////////////////////////////
bool is_it_upper(char test){
  

  if(test >= 'A' && test <= 'Z')
    return true ;
  else
    return false; 
    
}

bool is_it_upper(char array[]){
  
  int temp;
  
  temp = strlen(array);

  cout << "\nTEMP = " << temp;
  
  for(int i = 0; i<temp; ++i)
  {
    if (is_it_upper(array[i])== false){
      i = 100;
      return false;}
  } 
return true;  
}


































