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
        printf("MEMORY ALLOCATION FAILED");
        exit(0);
    }

    temp->data=data;
    temp->next=NULL;
    return temp;
}

void insertBeginning(int data){
    struct Node* newNode=createNode(data);

    if(head==NULL){
        head=newNode;
    }else{
        newNode->next=head;
        head=newNode;
    }
}

void display(){
    struct Node* currNode=head;
    while(currNode!=NULL){
        printf("%d -> ",currNode->data);
        currNode=currNode->next;
    }
    printf("NULL \n");
}

int main(){
    insertBeginning(10);
    insertBeginning(20);
    insertBeginning(30);

    display();

    return 0;
}