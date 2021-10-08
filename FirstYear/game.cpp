//My Name : Shannon Meyer
//CS 162
//Program: Dice War - This is a game to play verse the computer that simulates playing War but with dice. 
//The goal is to play each round and get the highest roll. 
//The winner is the first to 10 points and is able to be replayed without exiting.

#include <iostream>
#include <cstdlib> 
#include <ctime>

using namespace std;

int main()
{
  int die1 , die2 , die3 , die4 ;
  int sum , sum2 , playerSum , compSum , war;
  char letter , letter2;
  
  playerSum = 0;
  compSum = 0;
  
  cout << "This game is called Dice Wars. The Player will roll two dice against the Computer"
       << " and the highest combined roll wins." 
       << "The scoreing is as follows, \n \n Normal Win = Highest Roll 1 point awarded."
       << "\n\n Double Win = Two of the same number was rolled 2 points are awarded."
       << "\n \n War = A tie between the players and will roll again for a winner and 3 points are awarded."
       << "\n \t If there is another tie 3 additional points will be awarded. \n\t "
       << "Also, if the winner rolled doubles 4 points are awarded.  \n"
       <<  endl; 
  
  while ((compSum <=9) & (playerSum <= 9))
   { 
    while (letter != 'p')            // repeats till p is entered
      {
       cout << " \n To play a round of Dice Wars press p key once and enter." << endl;
       cin >> letter;
       cin.ignore(100,'\n');
       cout << endl;
      }
    
    srand(time(NULL));               // used to generate different numbers
    die1 = rand() % 6 + 1;        // add 1 so the numbers 1-6 appear and not 0-5
    die2 = rand() % 6 + 1;
    die3 = rand() % 6 + 1;      
    die4 = rand() % 6 + 1;
    
    sum = die1 + die2;
    cout << "The player has rolled a "<< endl;
    cout << die1 << " and " << die2 << " for a total of \n\t\t\n" << sum << "\n" << endl;
  
    sum2 = die3 + die4;
    cout << "The Computer has rolled a "<< endl;
    cout << die3 << " and " << die4 << " for a total of \n\t\t\n" << sum2 << "\n" << endl;
    
        
    if(sum > sum2)                         // see who wins the round and adds point system
        if (die1 == die2)
          playerSum = playerSum + 2 ;
        else
          playerSum = playerSum + 1 ;
    if(sum2 > sum)
        if (die3 == die4)
        compSum = compSum + 2 ;
        else
        compSum = compSum + 1 ;
    
    war = 0;
    while (sum == sum2)                   // WARRRRRR +  point counter and reroll 
     {
      letter = 'o' ;                      // need to reset p use 'p' to roll dice
      while (letter != 'p')              // repeats till p is entered
       {
        cout << "THIS IS WARRRRRR press p key once to play and then enter." << endl;
        cin >> letter;
        cout << endl;
       }
      
      srand(time(NULL));              
      die1 = rand() % 6 + 1;        
      die2 = rand() % 6 + 1;
      die3 = rand() % 6 + 1;      
      die4 = rand() % 6 + 1;
      
      sum = die1 + die2;
      cout << "The player has rolled a "<< endl;
      cout << die1 << " and " << die2 << " for a total of \n\t\t\n" << sum << "\n" << endl;
  
      sum2 = die3 + die4;
      cout << "The Computer has rolled a "<< endl;
      cout << die3 << " and " << die4 << " for a total of \n\t\t\n" << sum2 << "\n" << endl;
      
      war = war + 3;
      
      if (sum >sum2)
        if (die1 == die2)
        playerSum = war + playerSum + 1;
        else
        playerSum = war + playerSum;
        
      if (sum2 > sum)
        if (die3 == die4)
        compSum = war + compSum + 1;
        else
        compSum = war + compSum;
     }

    letter = 'o' ;  // need to reset p use 'p' to roll dice
    
    cout << "The players score is " << playerSum << endl;
    cout << "The compters score is " << compSum << endl;
    
    letter2 = 'o';
    // ASK THE PLAYER TO REPLAY OR QUIT
    if ((compSum >9) | (playerSum>9))
        while ((letter2 != 'y' ) && (letter2 != 'n'))
        {
        cout << "\nWould you like to play agian? Press 'y' to play again and 'n' to exit and then press enter" << endl;
        cin >> letter2;
        cout << endl;
        if (letter2 == 'y') // IF YES the scores reset and restart loop
          {
          playerSum = 0;
          compSum = 0;}
        if (letter2 == 'n') // If NO the game quits
         {
          playerSum = playerSum;
          compSum = compSum;}
        }
        
        
  
   }
  
  return 0;
}






















