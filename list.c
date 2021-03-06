#include "list.h"
void initializeList(list * plist) 
{
     * plist = NULL;
}

void appendList(int data, list * plist)
{
    if(isEmpty(plist))
    {
        * plist = (Node *)malloc(sizeof(Node));
        (* plist) -> item = data;
        (* plist) -> next = NULL;
    }
    else
    {
        Node *pNode = *plist, *p;
        while(pNode -> next != NULL)
            pNode = pNode -> next;
        p = (Node *)malloc(sizeof(Node));
        pNode -> next = p;
        p -> item = data;
        p -> next = NULL;
    }
}

int isEmpty(list * plist)
{
    if(*plist == NULL)
        return 1;
    return 0;
}

void displayList(list List)
{
    Node *pNode = List;
    while(pNode != NULL)
    {
        printf("%d ", pNode -> item);
        pNode = pNode -> next;
    }
    printf("\n");
}

void freeList(list * pList)
{
    Node *previous = NULL, * current = NULL;
    for(previous = *pList; previous != NULL; previous = current)
    {
        current = previous -> next;
        free(previous);
    }
}

list insertList(list * pList, int data, int position)
{
    Node *pNode = NULL, *pNode1 = *pList;
    int i = 1;
    if(position == 1)
    {
        pNode = (Node *) malloc(sizeof(Node));
        pNode -> next = *pList;
        pNode -> item = data;
        return pNode;
    }
    while(++ i != position)
        pNode1 = pNode1 -> next;
    pNode = (Node *) malloc(sizeof(Node));
    pNode -> item = data;
    pNode -> next = pNode1 -> next;
    pNode1 -> next = pNode;
    return *pList;
}

list deleteList(list * pList, int data, int position)
{
    Node *pNode = NULL, *pNode1 = *pList;
    int i = 1;
    if(position == 1)
    {
        *pList = (*pList) -> next;
        free(pNode1);
        return *pList;
    }
    if(position == SIZE + 1)
    {
        while(pNode1 -> next -> next != NULL)
            pNode1 = pNode1 -> next;
        free(pNode1 -> next);
        pNode1 -> next = NULL; 
        return *pList;
    }
    while(++ i != position)
        pNode1 = pNode1 -> next;
    Node *p = pNode1 -> next;
    pNode1 -> next = pNode1 -> next -> next;
    free(p);
    return *pList;
}

void traverse(list * plist, int (*pFun)(int * data))
{
    Node *pNode = *plist;
    while(pNode != NULL)
    {
        pFun(&pNode -> item);
        pNode = pNode -> next;
    }
}

int pFun1(int * data)
{
    (*data) ++;
    return 1;
}

int pFun2(int * data)
{
    (*data) *= 2;
    return 1;
}

int (*pFun[2])(int *data) = {pFun1, pFun2};