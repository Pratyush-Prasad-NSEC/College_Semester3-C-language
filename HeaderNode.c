#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* next;
};
struct HeaderNode{
    char data[100];
    struct Node* next; 
};
struct HeaderNode* header=NULL;
struct Node* head=NULL;

void init(){
   header=(struct HeaderNode*)malloc(sizeof(struct HeaderNode));
   if(header==NULL){
    printf("\nMEMORY ALLOCATION FAILED");
    exit(0);
   }

   scanf("%[^\n]s",header->data);
   header->next=head;
}

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
        printf("\nEMPTY LINKEDLIST");
        return;
    }

    printf(" LinkedList : ");
    struct Node* currNode=head;
    while(currNode!=NULL){
        printf("%d ",currNode->data);
        currNode=currNode->next;
    }
}

int main(){
    head=createNode(1);
    head->next=createNode(2);
    head->next->next=createNode(3);
    head->next->next->next=createNode(4);

    init();

    printf("%s ->",header->data);
    display();
    return 0;
}
