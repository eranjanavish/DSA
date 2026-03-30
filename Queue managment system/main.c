#include "queue.h"

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
        getchar(); // clear buffer
        getchar(); // wait for enter
    }

    return 0;
}
