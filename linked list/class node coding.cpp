#include <iostream>
using namespace std;

struct node
{
	int data; //list of integer data type
	node* next; //store address of next node
};

struct node* head; //variable that will be pointer to node and store the address of first node in the linked list (head)

void insert(int);
void print();
int main()
{
	head = NULL; // means the list is empty
	cout << "How many numbers?\n";
	int number,input;
	cin >> number;
	
	for(int i=0;i<number;i++)
	{
		cout << "Input a number: \n";
		cin >> input;
		insert(input);
		print();
	}
}

void insert(int number)
{
	
}

void print()
{
	
}

int listLength(struct node* head)
{
	struct node *current = head;
	int count = 0;
	
	while(current!=NULL)
	{
		count++;
		current = current -> next;
	}
	return count;
}
