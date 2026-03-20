#ifndef UNDO_STACK_H
#define UNDO_STACK_H

#include "token.h"
#include "queue.h"

/*(until counter.h is ready)*/
typedef struct Counter Counter;
void assignToken(Counter* head, int n, int token);


struct stack_node {
    struct token *data;
    struct stack_node *next;
};


struct stack {
    struct stack_node *top;
    int size;
};


void initialize_stack(struct stack *s);
struct stack_node* create_node(struct token *t);
int is_empty(struct stack *s);
void push(struct stack *s, struct token *t);
struct token* pop(struct stack *s);
struct token* peek(struct stack *s);
void display_stack(struct stack *s);
int stack_size(struct stack *s);
void clear_stack(struct stack *s);
void run_undo_menu(struct stack *s,
                   struct token_list *list,
                   Counter *counter_head,
                   int counter_count);

#endif
