#include <iostream>
using namespace std;

struct node
{
	int data; //list of integer data type
	node* next; //store address of next node
};

node* head; //variable that will be pointer to node and store the address of first node in the linked list (head)
node *newNode, *last; //global variable (can be accessed anywhere)


node *buildListForward();
node *buildListBackward();
void outputAll();
void deleteNode(int);
bool search(int);
void insertNodeHead(int);
void insertNodeMiddle(int item);
void insertNodeTail(int item);
void deleteItem(int item);

int main()
{
	buildListForward();
	outputAll();
	//buildListBackward();
	cout << "\ninsert number\n";
	int input;
	cin >> input;
	search(input);
	deleteItem(input);
	outputAll();
}


node *buildListForward() //insert at the end
{
	node  *newNode, *last;
	int num;
	
	cout << "Enter numbers of integer. Enter -999 to exit input." << endl;
	cin >> num;
	head = NULL; 
	
	while(num != -999)
	{
		newNode = new node; //create a new node
		newNode -> data = num;  //assign number into data of the new node
		newNode -> next = NULL; //newnode link points to null (become tail)
	
	if(head == NULL)  //if there's nothing in the list 
	{
		head = newNode; //make a new node and assign it as first item
		last = newNode; //assign the new node as last item as well 
	}
	else //else if there is already a value in the first pointer
	{
		last -> next = newNode;  //make last item link to new node
		last = newNode; //newNode become the last item 
	}
	cin >> num;
	}//end while 
	return head;
}//end func

node *buildListBackward() //insert at the beginning 
{
	node   *newNode;
	int num;
	
	cout << "\nEnter list of integer. Enter -999 to exit input." << endl;
	cin >> num;
	head = NULL; //head points to null
	
	while(num != -999)
	{
		newNode = new node; //create a new node
		newNode->data = num; //store data in new node
		newNode->next = head; //put newNode at the beginning of the list 
		
		head = newNode; //head pointer points to newNode
		/*
		1. create new node
		2. store data into new node
		3. new node link to head
		4. head points to new node
		*/
		cin >> num; //read next number
	}
	
	return head; 

}//end of buildListBackward

void outputAll()
{
	node *current;
	current = head;
	cout << endl;
	while(current != NULL)
	{
		cout <<  current->data << " ";
		current = current->next;
	}
}

void deleteNode(int input)
{
	node *current, *p, *q;	
	q=p->next;
	p->next=q->next;
	delete q;	

}

bool search(int item)
{
	// my try
	node *current;
	bool found=false;
	current = head;
	while(current!=NULL && !found)
	{
	if(current->data==item)
	{
		found = true;
		cout << "Item found\n";
		cout << current->data;
	}
	else
	{
		current = current->next;
	}
	}
	return found;
	
	
/*	node *current;
	bool found = false;
	current = head;

	while(current!=NULL && !found)
	{
		if(current->data == item)
		{
			found = true;
			cout << "number is found in the list";
		}
		else
		{
			current = current->next;
		}
	}
	return found;*/
}

void insertNodeHead(int item)
{
	//my try
	newNode = new node;
	newNode->data = item;
	newNode->next = head;
	head=newNode;
	
	if(last==NULL)
	{
		last = newNode;
	}
}

void insertNodeMiddle(int item)
{
	newNode = new node;
	node *bef, *aft;
	//inserting the node
	newNode->data = item;
	aft->next = newNode->next;
	bef->next=newNode;
}

void insertNodeTail(int item)
{
	newNode = new node;
	
	//inserting the node 
	newNode->data = item;
	newNode->next = NULL;
	
	if(head==NULL)
	{
		head=newNode;
		last=newNode;
		//count++;
	}
	else
	{
		last->next=newNode;
		last = newNode;
		//count++
	}
}

void deleteItem(int item)
{
	node *current;
	current=head;
	current->data = item;
//delete node with cases consideration
	if(head==NULL)
	{
		cout << "\nCannot delete from an empty list.\n";
	}
	else
	{
		if(head->next==current)
		{
			head->next = current->next;
		}
		else
		{
			
		}
	}
}
/*
insert node in between two pointer (*p and *q)
newNode = new node;
newNode->next = q;
p->next=newNode;
!order of statement does not matter
*/


