

#include <stdio.h>
#include <stdlib.h>

#include "dictionary.h"
#include "linkedlist.h"
#include "result.h"

struct Dictionary {
	LinkedList* lPtr;
};

/******************
* Function Name: initDictionary
* Input: None
* Output: Dictionary*
* Function Operation: Initializes a dictionary by allocating memory for dictionary & linkedlist.
******************/
Dictionary* initDictionary()
{
	Dictionary* newDictionary = (Dictionary*)malloc(sizeof(Dictionary));
	//Making sure that the malloc succeeded.
	if (newDictionary != NULL)
	{
		newDictionary->lPtr = createLinkedList();
	}
	else if (newDictionary == NULL || newDictionary->lPtr == NULL)
	{
		destroyDictionary(newDictionary);
	}
	return newDictionary;
}

/******************
* Function Name: destroyDictionary
* Input: Dictionary*
* Output: void
* Function Operation: Free the memory that was allocated for the dictionary and its related functions.
******************/
void destroyDictionary(Dictionary* d)
{
	destroyLinkedList(d->lPtr);
	free(d);
}

/******************
* Function Name: sizeOfDictionary
* Input: Dictionary*
* Output: int
* Function Operation: Returns the number of items in the dictionary.
******************/
int sizeOfDictionary(Dictionary* d)
{
	return getSize(d->lPtr);
}

/******************
* Function Name: putInDictionary
* Input: Dictionary*, int, int
* Output: Result
* Function Operation: Determines & assaigns the requested item inside the dictionary.
This functions' purpose is to manage all the keys (and their respective values) in a sorted manner.
In order to achieve that it calls insertToList that can distinguish where it'd should place the item.
******************/
Result putInDictionary(Dictionary* d, int key, int value)
{
	return insertToList(d->lPtr, key, value);
}

/******************
* Function Name: getFromDictionary
* Input: Dictionary*, int
* Output: int
* Function Operation: Finds a value of a given key, if such can't be found the value 0 will be returned.
******************/
int getFromDictionary(Dictionary* d, int key)
{
	return findValue(getHead(d->lPtr), key);
}

/******************
* Function Name: removeFromDictionary
* Input: Dictionary*
* Output: Result
* Function Operation: Finds an item with the same key value as given & removes it from the dictionary.
******************/
Result removeFromDictionary(Dictionary* d, int key)
{
	Node* headPtr = getHead(d->lPtr);

	//Dictionary is empty - no key found
	if (headPtr == NULL)
	{
		return FAILURE;
	}

	//Head node need to be removed
	else if (getKey(headPtr) == key)
	{
		return removeHeadNode(d->lPtr);
	}
	else
	{
		return removeNode(d->lPtr, headPtr, key);
	}
}

/******************
* Function Name: printDictionary
* Input: Dictionary*
* Output: void
* Function Operation: Prints all the dictionary items.
						Example of a print:
							Dictionary: {[1:10][50:1][100:7]} 
******************/
void printDictionary(Dictionary* d)
{
	printList(d->lPtr);
}


/******************
* Function Name: createDictionaryFromArrays
* Input: int arr, int arr, int arr
* Output: Dictionary*
* Function Operation: Creates a dictionary from given arrays of matching keys & values.
******************/
Dictionary* createDictionaryFromArrays(int keys[], int values[], int size)
{
	Dictionary* newDictionary = initDictionary();

	fillListFromArrays(newDictionary->lPtr, keys, values, size);

	return newDictionary;
}



