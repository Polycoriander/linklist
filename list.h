#ifndef __LIST_H__
#define __LIST_H__
#include <stdio.h>
#include <stdlib.h>
#define SIZE 15

typedef struct node
{
    int item;
    struct node * next;
} Node, *list;

void initializeList(list * plist);
void appendList(int data, list * plist);
int isEmpty(list * plist);
void displayList(list List);
void freeList(list * pList);
list insertList(list * pList, int data, int position);
list deleteList(list * pList, int data, int position);
void traverse(list * plist, int (*pFun)(int * data));

extern int (*pFun[2])(int *data);
#endif