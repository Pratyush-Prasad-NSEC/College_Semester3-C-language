#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
    struct Node* prev;
};
struct Node* head=NULL;

struct Node* createNode(int data){
    struct Node* temp=(struct Node*)malloc(sizeof(struct Node));

    if(temp==NULL){
        printf("\nMemory Allocation Failed!");
        exit(0);
    }

    temp->data=data;
    temp->next=NULL;
    temp->prev=NULL;
    return temp;
}

void display(int reverseFactor){
    if(head==NULL){
        printf("\nEMPTY LINKEDLIST");
        return;
    }
    printf("\n LinkedList : ");

    if(reverseFactor==0){
        struct Node* currNode=head;
        while(currNode!=NULL){
            printf("%d ",currNode->data);
            currNode=currNode->next;
        }
    }else{
        struct Node* currNode=head;
        while(currNode->next!=NULL){
            currNode=currNode->next;
        }

        while(currNode!=NULL){
            printf("%d ",currNode->data);
            currNode=currNode->prev;
        }
    }
}

void insertFirst(int data){
    struct Node* newNode=createNode(data);

    if(head==NULL){
        head=newNode;
        return;
    }

    head->prev=newNode;
    newNode->next=head;
    head=newNode;
}

void insertLast(int data){
    struct Node* newNode=createNode(data);

    if(head==NULL){
        head=newNode;
        return;
    }

    struct Node* currNode=head;
    while(currNode->next!=NULL){
        currNode=currNode->next;
    } 

    currNode->next=newNode;
    newNode->prev=currNode;
}

void deleteFirst(){
    if(head==NULL){
        printf("\nEMPTY LINKEDLIST");
        return;
    }

    if(head->next==NULL){
        head=NULL;
    }

    struct Node* temp=head;
    head=head->next;
    head->prev=NULL;
    
    free(temp);
    temp=NULL;
}

void deleteLast(){
    if(head==NULL){
        printf("\nEMPTY LINKEDLIST");
        return;
    }

    if(head->next==NULL){
        head=NULL;
    }

    struct Node* currNode=head;
    while(currNode->next!=NULL){
        currNode=currNode->next;
    }

    struct Node* temp=currNode;
    currNode->prev->next=NULL;

    free(temp);
    temp=NULL;
}

int search(int key){
    struct Node* currNode=head;
    int pos=1;

    while(currNode!=NULL){
        if(currNode->data==key){
            return pos;
        }
        pos++;
        currNode=currNode->next;
    }

    return -1;
}

int main(){
    display(0);
    insertFirst(1); insertFirst(2); insertFirst(3);
    display(0);
    insertLast(4); insertLast(5); insertLast(6);
    display(0);display(1);
    printf("\n %d ",search(4));
    deleteFirst(); deleteFirst();
    display(0);display(1);
    insertLast(7); insertFirst(12);
    deleteLast(); deleteLast();
    display(0);display(1);
    deleteLast(); deleteFirst(); deleteFirst(); deleteFirst(); deleteFirst();
}

