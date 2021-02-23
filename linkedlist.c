

#include "linkedlist.h"


struct LinkedList {
	int size;
	Node* head;
};

/******************
* Function Name: createLinkedList
* Input: none
* Output: LinkedList*
* Function Operation: Creates a linked list by allocating it memory using 'malloc'
******************/
LinkedList* createLinkedList()
{
	LinkedList* listPtr= (LinkedList*)malloc(sizeof(LinkedList));
	
	//Making sure that allocation succeded before trying to change values
	if (listPtr!=NULL)
	{
		//Assigning the new list its respective values.
		listPtr->size = 0;
		listPtr->head = NULL;
	}
	return listPtr;
}

/******************
* Function Name: destroyLinkedList
* Input: LinkedList*
* Output: void
* Function Operation: In charge of freeing all the memory that was allocated for the linked-list.
******************/
void destroyLinkedList(LinkedList* listPtr)
{
	freeAllNodes(listPtr->head);
	free(listPtr);
}

/******************
* Function Name: getHead
* Input: LinkedList*
* Output: Node*
* Function Operation: Returns the address of the head node in a given list.
******************/
Node* getHead(LinkedList* listPtr)
{
	return listPtr->head;
}

/******************
* Function Name: getSize
* Input: LinkedList*
* Output: int
* Function Operation: Returns the size value of a given list.
******************/
int getSize(LinkedList* listPtr)
{
	return listPtr->size;
}

/******************
* Function Name: setHead
* Input: LinkedList*, Node*
* Output: void
* Function Operation: Assignes a node to a list as the head-node.
******************/
void setHead(LinkedList* listPtr, Node* nodePtr)
{
	listPtr->head = nodePtr;
}

/******************
* Function Name: setSize
* Input: LinkedList*, char
* Output: void
* Function Operation: Increases or decreases the value of size in a list.
******************/
void setSize(LinkedList* listPtr, char sign)
{
	if (sign == '+')
	{
		listPtr->size++;
	}
	else if (sign =='-')
	{
		listPtr->size--;
	}
}

/******************
* Function Name: insertToList
* Input: LinkedList*, int, int
* Output: Result
* Function Operation: Navigates the given data to the relevant function.
						- When the head will need to be changed, it'll call 'insertNewHead'.
						- In more general cases it'll call 'insertNewNode'.
******************/
Result insertToList(LinkedList* l, int key, int value)
{
	Result statusInd;
	Node* headPtr = l->head;

	if (headPtr == NULL || getKey(headPtr) == key || getKey(headPtr) > key)
	{
		statusInd = insertNewHead(l, key, value);
	}
	else
	{
		statusInd = insertNewNode(l, headPtr, key, value);
	}
	return statusInd;
}

/******************
* Function Name: insertNewHead
* Input: LinkedList*, int, int
* Output: Result
* Function Operation: Detemines whether the new Node is relevant to the head Node. It makes the appropriate modifications.
******************/
Result insertNewHead(LinkedList* l, int key, int value)
{
	Node* newNodePtr;


	if (l->head == NULL)
	{
		l->head = newNode(key, value);

		//Error return if allocation failed
		if (l->head == NULL)
		{
			return MEM_ERROR;
		}
		else
		{
			setSize(l,'+');
			return SUCCESS;
		}
	}
	//When head-key is equal to the key provided - value is updated.
	else if (getKey(l->head) == key)
	{
		setValue(l->head, value);
		return SUCCESS;

	}

	//Swap new node and head in case that head-key is bigger than the key provided.
	else if (getKey(l->head) > key)
	{
		newNodePtr = newNode(key, value);
		if (newNodePtr != NULL)
		{
			setNext(newNodePtr, l->head);
			l->head = newNodePtr;
			setSize(l, '+');
			return SUCCESS;

		}
		else
		{
			//Error print if allocation failed
			return MEM_ERROR;
		}
	}

	else
	{
		insertNewNode(l, getNext(l->head), key, value);
	}

}

/******************
* Function Name: insertNewNode
* Input: LinkedList*, Node*, int, int
* Output: Result
* Function Operation: Inserts a new node in its respective position.
					  - First it filters a few edge cases.
					  - Then, if those requirements not met it calles insertNewNode with the next node.
******************/
Result insertNewNode(LinkedList* l, Node* nodePtr, int key, int value)
{
	Node* newNodePtr;
	//When the dictionary is empty

	if (getKey(nodePtr) == key)
	{
		setValue(nodePtr, value);
	}
	else if (getNext(nodePtr) == NULL)
	{
		newNodePtr = newNode(key, value);


		//Error return if allocation failed
		if (newNodePtr == NULL)
		{
			return MEM_ERROR;
		}
		else
		{
			setNext(nodePtr, newNodePtr);
			setSize(l, '+');
			return SUCCESS;
		}
	}
	else if (getKey(getNext(nodePtr)) > key)
	{
		newNodePtr = newNode(key, value);
		if (newNodePtr != NULL)
		{
			setNext(newNodePtr, getNext(nodePtr));
			setNext(nodePtr, newNodePtr);
			setSize(l, '+');
		}
		else
		{
			//Error print if allocation failed
			return MEM_ERROR;
		}
	}
	else
	{
		insertNewNode(l, getNext(nodePtr), key, value);
	}
}

/******************
* Function Name: removeHeadNode
* Input: LinkedList*
* Output: Result
* Function Operation: Removes & re-assaigns the head-node.
******************/
Result removeHeadNode(LinkedList* l)
{
	Node* tmpPtr;

	if (getHead(l) != NULL)
	{
		tmpPtr = l->head;

		//Assaigning head
		setHead(l, getNext(l->head));

		//Freeing obsolete memory.
		freeNode(tmpPtr);

		//Updating size of the list
		setSize(l, '-');
		return SUCCESS;
	}

	//Means that the list is empty
	else
	{
		printf("List is empty!");
		return FAILURE;
	}
}


/******************
* Function Name: removeNode
* Input: LinkedList*, Node*, int
* Output: Result
* Function Operation: Removes a single node from the list & re-connects the list according to the changes. 
******************/
Result removeNode(LinkedList* l, Node* nodePtr, int key)
{
	//Variable that'll be used for holding the pointer to the node desired.
	Node* tmpPtr;
	if (getNext(nodePtr) == NULL)
	{
		return FAILURE;
	}
	else if (getKey(getNext(nodePtr)) == key)
	{

		tmpPtr = getNext(nodePtr);

		//Removing the wanted node from the chain
		setNext(nodePtr, getNext(getNext(nodePtr)));
		freeNode(tmpPtr);
		setSize(l, '-');
		return SUCCESS;
	}

	//No match found - continue the search in the next node
	else
	{
		removeNode(l, getNext(nodePtr), key);
	}

}

/******************
* Function Name: findValue
* Input: Node*, int
* Output: int
* Function Operation: Finds a node & returns its value.
******************/
int findValue(Node* nodePtr, int key)
{
	if (nodePtr == NULL)
	{
		return 0;
	}
	else if (getKey(nodePtr) == key)
	{
		return getValue(nodePtr);
	}

	else
	{
		findValue(getNext(nodePtr), key);
	}
}

/******************
* Function Name: printList
* Input: LinkedList*
* Output: void
* Function Operation: Prints every item on the list.
						Example:
						{[1:10][50:90][100:80]}
******************/
void printList(LinkedList* l)
{
	Node* tmpNode = l->head;

	printf("{");

	while (tmpNode != NULL)
	{
		printNode(tmpNode);
		tmpNode = getNext(tmpNode);
	}

	printf("}");

}

/******************
* Function Name: fillListFromArrays
* Input: LinkedList* ,int arr[], int arr[], int
* Output: void
* Function Operation: Creates a list contains the keys & values given by the arrays 'keys', 'values.
					  Fairly simple proccess. due to the fact that the arrays are synced, 
					  (Node key= keys[i], value=values[i]), we only have to call 'insertToList'
					  & it creates the node & finds the right place for it in the list.
******************/
void fillListFromArrays(LinkedList* l, int keys[], int values[], int size)
{
	int i;
	for (i = 0; i < size; i++)
	{
		insertToList(l, keys[i], values[i]);
	}
}
