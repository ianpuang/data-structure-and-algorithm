#include <iostream>

using namespace std;

struct node
{
	int data;
	node *link;	
};

//function prototype 
void initializeQueue();
bool isEmptyQueue();
void addQueue();
void deleteQueue();
void front();
void back();


//global variable
node *newNode,*head,*current,*last,*queueFront,*queueRear;

int main()
{
	
}


void initializeQueue()
{
	while(queueFront!=NULL)
	{
		current = queueFront;
		queueFront = queueFront->link;
		delete current;
	}
	queueRear=NULL;
}
