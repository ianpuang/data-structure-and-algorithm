#include <iostream>

using namespace std;

struct node
{
	int data;
	node *llink;
	node *rlink;	
};


void inOrder(node* p);
void preOrder(node* p);
void postOrder(node* p);

int main()
{
	
}

void inOrder(node *p)
{
	if(p!=NULL)
	{
		inOrder(p->llink);
		cout << p->data << " ";
		inOrder(p->rlink);
	}
}

void preOrder(node *p)
{
	if(p!=NULL)
	{
		cout << p->data<< " ";
		preOrder (p->llink);
		preOrder (p->rlink);
	}
}

void postOrder(node* p)
{
	if(p!=NULL)
	{
		postOrder(p->llink);
		postOrder(p->rlink);
		cout << p->data << " ";
	}
}
