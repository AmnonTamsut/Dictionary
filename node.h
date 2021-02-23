

#pragma once
#ifndef __NODE_H
#define __NODE_H
#include <stdio.h>
typedef struct Node Node;

int getKey(Node* nodePtr);
int getValue(Node* nodePtr);
Node* getNext(Node* nodePtr);
void setValue(Node* nodePtr, int value);
void setKey(Node* nodePtr, int key);
void setNext(Node* nodePtr, Node* nextPtr);
void freeNode(Node* nodePtr);
void freeAllNodes(Node* headNodePtr);
Node* newNode(int key, int value);
void printNode(Node* nodePtr);

#endif
