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
        printf("\nEMPTY LINKEDLIST");
        return;
    }

    printf("\n LinkedList : ");
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
}

void deleteFirst(){
    if(head==NULL){
        printf("\n EMPTY LINKEDLIST");
        return;
    }
    struct Node* temp=head;
    head=head->next;
    free(temp);
    temp=NULL;
}

void deleteLast(){
    if(head==NULL){
        printf("\n EMPTY LINKEDLIST");
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
    insertFirst(1); insertFirst(2); insertFirst(3);
    display();
    insertLast(4); insertLast(5); insertLast(6);
    display();
    printf("\n %d ",search(4));
    deleteFirst(); deleteFirst();
    display();
    insertLast(7); insertFirst(12);
    deleteLast(); deleteLast();
    display();
    deleteLast(); deleteFirst(); deleteFirst(); deleteFirst(); deleteFirst();
}