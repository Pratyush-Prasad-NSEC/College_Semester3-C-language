#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};
static struct Node* head=NULL;

struct Node* createNode(int data){
    struct Node* temp=(struct Node*)malloc(sizeof(struct Node));

    if(temp==NULL){
        printf("\nMEMORY ALLOCATION FAILED!");
        exit(0);
    }

    temp->data=data;
    temp->next=NULL;

    return temp;
}

void display(){
    if(head==NULL){
        printf("\nEMPTY STACK");
        return;
    }

    printf("\n STACK : ");
    struct Node* currNode=head;
    while(currNode!=NULL){
        printf("%d ",currNode->data);
        currNode=currNode->next;
    }
}

void insertFirst(int data){
    struct Node* newNode=createNode(data);

    if(head==NULL){
        head=newNode;
        return;
    }

    newNode->next=head;
    head=newNode;
}

void deleteFirst(){
    if(head==NULL){
        printf("\n UNDERFLOW");
        return;
    }
    struct Node* temp=head;
    head=head->next;
    free(temp);
    temp=NULL;
}

void push(int data){
    insertFirst(data);
}

void pop(){
    deleteFirst();
}

int peek(){
    if(head==NULL){
        return -1;
    }

    return head->data;
}

int main(){
    printf("\n %d ",peek());
    display();
    push(1); push(2); push(3); push(4); push(5); push(6);
    display();
    printf("\n %d ",peek());
    pop(); pop(); display(); pop(); pop(); pop(); pop();
    return 0;
}