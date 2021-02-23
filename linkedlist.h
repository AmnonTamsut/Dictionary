
#pragma once
#ifndef __LINKEDLIST_H
#define __LINKEDLIST_H
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "result.h"
#include "node.h"


typedef struct LinkedList LinkedList;

LinkedList* createLinkedList();
void destroyLinkedList(LinkedList* listPtr);
Node* getHead(LinkedList* listPtr);
int getSize(LinkedList* listPtr);
void setHead(LinkedList* listPtr, Node* nodePtr);
void setSize(LinkedList* listPtr,char sign);

Result insertToList(LinkedList* l, int key, int value);
Result insertNewHead(LinkedList* l, int key, int value);
Result insertNewNode(LinkedList* l,Node* nodePtr, int key, int value);
Result removeHeadNode(LinkedList* l);
Result removeNode(LinkedList* l, Node* nodePtr, int key);
int findValue(Node* nodePtr, int key);
void printList(LinkedList* l);
void fillListFromArrays(LinkedList* l, int keys[], int values[], int size);



#endif
