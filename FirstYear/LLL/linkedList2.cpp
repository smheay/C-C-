#include <cctype>
#include <cstring>
#include <fstream>
#include <iostream>
using namespace std;

//Not sure what I was doing with this

const int SIZE = 100;

struct node {
	int data;
	node *next;
};


void readALL(node *head);
void addEnd(node *&head);
void deleteAll(node *&head);
void removeFirstAndLast(node *&head);
void deletecode(node *&head);



int main() {
  
  node * head = NULL;
  node * copy;
  
	int choice;

	do {
		cout << "\n\n\n\n LLL Lists \n";
		cout << "0 - Quit.\n";
		cout << "1 - Makle list.\n";
		cout << "2 - Read All.\n";
		cout << "3 - add at end\n";
		cout << "4 - delete all\n";
		cout << "5 - removeFirstAndLast \n";
		cout << "6 - void deletecode(node *&head)\n";
		cout << "7 - \n";
		cout << "\n\n\n\n\n\n\n\n\n\n";
		cout << "Enter Choice: ";
		cin >> choice;
		cin.ignore(100, '\n');

		switch (choice) {
		case 0:
			cout << "Goodbye.\n";
			break;
		case 1:
			copy=(head);
			break;
		case 2:
			readALL(head);
			break;
		case 3:
			addEnd(head);
			break;
		case 4:
			deleteAll(head);
			break;
		case 5:
			removeFirstAndLast(head);
			break;
		case 6:
		  deletecode(head);
			break;
		case 7:
			break;
		default:
			cout << "\nSorry, but " << choice << " isn't a valid choice.\n";
			break;
		}

	} while (choice != 0);

	return 0;
}
///////////////////////////////////////////////////
void deletecode(node *&head) {
	node *p, *q;
	q = head;
	p = head->next;
  
  
	if (q->data == 4) 
	{
		head = p;
		delete q;
	}
	else
	{
		while (p->data != 4)
		{
			q = q->next;
			p = p->next;
			if (p->next == NULL) 
			{
				q->next = NULL;
				delete p;
			} 
			else 
			{
				q->next = p->next;
				delete p;
			}
		}
	}
}
//////////////////////////////////////////////////////
void removeFirstAndLast(node *&head) {
	if (!head) // no items
		return;

	if (head->next == NULL) { // one item list
		delete head;
		head = NULL;
		return;
	}
	node *temp = head;
	if (head->next->next == NULL) { // two item list
		while (head) {
			temp = head;
			head = head->next;
			delete temp;
		}
		head = NULL;
		return;
	}
	node *drag, *drag2 = head;
	temp = head;	   // more than 2 items
	head = head->next; // remove head item
	delete temp;

	temp = head->next;
	while (temp->next) // go to t->n to point to last
	{
		drag2 = drag2->next;
		drag = temp;
		temp = temp->next;
	}
	drag2->next = NULL;
	delete drag;
	delete temp;
}

//////////////////////////////////////////////////////
void deleteAll(node *&head) {
	if (!head)
		return;

	node *hold = head;

	while (head != NULL) {
		hold = head;
		head = head->next;
		delete hold;
		readALL(head);
	}
}
//////////////////////////////////////////////////////
void addEnd(node *&head) {
	node *current = head;
	node *newNode;

	if (!head) {
		head = new node;
		head->next = NULL;
		head->data = rand() % 20;
	}

	else {
		while (current->next) {
			current = current->next;
		}
		newNode = new node;
		current->next = newNode;
		newNode->next = NULL;
		newNode->data = rand() % 20;
	}
}
//////////////////////////////////////////////////////
void readALL(node *head) {
	if (!head)
		return;

	node *current = head;
	node *read = head;
	/*
	  cout << "This is head data = " << head->data;
	  cout << "\nThis is head memory = " << head;

	  cout << "\n\n\nThis is current data = " << current->data
		   << "\nThis is current memory = " << current
		   << "\nThis is current->next-> memory = " << current->next << endl;

	  cout << "\n\n\n\n" << endl;
	  while (current) {
		  cout << "\n\n\nThis is current data = " << current->data
			   << "\nThis is current memory = " << current
			   << "\nThis is current->next-> memory = " << current->next <<
	  endl;
		  current = current->next;
	  }
	  */
	cout << "\n\n\n\n" << endl;
	while (read) {
		cout << read->data << "   ";
		read = read->next;
	}
}
//////////////////////////////////////////////////////
node & head(node & head){
  
  
	node *last, *newNode;
  head = NULL;
  last = NULL;
  newNode = NULL;
  
	int num;

	srand(time(0)); // auto set

	for (int i = 0; i < 5; ++i) {
		num = rand() % 6;

		newNode = new node;
		newNode->data = num;
		newNode->next = NULL;
		cout << newNode->data << endl;

		if (head == NULL) // empty list
		{
			head = newNode;
			last = newNode;
		} else // not empty
		{
			last->next = newNode;
			last = newNode;
		}
	}
	return * head;
}