#include <iostream>
#include <cstdlib>
#include <cstring>
#include <iomanip>

using namespace std;

struct node 
{
	  int data;
	  node * next; 
};
  
class list 
{
  public:
  
	list();  // contructor
	~list(); // destructor
	
	void makeLLL();
	int makeLLL(node *& head);
	
	
	void realAllOut();
	
	void remove_largest();
	void remove_largest(node * & head, int & largest);
	
	int countEven();
	int countEven(node * & head,int x);

  int sum();
	int sum(node * & head, int x);
	
	int removeLast();
	int removeLastRECUR(node * & head);
	
	int removeLastTwo();
	int removeLastTwoRECUR(node *& head);
	
	void removeAllAfterLastTwo();
	void removeAllAfterLastTwoRECUR(node *& head, node * temp);
  

	private: 
	node * head;
};

int main() 
{
  
	list my_list;
	node * head = NULL;
	int choice, value;
	

	my_list.makeLLL();
	cout << "\nThis is the LLL filled with 7 random numbers." << endl;
	my_list.realAllOut();
	
	do {
		cout << "\nLLL\n";
		cout << "0 - Quit.\n";
		cout << "1 - Make a new list.\n";
		cout << "2 - Recursion\n";
		cout << "3 - my_list.realAllOut();.\n";
		cout << "4 - sum.\n";
		cout << "5 - .\n";
		cout << "6 - .\n";
		cout << "7 - .\n";
		cout << "Choice: ";
		cin >> choice;
		cin.ignore(100, '\n');

		switch (choice) 
		{
		case 1: my_list.makeLLL();
			      cout << "\nThis is the LLL filled with 7 random numbers." << endl;
			      my_list.realAllOut();
	        	break;

		case 2: //value =  
		        my_list.removeAllAfterLastTwo();
		        //cout << "\n" <<  value << endl;
			break;
		case 3:my_list.realAllOut();
			break;
		case 4:cout << my_list.removeLastTwo();
			break;/*
		case 5:
			break;
		case 6:
			break;
		case 7:
			break;
		case 8:
			break;*/
		case 0:
			break;
		}
	} while (choice != 0);

	return 0;
}
int list::countEven()
{    
     int x= 0 ;
     x = countEven(head,x);
     return x;
}
int list::countEven(node * & head, int x)
{ //if head return
  //if even increase count 
  // else traverse

	 
	 if (!head)
	    return x;
 
	 x = countEven(head->next,x);
   
	 if(head->data % 2 == 0)
	     return x + 1;
	 else 
	    return x;

	     
	 
}


void list::remove_largest()
{
  
  if(!head)  // emtpty
    return;
  if(NULL == head -> next) // single
  {
    delete head;
    head = NULL;
    return;
  }
  node * flag = NULL;
  node * current = head->next;
  node * previous = head;
  
  if(previous-> data < current->data)
       flag = current;
  else
       flag = previous;
  
  while (current) // read all numbers
  {
    if(flag-> data < current-> data)
         flag = current;
    
    current = current -> next;
    
  }
  flag -> data = head -> data;
  flag = head -> next;
  delete head;
  head = flag;
  
  // int largest = 0;
  // remove_largest(head, largest);
}


void list::remove_largest(node * & head, int & largest)
{  
    if (!head) return;
    if (head->data > largest)
       largest = head->data;
    remove_largest(head->next, largest);
    if (largest == head->data)
    {
       node * temp = head;
       head = head->next;
       delete temp;
    }
}

void list::realAllOut()
{
  

  node * current;
  current = head;
  
  cout << "\n" << (*current).data << "\n" ;
  
 
  if (!head)
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
	node *last, *newNode; // Variables needed to build a LLL (HEAD is made
						  // already in class)
	// 1 to point to start, 1 to point to end and 1 to create

	head = NULL; // set the head node pointer to null already set anyway
	last = NULL;
	newNode = NULL;

	int num;

	srand(time(0)); // auto set

	for (int i = 0; i < 7; ++i) {
		num = rand() % 9;

		newNode = new node;
		newNode->data = num;
		newNode->next = nullptr;

		if (head == nullptr) // empty list
		{
			head = newNode;
			last = newNode;
		} else // not empty
		{
			last->next = newNode;
			last = newNode;
		}
	}
	
	
	makeLLL(head);
}

int list::makeLLL(node *& head)
{
  int count = 0;
  if(!head)
    return 0;
    
  if(head->data == 2)
  {
    node * temp = head;
    head = new node;
    head->data = 5;
    head->next = temp;
    count = makeLLL(temp->next)+ 1;
  }
  
  else
     count = makeLLL(head->next);
  
  return count;
}
	
int list::removeLast()
{
  if(!head)
     return 0;
  
  return removeLastRECUR(head);
  
}
int list::removeLastRECUR(node * & head)
{
  int x = 0;
  
  if(!head)
    return 0;
  
  
	if(!head->next)
	 {
	   x = head->data;
	   delete head;
	   head = NULL;
	   return x;
	 }
	 
  return x = removeLastRECUR(head->next);
  
   
}

int list::removeLastTwo()
{
  if(!head)
     return 0;
  
  return removeLastTwoRECUR(head);
  
}
int list::removeLastTwoRECUR(node *& head)
{
   if(!head)
      return 0;
      
   if(head && !head->next)
      {
        delete head->next;
        delete head;
        head = NULL;
        return 0;
      }
  
   if(!head->next->next->next) 
     {  
        node * temp = head->next->next;
        node * temp2 = head->next;
        delete temp;
  	    delete temp2;
        head->next = NULL;  
        return head->data;
     }
    
   return removeLastTwoRECUR(head->next); 
}



void list::removeAllAfterLastTwo()
{
  if(!head)
      return;
      
  node * temp = NULL;
  
  removeAllAfterLastTwoRECUR(head->next, temp);
}

void list::removeAllAfterLastTwoRECUR(node *& head, node * temp)
{
  if(!head)
    return ;
  
  if(head->data == 2)
    temp = head;

  removeAllAfterLastTwoRECUR(head->next, temp);
  
  if(head ->data == 2)
	temp = NULL;

  if(temp != NULL)
   {
     node * goodbye = head;
     head = head->next;
     delete goodbye;
   }

}






int list::sum()
{
  if(!head)
    return 0;
  if(!head->next)
    return 0;

  node * temp = head;
  cout << " This is data 1 " << head-> data << endl;

  while(temp -> next)
      {
        temp = temp -> next;
      }

  temp-> next = head;

  cout << " This is data 2 " << temp -> data << endl;
  int x = 1;

  x = sum(head, x);
  
  temp = head;
  while(temp-> next != head)
      {
        temp = temp -> next;
      }
  cout << " This is data 3 " << temp -> data << endl;
  temp-> next = NULL;
  
  if(x == 1)
    return 1;
  
  else 
    return 0;

}
int list::sum(node *& head, int x)
{
  if(head == head->next)
    return 0;
  if(x == 0)
    return 0;

  node * temp = head;
  
  while(temp != temp-> next)
  {
    if(temp->data == head->data)
      { cout << " This is a copy of data " << endl;}
    temp = temp->next;
  }


  return sum(head->next,x);
}





// contructor
list::list()
{
	head = NULL;
}

// destructor
list::~list()
{
  
}





