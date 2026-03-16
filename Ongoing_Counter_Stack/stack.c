struct StackNode{
    int token;
    struct StackNode*next;
};

struct StackNode*top = NULL;

void push(int token){
    struct StackNode* newNode = (struct StackNode*)malloc(sizeof(struct StackNode));

    newNode->token = token;
    newNode->token = top;
    top= newNode;

    printf("Token %d accepted and pushed to stack\n",token);

}

void pop(){

    if(top==NULL){
        printf("Stack Empty.No token to remove.\n");
        return;
    }
    struct StackNode*temp = top;

    printf("Removed Token: %d\n",top->token);

    top=top->next;
    free(temp);
}

void display(){
    struct StackNode*temp=top;

    if(temp==NULL){
        printf("Stack Empty\n");
        return;
    }

    printf("Counter Token Stack:\n");


    while(temp !=NULL){
        printf("Token %d\n",temp->token);
        temp= temp->next;
    }
}

int main(){

    push(1);
    push(2);
    push(3);

    display();

    return 0;
}