//Shannon Meyer
//CS 162
//program 4

/*In A .h file we have the following constructs:
1. #includes
2. using namespace std;
3. Constants
4. Structures
5. Prototypes
6. Class Interface (NO IMPLEMENTATION OF FUNCTIONS)
*/

#include <iostream>
#include <cstring>
#include <cctype>
#include <fstream>
using namespace std;

//Manage a collection of data using a linear linked list 
class card
{
  public:
    card();             //constructor - initializes data members
    ~card();            //destructor - deallocate memory
    void readIn();
    void readOut();
    bool search(char array[]);
    void outputFile(char array[]);
    void inputFile(char array[]);
    void inputFile2(char array[]);
    void inputFile3(char array[]);
    /*
    void inputFile();
    void deleteFile();
    */
    
  private:
    char * name;
    char * descript;
    char * data;
};
