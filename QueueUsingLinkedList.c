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
        printf("\nEMPTY QUEUE");
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

void deleteLast(){
    if(head==NULL){
        printf("\n EMPTY STACK");
        return;
    }

    struct Node* temp;
    if(head->next==NULL){
        temp=head;
        head=NULL;
        return;
    }

    struct Node* currNode=head;
    while(currNode->next->next!=NULL){
        currNode=currNode->next;
    }
    temp=currNode->next;
    currNode->next=NULL;

    free(temp);
    temp=NULL;
}

void enqueue(int data){
    insertFirst(data);
}

void dequeue(){
    deleteLast();
}

int main(){
    display();
    enqueue(1); enqueue(2); enqueue(3); enqueue(4); enqueue(5); enqueue(6);
    display();
    dequeue(); dequeue(); dequeue(); 
    display(); 
    dequeue(); dequeue(); dequeue();
    return 0;
}
