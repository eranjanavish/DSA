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

int normalCount = 0;
int tokenType[1000]; // 1 = Priority , 2 = Normal

Queue PriorityQueue;
Queue NormalQueue;
Queue MissQueue;


/* CREATE NODE */
Node* CREATE_NODE(int value)
{
    Node* NewNode = (Node*)malloc(sizeof(Node));
    NewNode->data = value;
    NewNode->prev = NULL;
    NewNode->next = NULL;
    return NewNode;
}


/* INITIALIZE QUEUE */
void INIT_QUEUE(Queue* Q)
{
    Q->front = NULL;
    Q->rear = NULL;
}


/* CHECK EMPTY */
int IS_EMPTY(Queue Q)
{
    return (Q.front == NULL);
}


/* CHECK TOKEN EXIST */
int TOKEN_EXISTS(Queue Q, int value)
{
    Node* current = Q.front;

    while (current != NULL)
    {
        if (current->data == value)
            return 1;
        current = current->next;
    }
    return 0;
}


/* ENQUEUE */
void ENQUEUE(Queue* Q, int value)
{

    Node* NewNode = CREATE_NODE(value);

    if (Q->front == NULL)
    {
        Q->front = NewNode;
        Q->rear = NewNode;
    }
    else
    {
        Q->rear->next = NewNode;
        NewNode->prev = Q->rear;
        Q->rear = NewNode;
    }
}


/* DEQUEUE */
int DEQUEUE(Queue* Q)
{

    if (Q->front == NULL)
    {
        printf("Queue Empty\n");
        return -1;
    }

    Node* temp = Q->front;
    int value = temp->data;

    Q->front = temp->next;

    if (Q->front != NULL)
        Q->front->prev = NULL;
    else
        Q->rear = NULL;

    free(temp);

    return value;
}


/* DISPLAY QUEUE */
void DISPLAY(Queue Q)
{

    Node* current = Q.front;

    if (current == NULL)
    {
        printf("Empty\n");
        return;
    }

    while (current != NULL)
    {
        printf("%d -> ", current->data);
        current = current->next;
    }

    printf("NULL\n");
}


/* CALL NEXT CUSTOMER */
void CALL_NEXT()
{

    if (!IS_EMPTY(PriorityQueue))
    {

        printf("\nServing Token: %d\n", DEQUEUE(&PriorityQueue));
        normalCount = 0;

    }
    else
    {

        if (normalCount < 2 && !IS_EMPTY(NormalQueue))
        {

            printf("\nServing Token: %d\n", DEQUEUE(&NormalQueue));
            normalCount++;

        }
        else if (!IS_EMPTY(MissQueue))
        {

            printf("\nServing Token: %d\n", DEQUEUE(&MissQueue));
            normalCount = 0;

        }
        else if (!IS_EMPTY(NormalQueue))
        {

            printf("\nServing Token: %d\n", DEQUEUE(&NormalQueue));

        }
        else
        {

            printf("\nNo Customers in Queue\n");

        }
    }
}


/* ADD MISSED TOKEN */
void ADD_TO_MISS_QUEUE(int value)
{

    /* check if token ever existed */
    if (tokenType[value] == 0)
    {
        printf("Error: Token was never in Priority or Normal queue\n");
        return;
    }

    /* prevent duplicates */
    if (TOKEN_EXISTS(PriorityQueue, value) ||
            TOKEN_EXISTS(NormalQueue, value) ||
            TOKEN_EXISTS(MissQueue, value))
    {

        printf("Token already exists in a queue!\n");
        return;
    }

    /* if it was priority -> give special facility */
    if (tokenType[value] == 1)
    {

        printf("Missed Priority Customer Added back to Priority Queue\n");
        ENQUEUE(&PriorityQueue, value);

    }
    else if (tokenType[value] == 2)
    {

        printf("Missed Normal Customer Added to Miss Queue\n");
        ENQUEUE(&MissQueue, value);

    }
}






    int main()
    {

        int choice, token, type;

        INIT_QUEUE(&PriorityQueue);
        INIT_QUEUE(&NormalQueue);
        INIT_QUEUE(&MissQueue);

        while (1)
        {

            system("cls");

            printf("\n====== Queue Management System ======\n");
            printf("1. Add Customer Token\n");
            printf("2. Add Missed Token\n");
            printf("3. Call Next Customer\n");
            printf("4. Display Queues\n");
            printf("5. Exit\n");
            printf("Enter choice: ");
            scanf("%d", &choice);

            switch (choice)
            {

            case 1:
                printf("Enter Token Number: ");
                scanf("%d", &token);

                printf("Enter Type (1 = Priority, 2 = Normal): ");
                scanf("%d", &type);

                if (TOKEN_EXISTS(PriorityQueue, token) ||
                        TOKEN_EXISTS(NormalQueue, token) ||
                        TOKEN_EXISTS(MissQueue, token))
                {

                    printf("Token already exists!\n");

                }
                else
                {

                    if (type == 1)
                    {
                        ENQUEUE(&PriorityQueue, token);
                        tokenType[token] = 1;
                    }
                    else if (type == 2)
                    {
                        ENQUEUE(&NormalQueue, token);
                        tokenType[token] = 2;
                    }
                    else
                    {
                        printf("Invalid Type!\n");
                    }
                }
                break;

            case 2:
                printf("Enter Missed Token Number: ");
                scanf("%d", &token);
                ADD_TO_MISS_QUEUE(token);
                break;

            case 3:
                CALL_NEXT();
                break;

            case 4:
                printf("\nPriority Queue: ");
                DISPLAY(PriorityQueue);

                printf("Normal Queue: ");
                DISPLAY(NormalQueue);

                printf("Miss Queue: ");
                DISPLAY(MissQueue);
                break;

            case 5:
                printf("\nExiting Program...\n");
                exit(0);

            default:
                printf("Invalid Choice\n");
            }

            printf("\nPress Enter to continue...");
            getchar();
            getchar();
        }

        return 0;
    }

