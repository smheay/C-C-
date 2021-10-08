//Shannon Meyer
//CS 162
//program 4

#include "class.h"

//constructor - initializes data members
card::card() 
{
  name = NULL;
  descript= NULL;
  data = NULL;
  /*
  name[NAME];
  descript[DESCRIPT];
  data[DATA];
  */
}
//destructor - deallocate memory
card::~card()
{
  if (name != NULL)
    delete [] name;
  name = NULL;
  if (descript != NULL)
    delete [] descript;
  descript = NULL;
  if (descript != NULL)
    delete [] data;
  data = NULL;
  
}

//READ IN TO ARRAY
void card::readIn() 
{
  if (name != NULL)
    delete [] name;
  name = NULL;
  if (descript != NULL)
    delete [] descript;
  descript = NULL;
  
  char temp[100];
  char temp2[100];
  char temp3[100];
 
  cout << "\nEnter the name.";
  cin.get(temp, 100, '\n');
  name = new char [strlen(temp) + 1];
  strcpy(name, temp);
  cin.ignore(100, '\n');
  
  cout << "\nEnter in the text.";
  cin.get(temp2, 100, '\n');
  descript = new char [strlen(temp2) + 1];
  strcpy(descript, temp2);
  cin.ignore(100, '\n');
  
  cout << "\nEnter in the data.";
  cin.get(temp3, 100, '\n');
  data = new char [strlen(temp3) + 1];
  strcpy(data, temp3);
  cin.ignore(100, '\n');
}
//DISPLAY CARDS
void card::readOut()
{
  if (name != NULL) //if (name)
    cout << "\nName        = " << name;
    cout << "\nDescription = " << descript;
    cout << "\nData        = " << data;
    cout << "\n\n\n\n";
}
//SEARCH
bool card::search(char array[])
{
 if (name != NULL) //if (name)
   return strcmp(name, array);
 else return false;
}

//file out 
void card::outputFile(char array[])
{
  ofstream fileOut;
  fileOut.open(array, ios::app);
  
  if (name != NULL) //if (name)
    fileOut << name << '#' << descript << '#' << data << '#' <<endl;
  
}
// FILL ARRAY FROM FILE/////////////////////
void card::inputFile(char array[])
{
  ifstream file_in;

  name = new char [strlen(array) + 1];
  strcpy(name, array);
}
////////////////////////////////////////////
void card::inputFile2(char array[])
{
  ifstream file_in;
  
  descript = new char [strlen(array) + 1];
  strcpy(descript, array);
}
/////////////////////////////////////////////
void card::inputFile3(char array[])
{
  ifstream file_in;
  
  data = new char [strlen(array) + 1];
  strcpy(data, array);
  
}














