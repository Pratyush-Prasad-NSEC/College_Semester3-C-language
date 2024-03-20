#include<stdio.h>
#define SIZE 5
static int arr[SIZE];
static int front=-1;
static int rear=-1;

void enqueueFirst(int data){
    if((front==0 && rear==SIZE-1)||(front-1==rear)){
        printf("\nOVERFLOW");
        return;
    }

    if(front==-1){
        front=rear=0;
    }else if(front==0){
        front=SIZE-1;
    }else{
        front--;
    }
    arr[front]=data;
    printf("\n%d INSERTED AT FIRST",data);
}

void enqueueLast(int data){
    if((front==0 && rear==SIZE-1)||(rear+1==front)){
        printf("\nOVERFLOW");
        return;
    }

    if(rear==-1){
        front=rear=0;
    }else if(rear==SIZE-1){
        rear=0;
    }else{
        rear++;
    }
    arr[rear]=data;
    printf("\n%d INSERTED AT LAST",data);
}

void dequeueFirst(){
    if(front==-1){
        printf("\nUNDERFLOW");
        return;
    }

    int temp=arr[front];
    if(front==rear){
        front=rear=-1;
    }else if(front==SIZE-1){
        front=0;
    }else{
        front++;
    }
    printf("\n%d DELETED FROM FIRST",temp);
}

void dequeueLast(){
    if(rear==-1){
        printf("\nUNDERFLOW");
        return; 
    }

    int temp=arr[rear];
    if(rear==front){
        front=rear=-1;
    }else if(rear==0){
        rear=SIZE-1;
    }else{
        rear--;
    }
    printf("\n%d DELETED FROM LAST",temp);
}

void display(){
    if(front==-1){
        printf("\nEMPTY");
        return;
    }

    printf("\n Queue : ");
    if(front<=rear){
        for(int i=0;i<=rear;i++){
            printf("%d ",arr[i]);
        }
    }else{
        for(int i=front;i<SIZE;i++){
            printf("%d ",arr[i]);
        }
        for(int i=0;i<=rear;i++){
            printf("%d ",arr[i]);
        }
    }
}

int main(){
    display();
    enqueueFirst(1); enqueueFirst(2); enqueueFirst(3);
    display();
    enqueueLast(4); enqueueLast(5); enqueueLast(6);
    display();
    dequeueFirst();
    display();
    dequeueLast();
    display();
    dequeueFirst(); dequeueFirst(); dequeueFirst(); dequeueFirst();

}