#include <iostream>
using namespace std;

struct node
{
	int data;
	node* llink;
	node* rlink;
};

node* root=NULL;
node *current, *trailCurrent;
node* newNode;

void searchItem(int);
void insertItem(int);


int main()
{
	
}

void searchItem(int item)
{
	bool found = false;
	
	if(root==NULL)
	{
		cout << "tree is empty\n";
		return;
	}
	else
	{
		current = root;
		while(current!=NULL && !found)
		{
			if(current->data==item)
			{
				found = true;
			}else if(current->data>item)
			{
				current=current->llink;
			}else
			{
				current=current->rlink;
			}
		}
	}
}

void insertItem(int item)
{
	newNode = new node;
	newNode->data=item;
	newNode->llink=NULL;
	newNode->rlink=NULL;
	
	if(root==NULL)
	{
		root = newNode;
	}
	else
	{
		current = root;
		while(current!=NULL)
		{
			trailCurrent=current;
			if(current->data==item)
			{
				cout << "\nCannot insert duplicate\n";
				exit;
			}else if(current->data>item)
			{
				current=current->llink;
			}else
			{
				current=current->rlink;
			}
			
			if(trailCurrent->data>item)
			{
				trailCurrent->llink = newNode;
			}else
			{
				trailCurrent->rlink = newNode;
			}
		}
	}
}
