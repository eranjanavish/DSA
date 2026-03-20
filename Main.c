#include <stdio.h>
#include <stdlib.h>
#include "Token_Generator/token.h"
#include "Undo_Stack/undo_stack.h" 

// use this commnad to run the c file -  gcc main.c ./Token_Generator/token.c -o token_program
//And then -  ./token_program     
int main(){
    

        struct token_list list;
        initialize_token_list(&list);
        create_tokens_1_100(&list);
    
        
    
        
        
        //Starts the program
        while(1){

        printf("====== Office Managment System ======\n");
        printf("1. Issue a Token\n");
        printf("2. Counter Operator Access\n");
        printf("3. Department Manager Access\n");
        printf("4. Completed Service Records\n");
        printf("5. Exit\n");

        
        int choice;
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
            printf("Option 1 Selected\n");
            struct token *token = issue_token(&list);

            //Here the coutnter managment system checks the counters and sort them according to the number of tokens each counter service right now (ascending order)

            //Counter A - 25 tokens,  counter B - 5 tokens -> after sorting -> counter B - 5, Counter A - 25 tokens

            // we select the counter and pass the token to the counters queue
            //
            break;

            case 2:
                printf("Option 2 Selected");

                 run_undo_menu(&undo_stack,
                  &list,
                  counter_head,
                  counter_count);

                //Counter operator selects the counter and start giving service to the tokens

                //if a token is missing add it to the missing list

                //wrong tokens will get deleted

                //At the end of the day all the tokens which are completed will go to the completed list
                break;

            case 3:
            printf("Option 3 Selected");

            //Avtive service records are visible to the managers.

            break;
;

            case 4:
            printf("Option 4 Selected");
            //completed service records
            break;


            

            case 5:
                printf("\nExiting Program...\n");
                exit(0);

            default:
                printf("Invalid Choice\n");
        }
    }
        
    
    }

