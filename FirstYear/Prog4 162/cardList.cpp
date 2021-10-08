//Shannon Meyer
//CS 162
//program 4
#include "cardList.h"


//Constructor initialize data members
Info_List::Info_List() 
{
  array = NULL;
  size = 0;
  numberInput = 0;
}
//Destructor, Destoyer of stuff
Info_List::~Info_List() 
{ 
  
  if (array != NULL)
    delete [] array;
  array = NULL;
  size = 0;
  numberInput = 0;
}
//Set a dynamic array and delete if another function call is made
void Info_List::set_size()
{
  int size_of_array;
  
  if (array != NULL)
    delete [] array;
    
  cout << "Enter the size of the array needed." << endl;
  cin >> size_of_array;
  cin.ignore(100, '\n');
    
  array = new card[size_of_array];
  size = size_of_array;
  numberInput = 0;        //very important to add reset
  cout << "\nThe array has the lenght of " << size << endl;
}
//Set a dynamic array and delete if another function call is made
void Info_List::set_size_file(int size_of_array)//sent from filein
{
  if (array != NULL)
    delete [] array;
  
  array = new card[size_of_array];
  size = size_of_array;
  numberInput = 0;
  cout << "\nThe array has the lenght of " << size << endl;
}
// fill the dynamic array will limit if statement
void Info_List::input()
{
  if(size == numberInput)
  {
    if(numberInput == 0)
    {
      cout << "The dynamic array is empty yo." << endl;
      return;
    }
    if(numberInput > 0)
    {
      cout << "The dynamic array is full yo." << endl;
      return;
    }
  }
  array[numberInput].readIn();
  ++numberInput;
}
// Display all the array of class of card
void Info_List::display_all()
{
  if (array == NULL)
    {
      cout << "\nThe array is empty, yo." << endl;
      return;
    }
  for (int i = 0; i < numberInput; ++i)
    array[i].readOut();
}
// Search card * array[name] with whatever is inputted from the user.
void Info_List::search_list()
{
  if (array == NULL)
    {
      cout << "\nThe array is empty, yo." << endl;
      return;
    }
    
  char * searchs;
  searchs = new char[30];
  int temp;
  
  cout << "\nEnter the name to search for."<< endl;
  cin.get(searchs, 29, '\n');
  cin.ignore(100, '\n');
  cout << "\nYou have entered. \""<< searchs << "\" "
       << "Let's see if there is a match.\t"<< endl;
  
  for (int i = 0; i < numberInput; ++i)
  { 
    temp = array[i].search(searchs);
    if (!temp)
     {
       cout << "\nMatch Found!"<< endl;
       array[i].readOut();
     }
  }
  
  if (searchs != NULL)
    delete [] searchs;
}      
//Save to a file appends to the end
void Info_List::output_file()
{
  char * filetowrite;
  filetowrite = new char[30];
  
  cout << "\nEnter the file to write to."<< endl;
  cin.get(filetowrite, 29, '\n');
  cin.ignore(100, '\n');
  
  ofstream fileOut;
  fileOut.open(filetowrite);
  
  for (int i = 0; i < numberInput; ++i)
  {
    array[i].outputFile(filetowrite);
    cout << "\nNumber of data inputted :\t" << i << endl;
  } 
    
  fileOut.close();
  fileOut.clear();

  if (filetowrite != NULL)
    delete [] filetowrite; 

}
// file input test file and see size to make an array
void Info_List::input_file()
{
  char * filetoread;
  filetoread = new char[30];
  
  int size = 0;
  
  cout << "\nEnter the file name."<< endl;
  cin.get(filetoread, 29, '\n');
  cin.ignore(100, '\n');
  
  
  ifstream file_in;
  file_in.open(filetoread);

  if(!file_in)
   {
    cout << "\nNo file found."<< endl;
    return;
   }
  else
  {
    file_in.ignore(100,'#');

    while(file_in && !file_in.eof())
    {
      file_in.ignore(100,'#');
      file_in.ignore(100,'#');
      file_in.ignore();
      ++size;
      file_in.ignore(100,'#');
    }
    
    file_in.close();
    file_in.clear();
  }
  
  cout << "\nSize = " << size;
  set_size_file(size);
  
  if (filetoread != NULL)
    delete [] filetoread; 
}

//Read from file to fill array
void Info_List::input_file2()
{
  char line[150];
  char * filetoread;
  
  filetoread = new char[30];
  
  cout << "\nEnter the file name."<< endl;
  cin.get(filetoread, 30, '\n');
  cin.ignore(100, '\n');
  
  
  ifstream file_in;
  file_in.open(filetoread);
  
  if(!file_in)
    {
    cout << "\nNo file found."<< endl;
    return;
   }
   
  if(size == numberInput)
    {
      cout << "The dynamic array is full yo." << endl;
      return;
    }
  else
  {
    file_in.get(line, 150,'#');
    file_in.ignore(100,'#');
    array[numberInput].inputFile(line);
      
    while(numberInput < size && file_in && !file_in.eof())
    {
      
      
      file_in.get(line, 150,'#');
      file_in.ignore(100,'#');
      array[numberInput].inputFile2(line);
      
      file_in.get(line, 150,'#');
      file_in.ignore(100,'#');
      array[numberInput].inputFile3(line);
   
      file_in.ignore();
      ++numberInput;
      cout << "\nNumber Arrays Filled = " << numberInput << endl;
      
      if(size == numberInput)
        {
        cout << "The dynamic array is full yo." << endl;
          return;
        }
      
      file_in.get(line, 150,'#');
      file_in.ignore(100,'#');
      array[numberInput].inputFile(line);
      
    }
    
    file_in.close();
    file_in.clear();
  }
  if (filetoread != NULL)
    delete [] filetoread; 
}



















