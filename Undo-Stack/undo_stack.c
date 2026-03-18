#include <stdio.h>
#include <stdlib.h>
#include "undo_stack.h"



void initialize_stack(struct stack *s){

    s->top = NULL;
    s->size = 0;
    printf("Undo Stack initialized!\n");
}

struct stack_node* create_node(struct token *t){
    struct stack_node *new_node = (struct stack_node*)malloc(sizeof(struct stack_node));
        if(new_node == NULL) {
            printf("Memory allocation failed!\n");
            return NULL;
        }
        new_node->data = t;
        new_node->next = NULL;

        return new_node;
};

int is_empty(struct stack *s){

    return s->top == NULL;

}

void push (struct stack *s, struct token *t){

    struct stack_node *new_node = create_node(t);
    if(new_node == NULL ) return;
    new_node->next = s->top;
    s->top = new_node;
    s->size++;
    printf("Token %d pushed to undo stack !\n", t->token_id);

};

struct token* pop (struct stack *s){

    if(is_empty(s)){
        printf("No tokens to undo!\n");
        return NULL;
        }

        struct stack_node *temp = s->top;
        struct token*t = temp->data;
        s->top = s->top->next;
        free(temp);
        s->size--;
        printf("Token %d undone successfully!", t->token_id);
        return t;

};


struct token *peek(struct stack *s){

    if(is_empty(s)){
        printf("Stack is empty! No tokens issued yet.\n");
        return NULL;
    }
    return s->top->data;

};


void display_stack(struct stack *s){

    if(is_empty(s)){
        printf("stack is empty!\n");
        return;
    }

    struct stack_node *temp = s->top;
    printf("\n==================================\n");
    printf("  UNDO STACK (TOP TO BOTTOM) \n");
    printf("\n==================================\n");
    while( temp!= NULL){

        printf("TOken ID    :%d\n", temp->data->token_id);
        printf("Name        :%s\n", temp->data->name);
        printf("NIC         :%s\n", temp->data->nic);
        printf("Address     :%s\n", temp->data->address);
        printf("Phone       :%d\n", temp->data->phone_number);
        printf("Priority    :%d\n", temp->data->priority);
        printf("------------------------------");
        temp = temp->next;
    }

}

int stack_size(struct stack *s){

    return s->size;
}

void clear_stack(struct stack *s){

    while (!is_empty(s)){
        struct stack_node *temp = s->top;
        s->top = s->top->next;
        free(temp);
    }
    s->size = 0;
    printf("Stack cleared! System reset. \n");
}
