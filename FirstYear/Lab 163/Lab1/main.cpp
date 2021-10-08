// Shannon Meyer
// CS 163 Program 1 
// Create an ADT for Pizza class

/*

struct topping         struct pizzaSTR            struct node
{                      {                          {
  char * toppingName;   char * pizzaName;          pizzaSTR aPizza;
  char * type;          topping topList          node * pizzaNext;
  float cost;          };                          node * topNext;   
};                                                };

*/

#include "class.h"

bool again();

int main() 
{
  pizza pizzaList;
  pizzaSTR buildPizza;
  
  char * search;
  int doAgain;
  int choice = 1;
  
  while(choice != 0)
  {
    cout << "\nEnter the choice\n\n"
         << "\n1: Add a pizza "
         << "\n2: Read out "
         << "\n3: Add topping "
         << "\n4: Read out all toppins for a pizza  \n" << endl;
         
    cin >> choice;
    cin.ignore(100,'\n');
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n" << endl;
    
    switch(choice)
    {
      case 1: do
              {
                /// fill struct with data
                cout <<"\nEnter pizza name" << endl;
                buildPizza.pizzaName = new char[SIZE];
                cin.get(buildPizza.pizzaName, SIZE, '\n'); cin.ignore(SIZE,'\n');
                
                // send to get copied
                // add to list
                if(pizzaList.addPizza(buildPizza))
                 cout << "\n Pizza added. " << endl;
                else 
                 cout << " \nPizza not added. " << endl;
                // delete
                if(buildPizza.pizzaName)
                  delete[]buildPizza.pizzaName;
                  
                }while(again());
              break;
      
      case 2: if(!pizzaList.displayAll())
                   cout << "\nThere is no pizza to display." << endl;
              break;
      
      case 3: /// fill struct with data
                cout <<"\nEnter pizza name" << endl;
                buildPizza.pizzaName = new char[SIZE];
                cin.get(buildPizza.pizzaName, SIZE, '\n'); cin.ignore(SIZE,'\n');
   
                cout <<"\nEnter top name" << endl;
                buildPizza.topList.toppingName = new char[SIZE];
                cin.get(buildPizza.topList.toppingName, SIZE, '\n'); cin.ignore(SIZE,'\n');
                
                if(pizzaList.addTopping(buildPizza))
                      cout << "\n Topping added. " << endl;
                else 
                      cout << " \ntop not added and pizza wasn't found. " << endl;
                 
                doAgain =(again());
                
                while(doAgain)
                  {
                    if(buildPizza.topList.toppingName)
                         delete [] buildPizza.topList.toppingName;
                  
                    cout <<"\nEnter top name" << endl;
                    buildPizza.topList.toppingName = new char[SIZE];
                    cin.get(buildPizza.topList.toppingName, SIZE, '\n'); 
                    cin.ignore(SIZE,'\n');
                    
                    if(pizzaList.addTopping2(buildPizza))
                      cout << "\n Topping added. " << endl;
                    else 
                      cout << " \ntop not added and pizza wasn't found. " << endl;
                      
                    doAgain =(again());
                   }
                 
                     
                if(buildPizza.pizzaName)
                  delete[]buildPizza.pizzaName;
                  
                if(buildPizza.topList.toppingName)
                  delete [] buildPizza.topList.toppingName;
                
                
                
              break;
      case 4: cout <<"\nEnter pizza name" << endl;
                buildPizza.pizzaName = new char[SIZE];
                cin.get(buildPizza.pizzaName, SIZE, '\n'); cin.ignore(SIZE,'\n');
              
              if(pizzaList.displayTopping(buildPizza))
                 cout << "\n Are the current toppings. " << endl;
              else
                 cout << " \nPizza wasn't found. " << endl;
                 
              if(buildPizza.pizzaName)
                  delete[]buildPizza.pizzaName;
   
              break;
      case 5: break;
      case 0: break;
    }
  }
 return 0;
}

// repeat code 
bool again()
{
  int again;
  cout << "\nWould you like to add another  1  or  0 " << endl;
  cin >> again;
  cin.ignore(100 , '\n');
  if(again == 1)
    return true;
  else
    return false;
}