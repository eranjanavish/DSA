#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>
#include <stdlib.h>


typedef struct Node
{
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

typedef struct Queue
{
    Node* front;
    Node* rear;
} Queue;




extern int normalCount;
extern int tokenType[1000];

extern Queue PriorityQueue;
extern Queue NormalQueue;
extern Queue MissQueue;




/* Node */
Node* CREATE_NODE(int value);

/* Queue Operations */
void INIT_QUEUE(Queue* Q);
int IS_EMPTY(Queue Q);
int TOKEN_EXISTS(Queue Q, int value);

void ENQUEUE(Queue* Q, int value);
int DEQUEUE(Queue* Q);

void DISPLAY(Queue Q);

/* System Functions */
void CALL_NEXT();
void ADD_TO_MISS_QUEUE(int value);


#endif
