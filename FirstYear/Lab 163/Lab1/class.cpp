#include "class.h"


topping::topping()
{
  toppingName = NULL;
  type = NULL;
  cost = 0.0;
}

topping::~topping()
{
  
}

pizza::pizza()
{
  pizzaHead = pizzaTail =  NULL;
  topHead = topTail = NULL;
}
//
//
//
pizza::~pizza()
{

}
//
//
//Adds a pizza to the list 
int pizza::addPizza(pizzaSTR & toAdd)
{
  
    node * current;
    
    node * temp = new node; 
    temp->pizzaNext = NULL;
    temp->topNext = NULL;
    
    copyData(temp->aPizza, toAdd);
    
    if (!pizzaHead) 
    {//empty list set to same spot and data
       pizzaHead = pizzaTail = temp;
    }
    else if (strcmp(temp->aPizza.pizzaName,pizzaHead->aPizza.pizzaName) <=0)
    {//non empty list add start
       current = pizzaHead;
       pizzaHead = temp;
       pizzaHead->pizzaNext = current;
    }
    else if (strcmp(temp->aPizza.pizzaName,pizzaTail->aPizza.pizzaName) >= 0)
    {//non empty list add end
       current = pizzaTail;
       pizzaTail = temp;
       current->pizzaNext = pizzaTail;
    }
    else 
    { //traverse to insert in sorted order
        current = pizzaHead->pizzaNext;
        node * previous;
        
        while (current && strcmp(temp->aPizza.pizzaName, current->aPizza.pizzaName) > 0)
        { //while not null and find just the right spot
           previous = current;
           current = current->pizzaNext;
        }
        if (current) 
        { //not null just the right spot
            previous->pizzaNext = temp;
            temp->pizzaNext = current;
        }
        else return 0; 
      }

  return 1;
}
//
//
//
int pizza::displayAll()
{
  if(!pizzaHead)
     return 0;
     
  node * current = pizzaHead;
  
  while(current) // self test
  {
    cout << current->aPizza.pizzaName << "\n";
    current = current->pizzaNext;
  }
    return 1;
}
//Copy the data
void pizza::copyData(pizzaSTR & dest, pizzaSTR & source)
{

     copyName(dest.pizzaName, source.pizzaName);

}
//
//
//

void pizza::copyTailData(pizzaSTR & dest, pizzaSTR & source)
{

     copyName(dest.topList.toppingName, source.topList.toppingName);
     
}

void pizza::copyName(char * & dest, char * source)
{

     if (source)
     {
        dest = new char[strlen(source) +1];
        strcpy(dest,source);
    }
}
int pizza::addTopping(pizzaSTR & toAdd)
{  
    topHead = NULL;
    topTail = NULL;
    
    node * temp; 
    temp->pizzaNext = NULL;
    temp->topNext = NULL;
    
    copyData(temp->aPizza, toAdd);
    copyTailData(temp->aPizza, toAdd);
    
    cout << "\nAfter copyData " << temp->aPizza.pizzaName << endl;
    cout << "\nafter copyData " << temp->aPizza.topList.toppingName << endl;

    node * current = pizzaHead;
    
    while(current != NULL)
    {
       if(strcmp(temp->aPizza.pizzaName, current->aPizza.pizzaName) == 0)
          {
            cout << "\nFound a match " << temp->aPizza.pizzaName << endl;
            current->topNext = new node;
            current->topNext = temp;
            cout << "\nFdata " << current->topNext->aPizza.topList.toppingName << endl;
            current = pizzaTail;
          }
       current = current->pizzaNext;

    }
    
  
  topHead = topTail = temp;
   
  return 1;
 
}


int pizza::addTopping2(pizzaSTR & toAdd)
{
    node * temp; 
    temp->pizzaNext = NULL;
    temp->topNext = NULL;
    
    copyTailData(temp->aPizza, toAdd);
    cout << "\nTEST" << endl;
    
    topTail-> topNext = new node;
    temp = topTail-> topNext;
    topTail = temp;
    
    return 1;

}

int pizza::displayTopping(pizzaSTR & toAdd)
{

    node * temp; 
    
    copyData(temp->aPizza, toAdd);
    
    cout << "\nAfter copyData " << temp->aPizza.pizzaName << endl;

    node * current = pizzaHead;
    
    while(current != NULL)
    {
      current = current->pizzaNext;
      if(strcmp(temp->aPizza.pizzaName, current->aPizza.pizzaName) == 0)
          {
            cout << "\nFound a match " << temp->aPizza.pizzaName << endl;
            topHead = current-> topNext;
          }
      
    }
    
    while(topHead)
    {
      cout << topHead->aPizza.topList.toppingName << "  " ;
      topHead = topHead->topNext;
    }
    
}































