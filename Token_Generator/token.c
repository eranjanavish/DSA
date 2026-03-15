#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct token
{
    int token_id;
    int phone_number;
    char nic[15];
    char name[20];
    char address[30];
    int priority;
    struct token *next;
    

};

struct token_list 
{
    struct token *head;
    struct token *tail;
    
};

void initialize_token_list(struct token_list *list){
    list->head=NULL;
    list->tail=NULL;
    printf("List Initialized succesfully!\n");
}

struct token* assign_id(int id){
    struct token *token;
    token = (struct token*)malloc(sizeof(struct token));
    token->token_id = id;
    token->next=NULL;
    return token;



}

void insert_token(struct token_list *list, struct token *token){
    if (list->head==NULL){
        list->head=token;
        list->tail=token;
        
        
    }
    else{
        struct token *temp = list->head;
        while( temp->next!=NULL){
            temp=temp->next;

        }
        temp->next = token;
        
        if (token->token_id==5){
            list->tail =token;
            
        }  
        
    }
    
}

void create_tokens_1_100(struct token_list *list){
    
    for(int i=1;i<=5;i++){
        struct token *token = assign_id(i);
        insert_token(list,token);
    }
    printf("Daily Tokens Created\n");
}

void Display(struct token_list *list){
    struct token *temp= list->head;
    printf("Display Tokens \n");
    while(temp!=NULL){
        printf("Token %d\n",temp->token_id);
        temp=temp->next;
    }
}

struct token* issue_token(struct token_list *list){
    if(list->head == NULL)
        {printf("Token Limit Reached\n");
        return NULL;}
    else{
    struct token *token = list->head;
    
    printf("Token No : %d\n",token->token_id);
    printf("Enter Customer name :");
    scanf("%s",token->name);
    printf("Enter Customer NIC :");
    scanf("%s",token->nic);
    printf("Enter Customer address :");
    scanf("%s",token->address);
    printf("Enter Customer Phone number :");
    scanf("%d",&token->phone_number);
    printf("Enter Priority level : (1-High , 2-Low) : ");
    scanf("%d",&token->priority);
    list->head=list->head->next;
    printf("Token Created\n");
    printf("\n\n\n\n\n\n\n\n\n\n");
    return token;
    }

}

char question_answer(char q[20]){
    char answer;

    printf("%s",q);
    scanf(" %c",&answer);
    return answer;

}



