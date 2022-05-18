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
bool searchOrderedList(int);
void insertNodeHead(int);
void insertNodeMiddle(int item);
void insertNodeTail(int item);
void insertItemOrdered(int);
void deleteItem(int item);
void deleteNodeOrdered(int);

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
	node *current, *befCurrent; //pointer to current node and node before the current node
	current=head; //set current value equal to head 
	//current->data = item;
	bool found;
//delete node with cases consideration
	if(head==NULL)//if list is empty
	{
		cout << "\nCannot delete from an empty list.\n";
	}
	else
	{
		if(head->data==item)//if  head data is equal to item
		{
			//current = head; 
			head = head->next; //head points to next node 
			//count--;
			
			if(head==NULL) //list only has one node
			{
				last=NULL; //pointer last point to null
				delete current; 
			}
		}
		else //if item is not at head
		{
			found = false;  
			befCurrent = head; //set befCurrent pointer to point to head
			current=head->next; //current pointer points to next node
		}
		
		while(current!=NULL && !found) //while item still not found and havent reached end of node
		{
			if(current->data != item) //if data in current pointer not equal to item
			{
				befCurrent = current; //befCurrent pointer point to current
				current=current->next; //current pointer move to next node
			}else
			{
				found = true; //node found
			}
		}
		if(found) //if node is found
		{
			befCurrent->next=current->next;
			//count--;
			
			if(last==current) //node to be deleted is the last node 
			{
				last = befCurrent; //node before the current node(node to be deleted) become the last node 
				delete current; //delete the node
			}
			
		}
	}
}

bool searchOrderedList(int item)
{
	node *current;
	bool found = false;
	current=head;
	
	while((!found && current!=NULL))
{
	if(current->data>=item)
	{
		found = true;
		cout << "Item found\n";
	}
	else
	{
		current=current->next;
	}
	
	if(found)
	{
		found = (current->data == item);
	}
	return found;
}
}

void insertItemOrdered(int item)
{
	node *current , *trailCurrent; //this two pointer is for traversing the list
	newNode = new node; //create node
	newNode->data = item;
	newNode->next=NULL;
	bool found;
	
//case 1
	if(head==NULL)
	{
		head = newNode;
		last = newNode;
		
		while(current != NULL && !found)
		{
			if(current->data >= item)
			{
				found = true;
			}
			else
			{
				trailCurrent=current;
				current=current->next;
			}
		}
		/*
		-my try- 
		current->next=NULL;
		head->next=current;
		trailCurrent->next=current;
		*/
	}
//case 2
	else if(current==head)
	{
		newNode->next=head;
		head=newNode;
	}
	else
	{
		trailCurrent->next=newNode;
		newNode->next =current;
		
		if(current==NULL)
		{
			last = newNode;
		}
	}

}

void deleteNodeOrdered(int item)
{
	node *current, *trailCurrent;
	newNode=new node;
	newNode->data=item;
	bool found;
//case 1
	if(head==NULL)
	{
		cout << "Cant delete item because the list is empty\n";
	}
	else
{
	current=head;
	found=false;
//case 2
	if(current->data==item)	
	{
		current->next=head;
	}
//case 3
	while(!found && current!=NULL)
{
	if(current->data>=item)
	{
		
		//current=newNode;
		//trailCurrent->next = current;
		found = true;
	}else
	{
		trailCurrent=current;
		current=current->next;
	}
//case 4
	if(current==NULL)
	{
		cout << "Item not in the list\n";
	}else
	{
		if(current->data==item)
		{
			if(head==current)
			{
				head = head->next;
				if(head==NULL)
				{
					last==NULL;
					delete current;
				}
				else
				{
					trailCurrent->next=current->next;
					if(current==last)
					{
						last=trailCurrent;
						delete current;
					}
					//count--;
				}
				}else
					cout << "item not in the list\n";
				
			}
		}
	}
}


	
}





