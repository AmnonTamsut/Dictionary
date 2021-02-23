

#include "node.h"

struct Node {
	int key;
	int value;
	Node* next;
};

/******************
* Function Name: freeNode
* Input: Node*
* Output: void
* Function Operation: Frees a single node.
******************/
void freeNode(Node* nodePtr)
{
	free(nodePtr);
}

/******************
* Function Name: freeAllNodes
* Input: Node*
* Output: void
* Function Operation: De-allocates memory that's being used for all the relevant Nodes.
******************/
void freeAllNodes(Node* NodePtr)
{

	//Means that current Node isn't the last one on the list.
	if (NodePtr != NULL &&NodePtr->next != NULL)
	{
		freeAllNodes(NodePtr->next);
	}
	//Free current Node.
	free(NodePtr);
}

/******************
* Function Name: newNode
* Input: int, int
* Output: Node*
* Function Operation: Creates a new Node.
******************/
Node* newNode(int key, int value)
{
	Node* nodePtr = (Node*)malloc(sizeof(Node));

	if (nodePtr!=NULL)
	{
		//Assigning the new node its respective values.
		nodePtr->key = key;
		nodePtr->value = value;
		nodePtr->next = NULL;
	}

	return nodePtr;
}

/******************
* Function Name: printNode
* Input: nodePtr
* Output: Node*
* Function Operation: Prints a given Node.
******************/
void printNode(Node* nodePtr)
{
	printf("[%d:%d]", getKey(nodePtr), getValue(nodePtr));
}


/******************
* Function Name: getKey
* Input: Node*
* Output: int
* Function Operation: Returns the value of 'key'.
******************/
int getKey(Node* nodePtr)
{
	if (nodePtr == NULL)
	{
		return NULL;
	}
	return nodePtr->key;
}

/******************
* Function Name: getValue
* Input: Node*
* Output: int
* Function Operation: Returns the value of 'value'.
******************/
int getValue(Node* nodePtr)
{
	if (nodePtr==NULL)
	{
		return NULL;
	}
	return nodePtr->value;
}

/******************
* Function Name: getNext
* Input: Node*
* Output: Node*
* Function Operation: Returns the pointer to the next node of a given node.
******************/
Node* getNext(Node* nodePtr)
{
	if (nodePtr == NULL)
	{
		return NULL;

	}
	return nodePtr->next;
}

/******************
* Function Name: setKey
* Input: Node*, int
* Output: void
* Function Operation: Sets a key in a given Node.
******************/
void setKey(Node* nodePtr, int key)
{
	if (nodePtr == NULL)
	{
		return NULL;
	}
	nodePtr->key = key;
}

/******************
* Function Name: setValue
* Input: Node*, int
* Output: void
* Function Operation: Sets value in a given Node.
******************/
void setValue(Node* nodePtr, int value)
{
	if (nodePtr == NULL)
	{
		return NULL;
	}
	nodePtr->value = value;
}

/******************
* Function Name: setNext
* Input: Node*, Node*
* Output: void
* Function Operation: Sets Next pointer in a given Node.
******************/
void setNext(Node* nodePtr, Node* nextPtr)
{
	if (nodePtr == NULL)
	{
		return NULL;
	}
	nodePtr->next = nextPtr;
}

