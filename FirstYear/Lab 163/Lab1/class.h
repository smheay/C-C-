/*
// Shannon Meyer
// CS 163 Program 1 
// Create an ADT for Pizza class

Information about topping

1. Name of the topping
2. Surcharge for the topping
3. The category Protien, vegie ect

This ADT must have public member functions to perform the following:

1.Constructor -Construct an object and initialize the data members
2.Destructor -Release all dynamic memory and reset data members to their zero equivalent value
3.Add a new type of Pizza (creating a new name for the pizza). The pizzas should be in sorted order by their name.
4.Remove a topping from a particular pizza
5.Add a topping for a particular pizza
6.Display all pizzas
7.Display just the toppings for a particular pizza

*/

#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;


const int SIZE = 100;
const int PREMADE = 6;
const int TOP = 10;

struct topping
{
  topping();
  ~topping();
  char * toppingName;
  char * type;
  float cost;
};

struct pizzaSTR
{
  char * pizzaName;
  topping topList;
};

struct node
{
  pizzaSTR aPizza;
  node * pizzaNext;
  node * topNext;
};


class pizza
{
  public: pizza();
          ~pizza();
          int addPizza(pizzaSTR & toAdd);
          int displayAll();
          int addTopping(pizzaSTR & toAdd);
          int addTopping2(pizzaSTR & toAdd);
          int displayTopping(pizzaSTR & toAdd);
  
  private: 
           void copyData(pizzaSTR & dest, pizzaSTR & source);
           void copyName(char * & dest, char * source);
           void copyTailData(pizzaSTR & dest, pizzaSTR & source);
           
           node * pizzaHead;
           node * pizzaTail;
           node * topHead;
           node * topTail;

};





























