#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "undo_stack.h"


void initialize_stack(struct stack *s) {
    s->top  = NULL;
    s->size = 0;
    printf("Stack Initialized!\n");
}


struct stack_node* create_node(struct token *t) {
    struct stack_node *new_node = (struct stack_node*)
        malloc(sizeof(struct stack_node));
    if (new_node == NULL) {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    new_node->data = t;
    new_node->next = NULL;
    return new_node;
}

int is_empty(struct stack *s) {
    return s->top == NULL;
}


void push(struct stack *s, struct token *t) {
    struct stack_node *new_node = create_node(t);
    if (new_node == NULL) return;
    new_node->next = s->top;
    s->top  = new_node;
    s->size++;
    printf("Token %d pushed to Stack!\n",
        t->token_id);
}


struct token* pop(struct stack *s) {
    if (is_empty(s)) {
        printf("Stack is empty!\n");
        return NULL;
    }
    struct stack_node *temp = s->top;
    struct token      *t    = temp->data;
    s->top = s->top->next;
    free(temp);
    s->size--;
    return t;
}


struct token* peek(struct stack *s) {
    if (is_empty(s)) {
        printf("Stack is empty!\n");
        return NULL;
    }
    return s->top->data;
}

void display_stack(struct stack *s) {
    if (is_empty(s)) {
        printf("No rejected tokens today!\n");
        return;
    }
    struct stack_node *temp = s->top;
    printf("\n=============================\n");
    printf("    REJECTED TOKENS TODAY\n");
    printf("=============================\n");
    while (temp != NULL) {
        printf("Token ID  : %d\n", temp->data->token_id);
        printf("Name      : %s\n", temp->data->name);
        printf("NIC       : %s\n", temp->data->nic);
        printf("Address   : %s\n", temp->data->address);
        printf("Phone     : %d\n", temp->data->phone_number);
        printf("Priority  : %d\n", temp->data->priority);
        printf("-----------------------------\n");
        temp = temp->next;
    }
    printf("Total rejected : %d\n", s->size);
    printf("=============================\n");
}


int stack_size(struct stack *s) {
    return s->size;
}


void clear_stack(struct stack *s) {
    while (!is_empty(s)) {
        struct stack_node *temp = s->top;
        s->top = s->top->next;
        free(temp);
    }
    s->size = 0;
    printf("Stack cleared!\n");
}


void run_undo_menu(struct stack *s,
                   struct token_list *list,
                   Counter *counter_head,
                   int counter_count) {

    int choice;
    int confirm_choice;

    while (1) {

        printf("\n=============================\n");
        printf("     UNDO STACK SYSTEM\n");
        printf("=============================\n");
        printf("1. Load Next Token from Queue\n");
        printf("2. Display Rejected Tokens\n");
        printf("3. Stack Size\n");
        printf("4. Clear Stack\n");
        printf("5. Back to Main Menu\n");
        printf("=============================\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {


            case 1:
            {
                int token_id = -1;


                if (!IS_EMPTY(PriorityQueue)) {
                    token_id = DEQUEUE(&PriorityQueue);
                    printf("\nLoaded from Priority Queue.\n");

                } else if (!IS_EMPTY(NormalQueue)) {
                    token_id = DEQUEUE(&NormalQueue);
                    printf("\nLoaded from Normal Queue.\n");

                } else if (!IS_EMPTY(MissQueue)) {
                    token_id = DEQUEUE(&MissQueue);
                    printf("\nLoaded from Miss Queue.\n");

                } else {
                    printf("\nAll queues are empty!\n");
                    printf("No tokens waiting.\n");
                    break;

                }


                struct token *t = find_token_by_id(list, token_id);

                if (t == NULL) {
                    printf("Token %d details not found!\n",token_id);
                    break;
                }


                push(s, t);


                printf("\n=============================\n");
                printf("      TOKEN DETAILS\n");
                printf("=============================\n");
                printf("Token ID  : %d\n", t->token_id);
                printf("Name      : %s\n", t->name);
                printf("NIC       : %s\n", t->nic);
                printf("Address   : %s\n", t->address);
                printf("Phone     : %d\n", t->phone_number);
                printf("Priority  : %d\n", t->priority);
                printf("=============================\n");
                printf("1. Confirm — Send to Counter\n");
                printf("2. Decline — Reject Token\n");
                printf("=============================\n");
                printf("Enter choice: ");
                scanf("%d", &confirm_choice);

                if (confirm_choice == 1) {


                    struct token *confirmed = pop(s);
                    assignToken(counter_head,
                        counter_count,
                        confirmed->token_id);
                    printf("\nToken %d confirmed!\n",
                        confirmed->token_id);
                    printf("Sent to counter successfully.\n");

                } else {


                    printf("\nToken %d declined!\n", token_id);
                    printf("Saved as rejected token.\n");
                    printf("View at end of day report.\n");
                }
                break;
            }


            case 2:
                display_stack(s);
                break;


            case 3:
                printf("\nTotal rejected tokens : %d\n",
                    stack_size(s));
                break;

            case 4:
                printf("\n=============================\n");
                printf("     END OF DAY REPORT\n");
                printf("=============================\n");
                display_stack(s);
                clear_stack(s);
                printf("System is reset successfully !\n");
                break;

            case 5:
                return;

            default:
                printf("Invalid choice!\n");
        }
    }
}
