// Seems to have been practice with making functions and calling with to upper

#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;


//Here is an example of a constant; constants should
//be global so that they are accessible by all functions
//and there are no "side effects" unlike with global
//variables (which should be avoided!)
const int SIZE = 21;

void cap(char[]);



int main()
{
  char fullName[SIZE], major[SIZE], response;
  int count;
  
  do{ 
    cout << "Please enter your full name" << endl;
    cin.get(fullName,21,'\n');
    cin.ignore(100, '\n');
    cout << "You have entered " << fullName << "\nIs this correct 'Y' or 'N' ?" << endl;
    cin >> response ;
    cin.ignore(100, '\n');
    response = toupper(response);
    fullName[0] = toupper(fullName[0]);
  }while ('Y' != response);

  cap(fullName);
  
  cout << "\nFullName is now = " << fullName << endl;
  
  
  

  
  
  
return 0;  
}


void cap(char array [])


{
  int up , temp = strlen(array);
  
  for(int i = 0; i < temp; ++i)
  {
    up = i + 1;
    if(array[i] == char(32))
      array[up] = toupper(array[up]);
    if (i == 21)
      cout << "YOU HAVE GONE TOOO FAR " << endl;
  }



}






















