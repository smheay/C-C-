// 8/19/2021
// Yup




//Shannon Meyer
//CS 162
//program 4
//I was intending this program to be able to make dynamically allocated arrays
//and to read into those arrays from files or manually. 
//The cardList.h will make a dynamic array for the class card. and then 
// the functions will edit that array from there. 

//The program will create a dynamic array, add to the end of an array, 
//search it and use files to store and read the information entered. 

//while writing out the program I was intenteding for it to be able to store 
//information for the card game hearthstone hence why the class was called cards 
//but I added the password class object part just to show how I would expand 
//for more classes even though one class would be able to have mulitple different topics
//after saving and creating a new array.


#include "cardList.h"
void callPasswordList(Info_List & passwordList);
void callCardList(Info_List & cardList);


int main()
{
  Info_List cardList;
  Info_List passwordList;
  
  int choice;
  
  do
  {
    cout << "\nClass Lists\n\n";
    cout << "0 - Quit.\n";
    cout << "1 - Add cards to the card list.\n";
    cout << "2 - Add to the password list.\n";
    cout << "\n\n\n\n\n\n\n\n\n\n";
    cout << "Enter Choice: ";
    cin >> choice;
    cin.ignore(100, '\n');

    switch (choice)
    {
     case 0: cout << "Goodbye.\n";
      break;
     case 1: callCardList(cardList);
      break;
     case 2: callPasswordList(passwordList);
      break;

     default: cout << "\nSorry, but " << choice << " isn't a valid choice.\n";
      break;
    }
    
  }while (choice != 0);

return 0;
}
void callCardList(Info_List & cardList)
{
  
  
  int choice;
  
  do
  {
    cout << "\nCard List\n\n";
    cout << "0 - Quit.\n";
    cout << "1 - Add to the list.\n";
    cout << "2 - Print all the information in order.\n";
    cout << "3 - Search information. (Case and Space Sensitive)\n";
    cout << "4 - Save to file.\n";
    cout << "5 - Read from a file and make a Dynamic Array for its size.\n"
         << "    Do this to first then 6 to only work with information in the file." << endl;
    cout << "6 - Read from a file and fill a Dyanmic Array.\n";
    cout << "8 - Enter in the size of the array needed.(WILL DELETE CURRENT ARRAY) \n\n\n\n\n\n\n\n\n\n";
    cout << "Enter Choice: ";
    cin >> choice;
    cin.ignore(100, '\n');

    switch (choice)
    {
     case 0: cout << "Goodbye.\n";
      break;
     case 1: cardList.input();
      break;
     case 2: cardList.display_all();
      break;
     case 3: cardList.search_list();
      break;
     case 4: cardList.output_file();
      break;
     case 5: cardList.input_file();
      break;
     case 6: cardList.input_file2();
      break;
     case 8: cardList.set_size();
      break;
     default: cout << "\nSorry, but " << choice << " isn't a valid choice.\n";
      break;
    }
    
  }while (choice != 0);
}
void callPasswordList(Info_List & passwordList)
{
  int choice;
  
  do
  {
    cout << "\nPassword List\n\n";
    cout << "0 - Quit.\n";
    cout << "1 - Add to the list.\n";
    cout << "2 - Print all the information in order.\n";
    cout << "3 - Search information. (Case and Space Sensitive)\n";
    cout << "4 - Save to file.\n";
    cout << "5 - Read from a file and make a Dynamic Array for its size.\n"
         << "    Do this to first then 6 to only work with information in the file." << endl;
    cout << "6 - Read from a file and fill a Dyanmic Array.\n";
    cout << "8 - Enter in the size of the array needed.(WILL DELETE CURRENT ARRAY) \n\n\n\n\n\n\n\n\n\n";
    cout << "Enter Choice: ";
    cin >> choice;
    cin.ignore(100, '\n');

    switch (choice)
    {
     case 0: cout << "Goodbye.\n";
      break;
     case 1: passwordList.input();
      break;
     case 2: passwordList.display_all();
      break;
     case 3: passwordList.search_list();
      break;
     case 4: passwordList.output_file();
      break;
     case 5: passwordList.input_file();
      break;
     case 6: passwordList.input_file2();
      break;
     case 8: passwordList.set_size();
      break;
     default: cout << "\nSorry, but " << choice << " isn't a valid choice.\n";
      break;
    }
    
  }while (choice != 0);
}





