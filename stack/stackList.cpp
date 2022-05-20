#include <iostream>
using namespace std;

struct node
{
	int data;
	node *link;	
};

//function prototype
void initialiseStack();
bool isEmptyStack();
void push(int);
void pop();
int top();

//global variable
node *head,*current,*newNode,*stackTop;

int main()
{
	int data;
	initialiseStack();
	isEmptyStack(); 
	top();	
}

void initialiseStack()
{
	stackTop = NULL;
	node *temp;
	while(stackTop!=NULL)
	{
		temp = stackTop;
		stackTop = stackTop->link;
		delete temp;
	}

}

bool isEmptyStack()
{
	return (stackTop==NULL);
}

void push(int item)
{
	newNode = new node;
	newNode->data=item;
	newNode->link=stackTop; //insert newNode before stackTop
	stackTop = newNode; //stackTop point top node
}//end push

void pop()
{
	if(stackTop!=NULL)
	{
		current=stackTop;
		stackTop=stackTop->link;
		delete current;
	}
	else
	{
		cout << "Nothing to delete as the stack is empty\n";
	}
}

int top()
{
	return stackTop->data;
}
