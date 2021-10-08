//Shannon Meyer
//CS 162
//External Data and structures

//Reads from file, saves to file, LLL practice


#include <iostream>
#include <cstring>
#include <cctype>
#include <fstream>
using namespace std;

//structures
const int NAME =41, DESCRIPT=201, DATA = 132, DATALIST = 30;

struct data_s
{
  char name[NAME];
  char descript[DESCRIPT];
  char data[DATA];
};

//PROTOTYPES
void readIn(data_s dataList[], int & count);//user read in
void readOut(data_s dataList[], int count); //loop to read out all entered info
void search(data_s dataList[], int count);
void outputFile(data_s dataList[], int count);
void inputFile(data_s dataList[], int & count);
void deleteFile(data_s dataList[]);


int main()
{
  data_s dataList[DATALIST];
  int count = 0, choice;

  do
  {
    cout << "\nFile Explorer\n\n";
    cout << "0 - Quit and save.\n";
    cout << "1 - Add information to save.\n";
    cout << "2 - Print all the information in order.\n";
    cout << "3 - Search information. (Case and Space Sensitive)\n";
    cout << "4 - Save to file.\n";
    cout << "5 - Read from a file.\n";
    cout << "8 - Delete file contents.\n\n";
    cout << "Choice: ";
    cin >> choice;
    cin.ignore(100, '\n');

    switch (choice)
    {
     case 0: cout << "Goodbye.\n";
      outputFile(dataList, count);
      break;
     case 1: readIn(dataList, count);
      break;
     case 2: readOut(dataList, count);
      break;
     case 3: search(dataList, count);
      break;
     case 4: outputFile(dataList, count);
      break;
     case 5: inputFile(dataList, count);
      break;
     case 8: deleteFile(dataList);
      break;
     default: cout << "\nSorry, but " << choice << " isn't a valid choice.\n";
      break;
    }
  }while (choice != 0);

return 0;
}
//DELETE file contents
void deleteFile(data_s dataList[])
{
  ofstream fileOut;
  fileOut.open("playlist.txt");
  fileOut.close();
  fileOut.clear();
}
//IFSTREAM READING A FILE
void inputFile(data_s dataList[], int & count)
{
  char line[DESCRIPT], delimiter;
  ifstream file_in;
  file_in.open("playlist.txt");

  if(!file_in)
    return;
  else
  {
    file_in.get(dataList[count].name, NAME, '#');
    file_in.ignore(100,'#');

    while(file_in && !file_in.eof())                          //Getting info and filling array with count as the start
    {
      file_in.get(dataList[count].descript, DESCRIPT, '#');   // will stop when array is full
      file_in.ignore(100,'#');
      file_in.get(dataList[count].data, DATA, '#');
      file_in.ignore(100,'#');
      file_in.ignore();
      ++count;
      if(count>=DATALIST-1)
      {
        cout << "\nThe program memory is full.";
        return;
      }
      file_in.get(dataList[count].name, NAME, '#');
      file_in.ignore(100,'#');
    }
    file_in.close();
    file_in.clear();
  }
}
//OFSTREAM WRITE TO A FILE
void outputFile(data_s dataList[], int count)
{
  ofstream fileOut;
  fileOut.open("playlist.txt");

  if(!fileOut)
    cout << "\nNOT IN  FILE";
  else
  {
    for(int i = 0 ; i < count; ++i)
    {
      cout << "\nNumber of data inputted :\t" << i;
      fileOut  << dataList[i].name << '#' 
               << dataList[i].descript << '#'
               << dataList[i].data << '#' <<endl;
    }
    fileOut.close();
    fileOut.clear();
  }
}
//SEARCH INFORMATION 
void search(data_s dataList[], int count)
{
  char search[NAME];
  
  cout << "\nEnter the name to search for."<< endl;
  cin.get(search, NAME, '\n');
  cin.ignore(100, '\n');
  
  for(int i = 0; i < count; ++i)
  {
   if(strcmp(dataList[i].name,search)== 0)
   {
    cout << "\nName        = " << dataList[i].name;
    cout << "\nDescription = " << dataList[i].descript;
    cout << "\nData        = " << dataList[i].data;
    cout << "\n\n\n\n";
   }
  }
}
//READ OUT DATA IN ARRAYS
void readOut(data_s dataList[], int count)
{
  for(int i = 0; i < count; ++i)
  {
   cout << "\nName        = " << dataList[i].name;
   cout << "\nDescription = " << dataList[i].descript;
   cout << "\nData        = " << dataList[i].data;
   cout << "\n\n\n\n";
  }
}
//READ IN TO ARRAY
void readIn(data_s dataList[], int & count) 
{
  char responce;
  int i = count;
  cout << "\nNumber of data in memory  = " << count;
  if(i>=DATALIST-1)
  {
    cout << "\nThe program memory is full.";
    return;
  }
  while(i < DATALIST)
  {
    cout << "\nEnter in the person, place or thing. With a limit of " << NAME << " characters.\n" ;
    cin.get(dataList[i].name, NAME, '\n');
    cin.ignore(100, '\n');

   cout << "\nEnter the description of what was entered. With a limit of " << DESCRIPT << " characters.\n";
   cin.get(dataList[i].descript, DESCRIPT, '\n');
   cin.ignore(100, '\n');

   cout << "\nEnter in the the data. With a limit of " << DATA << " characters. (password, website ect..)\n";
   cin.get(dataList[i].data, DATA, '\n');
   cin.ignore(100, '\n');

   ++i;
   count = i;

   cout << "Do you want to enter another? 'Y' or 'N' " << endl;
   cin >> responce;
   cin.ignore(100, '\n');

   if(toupper(responce) != 'Y')
    return;
  }
}





