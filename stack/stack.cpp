#include <iostream>

using namespace std;

class stack
{
	private:
		int maxStackSize=100;
		int stackTop;
		int *list;
	public: 
		void initializeStack();
		bool isEmptyStack();
		bool isFullStack();
		void push(int);
		int top();
		void pop();
		//~stack();
		
		//other function
		int getStackTop();
};

int main()
{
	stack newStack;
	newStack.initializeStack();
	int item=10;
	newStack.push(item);
}

void stack::initializeStack()
{
	stackTop = 0;
}

bool stack::isEmptyStack()
{
	return(stackTop==0);
}

bool stack::isFullStack()
{
	return(stackTop==maxStackSize);
}

void stack::push(int item)
{
	if(!isFullStack())
	{
		list[stackTop] = item; //add item at top
		stackTop++;
		cout << "item added\n";
	}
	else
	{
		cout << "Item cannot be inserted\n";
	}
}
int stack::getStackTop()
{
	return stackTop;
}
