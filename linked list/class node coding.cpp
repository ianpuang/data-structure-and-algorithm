#include <iostream>
using namespace std;

struct node
{
	int data;
	struct node* next;
};

int main()
{
	return 0;
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
