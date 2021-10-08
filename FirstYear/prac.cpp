// Shannon Meyer
// CS 162
// This is practice



#include <iostream>
#include <cctype>
using namespace std;

int number1, number2 , x;
char initial1, initial2, initial3;

int main() 
{
  cout << "enter initials three letters" << endl;
  cin >> initial1 >> initial2 >> initial3 ;
  cout << "you have entered " << initial1 << initial2 << initial3 << endl;
  
  
  if (initial3 > initial2)
    
    number1 = false;
  
  cout << number1 << endl;
}


 
/*
 
  cout << "Type in a letter" << endl;
  cin  >> repeat;
  cout << "\n\n\nThis is what you entered " << repeat << endl;

 if (isupper(repeat))
    cout << "Entered a CAP \n\t\t" << repeat << endl;
 if (islower(repeat))
    repeat = toupper(repeat);
 
 cout << repeat << " is the Entered value " << endl;
 
 if (repeat == 'A' || repeat == 'F' )
  cout << repeat << " = A " << endl;

 if (repeat>= 'A' && repeat <= 'F' && repeat != 'E')
  cout << repeat << "  >= A and <=F but not E  " << endl;
  
 cout << "enter a grade value" << endl;
 cin  >> grade;
 cout << endl;
 
  while (islower(grade))
   {
    cout << "you have entered " << grade << " and this is an invalid option. Please enter a A, B, C, D, or F. " << endl;
    cin >> grade ;
    cout << endl;
   }
  
  

  cout << "Type in a whole number" << endl;
  cin  >> number1;
  cout << endl;
  
  cout << "Type in another whole number" << endl;
  cin >> number2;
  cout << endl;
  
  if (number1 > number2)
    cout << "This is the highest number : " << number1 << endl;
  if (number2 > number1)
    cout << "This is the highest number : " << number2 << endl;
  if (number1 == number2)
    cout << "The numbers are eqaul" << endl;
  
  do
    {
     cout << "Would you like to enter another two numbers 'y' for yes 'n' for no? " << endl;
     cin  >> repeat ;
     if (repeat != 'y' && repeat != 'n')
      cout << "Enter a 'y' for yes and 'n' for no" << endl;
    } while (repeat != 'y' && repeat != 'n');


  cout << "Enter a lot of stuff" << endl;
  cin  >> input1 ;
  cout << "This was the input" << input1 << endl;
*/







