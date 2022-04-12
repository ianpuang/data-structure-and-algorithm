#ifndef node_h
#define node_h

class Node
{
private:
	int id;
		

public:
	Node();
	void setId(int newId);
	int getId();
	void setNextPtr(Node* newNextPtr);
	Node* nextPtr; 
	Node* getNextPtr();
};

Node::Node()
{
	id = -1 ;
	nextPtr = nullPtr;
	
}

void Node::setId(int newId)
{
	id = newId;
}

int Node::getId()
{
	return id;
}

Node* Node::setNextPtr(Node* newNextPtr)
{
	nextPtr = newNextPtr;
}


#endif
