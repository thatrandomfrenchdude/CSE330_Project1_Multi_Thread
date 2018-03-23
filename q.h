//
//  main.h
//  cse330_P1
//
//  Created by Nicholas Debeurre on 9/5/17.
//  Copyright © 2017 Debeurre. All rights reserved.
//

#include <stdlib.h>
#include "tcb.h"

#ifndef q_h
#define q_h

//struct declarations
//Queue element
//typedef struct qE
//{
//    int qInt;
//    struct qE *next;
//    struct qE *prev;
//} qE;

//forward declaration
TCB_t *NewItem();
void InitQueue(TCB_t **newQ);
void AddQueue(TCB_t **currQ, TCB_t *itemToAdd);
TCB_t *DelQueue(TCB_t **currQ);
void RotateQ(TCB_t **headPtr);
void printQ(TCB_t **Q);

TCB_t *NewItem()
{
    TCB_t *newNode = (TCB_t*)malloc(sizeof(TCB_t));
    newNode -> next = NULL;
    newNode -> prev = NULL;
    return newNode;
}

//initializes an empty Queue where the head and tail are the same
void InitQueue(TCB_t **newQ)
{
    *newQ = NULL;
}

void AddQueue(TCB_t **currQ, TCB_t *itemToAdd)
{
    if (*currQ == NULL)
    {
        *currQ = itemToAdd;
        itemToAdd -> next = *currQ;
        itemToAdd -> prev = *currQ;
    }
    else
    {
        itemToAdd -> next = *currQ;
        itemToAdd -> prev = (*currQ) -> prev;
        (*currQ) -> prev -> next = itemToAdd;
        (*currQ) -> prev = itemToAdd;
    }
}

TCB_t *DelQueue(TCB_t **currQ)
{
    TCB_t *temp = *currQ;
    (*currQ) -> prev -> next = (*currQ) -> next;
    (*currQ) -> next -> prev = (*currQ) -> prev;
    *currQ = (*currQ) -> next;
    
    temp -> next = NULL;
    temp -> prev = NULL;
    return temp;
}

void RotateQ(TCB_t **headPtr)
{
    *headPtr = (*headPtr) -> next;
}

//void printQ(TCB_t **Q)
//{
//    TCB_t *temp = *Q;
//    if (temp != NULL)
//    {
//        while (temp -> next != *Q)
//        {
//            printf("%d ", temp -> context);
//            temp = temp -> next;
//        }
//        printf("%d\n", temp -> context);
//    }
//    else
//        printf("Queue is empty");
//}

#endif /* q_h */
