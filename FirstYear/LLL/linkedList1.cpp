#include <iostream>
#include <cstring>
#include <cstdlib>
#include <iomanip>





using namespace std;

struct node 
{
    int data;     // The LLL diagram is DATA * next---> JUST ONE
    node * next;  // variables DATA, NEXT, HEAD can all be whatever it is named 
};                 

class list
{
  public:
          list(); //contructor
          ~list(); //destructor
          void makeLLL();
          void realAllOut();
          void realAllOut(node * toRead);
          void firstAndLast();
          void deleteLast();
          int deleteLast(node *& head);
          void addToStart();
          void deleteANumber();
          void copyToNew();
          void deleteALL();
          void addAfterFirst();
          int countheadtimes();
          struct node * copyList();
          void copyList(node * head, node *& copy);
          
          

  private:
        node * head;  // HEAD is the start of a LLL making a structure of 1 node
        node * current;   // The class makes LLL of structures "node"
};                       // LLL diagram of class is (AFTER function makeLLL)
                         //        NODE1          NODE2          NODE3          NODE4
                         // HEAD-->DATA*next--->  DATA*next--->  DATA*next--->  DATA*next--->
                         //     CURRENT=╝ current->next=╝...

int main()
{
  node * current2 = NULL;
  
  list my_list;  // Making an object of the class list
  int choice;
  
  my_list.makeLLL();
      cout << "\nThis is the LLL filled with 7 random numbers." << endl;
      my_list.realAllOut();
  do
  {
    cout << "\nLLL\n\n";
    cout << "0 - Quit.\n";
    cout << "1 - Make a new list.\n";
    cout << "2 - read first and last.\n";
    cout << "3 - delete last number.\n";
    cout << "4 - add to start.\n";
    cout << "5 - delete a number.\n";
    cout << "6 - copy.\n";
    cout << "7 - delete all.\n";
    cout << "Choice: ";
    cin >> choice;
    cout << "\n";
    cin.ignore(100, '\n');
    
  switch (choice)
   {
    case 1:  my_list.makeLLL();
               cout << "\nThis is the LLL filled with 7 random numbers." << endl;
               my_list.realAllOut();
               
               break;
  
    case 2:  my_list.firstAndLast();
               break;
    case 3:  my_list.deleteLast();
               cout << "\nThis is the LLL now." << endl;
               my_list.realAllOut();
               break;
    case 4:  my_list.addToStart();
               cout << "\nThis is the LLL now with a number added to start." << endl;
               my_list.realAllOut();
               break;
    case 5:  my_list.deleteANumber();
               cout << "\nThis is the LLL now with entered number deleted." << endl;
               my_list.realAllOut();
               break;
    case 6:  current2 = my_list.copyList();
               cout << "\nIs the original list." << endl;
               my_list.realAllOut();
               cout << "\nIs the copy list." << endl;
               my_list.realAllOut(current2);
               break;
    case 7:  my_list.deleteALL();
               cout << "\nDelete." << endl;
               my_list.realAllOut();
               break;
    case 8:  int sdas = 0;
              sdas = my_list.countheadtimes();
             cout << sdas;
             break;
   }
  }while (choice != 0);
  
  
return 0;  
}
int list::countheadtimes()
{
  node * temp = head;
  int count = 0;
  while(temp->next)
  {
    if(temp->data == head->data)
       ++count;
    temp = temp->next;
    
  }
  
  return count;
}

int addList(node * head)
{
  if(!head)
    return 0;
    
  if(head->next != NULL)
     addList(head->next);
     
  return head->data += head->data;
}

// 
void list::addAfterFirst()
{
  if (!head)
    return;
  
  node * temp;
  temp = new node;
  int number;
  
  cout << "\nEnter number." << endl;
     cin >> number;
     cin.ignore(100, '\n');

  if(head-> next == NULL)
   {
     head -> next = temp;
     temp -> next = NULL;
     temp-> data = number;
   }
  
  
  temp = head-> next;
  head -> next = temp;
  temp ->data = number;
  
}
//delete all
void list::deleteALL()
{
  if(!head)
  {
    cout << "\nThere is no list!!" << endl;
    return;
  }
  
  node * current = head;
  
  while(head)
  {
    current = head -> next;
    delete head;
    head = current;
  }
  
  cout << "\nHead after delete!!" << head << endl;
}
//copy one list info into another new LLL
void list::copyToNew()
{
  if(!head)
  {
    cout << "\nThere is no list!!" << endl;
    return;
  }

  node * newNode, *last, *head2;
  node * current = head;
  
  int number = 0;
 
  while(current)
  {
    current = current-> next;
    ++number;
  }
   
  head2= NULL;
  last = NULL;
  newNode = NULL;
  
  current = head; 
  
  for(int i = 0; i < number ; ++i)
  {
    newNode = new node;
    newNode -> data = current -> data;
    newNode -> next = NULL;
    
    if(head2 == NULL)
    {
      head2 = newNode;
      last = newNode;
    }
    if(head2)
    {
      last -> next = newNode;
      last = newNode;
    }
    
    current = current -> next;
  }
  
  node * read = head2;
  if(number == 1)
  {
    cout << read-> data << "\t" ;
    return;
  }
  
  while(read)
  {
     
     cout << read-> data << "\t" ;
     read = read -> next;
  }
  
}
//delete a entered number       SOME CODE DOESN'T DO ERROR CHECKING FOR THE 
//                              EMPTY LIST, SIZE 1 LIST OR MULTIPLE LIST
void list::deleteANumber()
{
  int number;
  
  node * hold = head;
  
  if (!head)
    return;
  
  cout << "\nEnter number to add to delete from list." << endl;
  cin >> number;
  cin.ignore(100, '\n');
  
  while(head -> data == number)  
    {
      hold = hold-> next ;
      head = hold;
    }

  node * current  = head;
  node * temp = head;
  
  current = current -> next; // start current + 1 node
  while(current)
  {
    
    if(current -> data  == number)
    {
      current = current -> next;    // This was annoying untill I thought to restart every time
      temp -> next = current;       // there was a match. Couldn't think of a different way. 
      current = head -> next;       
      temp = head;
    }
    current = current -> next;
    temp = temp -> next;
  }
  
  
  
}
//addd to the start
void list::addToStart()
{
  node * temp = head;
  head = new node;
  
  if(!head)
    return;
    
  cout << "\nEnter number to add to start of list." << endl;
  cin >> head -> data;
  cin.ignore(100, '\n');

  head -> next =  temp;
  

}
//deleteLast node
void list::deleteLast()
{
  if(!head)
    return;
  
  node * temp = head->next;
  node * hold = head;

  while(temp->next){
    hold = temp;
    temp = temp->next;
  }

  hold -> next = NULL;
  delete temp;

  cout << "\n" << deleteLast(head);
} 
int list::deleteLast(node *& head){
  if(!head){
    return 0 ;
  }
  int count = 0;
  cout << head->data << " "  ;
  //
  //if(!head->next){
  //  node * temp = head->next;
  //  delete head;
  //  head = temp;
  //  return 0 ;
  //}

  count += deleteLast(head->next);
  
   if(count <= 1){
     node * temp = head;
     head = head-> next;
     delete temp;
     ++count;
   }
   
   return count;
  
}





































void list::firstAndLast()
{
  node * pointer;
  node * current;
  current = head;
  
  if(!head)
  {
    cout << "\nThere is no list!!" << endl;
    return;
  }
  
  cout << "\nThis funtion will read out the first and last node."<< endl;
  
  
  cout << "\nThis is the first node.\t == " << current -> data << endl;
  while(current)
  {
    if(current ->next == NULL)
      {
      cout << "\nThis is the last node.\t == "<< current -> data << endl;
      cout << "\nThis is the last node location in memory. == "<< current << endl;
      
      pointer = (node *)current; // Just showing that its possible to point to any spot in the 
                                 // LLL to save a spot or flag something
      
      cout << "\nThis is memory location data.\t == "<< pointer->data << endl;
      }
    current = current-> next;
  }
}

//read out list
void list::realAllOut()
{
  

  node * current;
  current = head;
  
  
  if (!head)
     return;
     
 
  while(current)
  {
    cout << current->data << "\t" ;
    current = current-> next;
  }
 
  //cout << "\n\n" << endl;

}
void list::realAllOut(node * toRead)
{
  

  node * current;
  current = toRead;
  
  
  if (!toRead)
     return;
     
 
  while(current)
  {
    cout << current->data << "\t" ;
    current = current-> next;
  }
 
  //cout << "\n\n" << endl;

}

void list::makeLLL() 
{
  node  *last, *newNode ; //Variables needed to build a LLL (HEAD is made already in class)
                          //1 to point to start, 1 to point to end and 1 to create
                                 
                                 
  head = NULL;   //set the head node pointer to null already set anyway
  last = NULL;
  newNode = NULL;
  
  int num;
  
  srand(time(0));  //auto set
  
  for(int i = 0; i <7 ; ++i)
  {
    num = rand() % 9;
  
    newNode = new node;
    newNode -> data = num;
    newNode -> next = nullptr;
  
    if(head == nullptr) //empty list
      {
       head = newNode;
       last = newNode;
      }
    else   // not empty
     {
       last -> next = newNode;
       last = newNode;
     }
  }
  current = head;

}
//contructor
list::list() 
{
  head = NULL;
  current = NULL;
}

//destructor
list::~list() 
{
  
}





struct node * list::copyList()
{
  node * copy = new node;
  if(!head)
  {
    copy = NULL;
    return copy;
  }


  copyList(head, copy);

  return copy;
}


void list::copyList(node * head, node *& copy)
{
  if(!head)
  {
    copy = NULL;
    return;
  }

  else
  {
    copy = new node;
    copy -> data = head ->data;
    copy -> next = NULL;

  }

  copyList(head->next, copy->next);
}


















