// Not fully working 
//Shannon Meyer
//CS 162




#include <iostream>
#include <cstring>
#include <cctype>
#include <fstream>
using namespace std;

//Place your structure definition here (globally):

const int COURSE = 8,  NAME = 30;

struct student
  {
  char firstName[NAME];
  char middleInt;
  char lastName[NAME];
  };
struct course
  {
  char courseDes[COURSE];
  int crn, sectionNum;
  };

//Place any prototypes that use the structure here:

void getStudent(student& aStudent);
void getCourse(course& aCourse);
void displayInfo(student& aStudent,  course& aCourse);
void writeOut(student& aStudent, course& aCourse);

int main()
{
     //Create a variable of the struct here:
  student aStudent;
  course aCourse;

     //Call the functions here:

  getStudent(aStudent);
  getCourse(aCourse);
  displayInfo(aStudent, aCourse);
  writeOut(aStudent, aCourse);

  char line[10];
  char delimiter;
  ifstream file_in;
  file_in.open("schedule.txt");
  
  if(file_in)
  {
    file_in.get(line, 10);
    {
    while(file_in && !file_in.eof())
     {
      delimiter = file_in.get();
      cout << line << delimiter;
     }
    }
  }
  file_in.close();
  file_in.clear();



 return 0;
}

//Implement the body of the functions here:
// GET NAME first middle last
void getStudent(student& aStudent)
{
  cout << "\nEnter your first name.\t" ;
  cin.get(aStudent.firstName, NAME, '\n');
  cin.ignore(100, '\n');

  cout << "\nEnter your middle initial.\t";
  cin >>aStudent.middleInt;
  cin.ignore(100, '\n');

  cout << "\nEnter your last name.\t";
  cin.get(aStudent.lastName, NAME, '\n');
  cin.ignore(100, '\n');
  
}

//GET COURSE INFO
void getCourse(course& aCourse)
{
  
  cout<< "\nEnter the course description.\t";
  cin.width(COURSE);
  cin >> aCourse.courseDes;
  cin.ignore(100, '\n');
  
  cout << "\nEnter the CRN.\t";
  cin >> aCourse.crn;
  cin.ignore(100, '\n');
  
  cout << "\nEnter the section number.\t";
  cin >> aCourse.sectionNum;
  cin.ignore(100, '\n');
}

//DISPLAY INFORMATION
void displayInfo(student& aStudent, course& aCourse)
{
  
 cout << "\nThe Student name is " << aStudent.firstName <<' '<< aStudent.middleInt<< ". " << aStudent.lastName<< endl;;
 cout << "The course description is " << aCourse.courseDes<< endl; 
 cout << "The CRN is " << aCourse.crn << endl;
 cout << "The section number is "<< aCourse.sectionNum<< endl;
}

//WRITE OUT INFORMATION
void writeOut(student& aStudent, course& aCourse)
{
  ofstream file_out;
  file_out.open("schedule.txt", ios::app);
  
  file_out << aStudent.firstName << ":" << aStudent.middleInt<< ":" << aStudent.lastName<< ":" <<endl;
  file_out << aCourse.courseDes<< ":" << aCourse.crn << ":" << aCourse.sectionNum << ":" << endl;
  
  file_out.close();
  file_out.clear();
}























