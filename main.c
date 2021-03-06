#include "list.h"
#include <time.h>

int main( void )
{
    int i, data;
    Node *temp;
    srand((unsigned)time(NULL));
    list myList;

    //create
    initializeList(&myList);
    printf("Input:\n");
    for( i = 0; i < SIZE; i++)
    {
        data = rand() % 100 + 1;
        printf("%d ", data);
        appendList(data, &myList);
    }
    printf("\n");
    printf("Createlist:\n");
    displayList(myList);

    //insert
    int position;
    data = rand() % 100 + 1;
    printf("insertData: %d\n", data);
    position = rand() % (SIZE + 1) + 1;
    printf("insertPosition: %d\n", position);
    myList = insertList(&myList, data, position);
    printf("InsertList:\n");
    displayList(myList);

    //delete
    data = rand() % 100 + 1;
    printf("deleteData: %d\n", data);
    position = rand() % (SIZE + 1) + 1;
    printf("deletePosition: %d\n", position);
    myList = deleteList(&myList, data, position);
    printf("InsertList\n");
    displayList(myList);

    //traverse
    traverse(&myList, pFun[0]);
    displayList(myList);
    
    //free
    freeList(&myList);
    return 0;
}