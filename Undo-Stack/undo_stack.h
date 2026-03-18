#ifndef UNDO_STACK_H
#define UNDO_STACK_H

#include "token.h"

struct stack_node {

    struct token *data;
    struct stack_node *next;
};

struct stack{

    struct stack_node *top;
    int size;
};

struct stack_node* create_node(struct token *t);
void initialize_stack(struct stack *s);
int is_empty(struct stack*s);
void push(struct stack *s , struct token *t);
struct token* pop(struct stack *s);
struct token* peek(struct stack *s);
void display_stack(struct stack *s);
int stack_size(struct stack *s);
void clear_stack(struct stack *s);


#endif
