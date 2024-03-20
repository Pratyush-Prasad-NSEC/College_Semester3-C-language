#include<stdio.h>
#define SIZE 5
static int arr[SIZE];
static int front=-1;
static int rear=-1;

void enqueue(int data){
    if(rear==SIZE-1){
        printf("\nOVERFLOW");
        return;
    }
    
    if(rear==-1){
        front=rear=0;
    }else{
        rear++;
    }
    arr[rear]=data;
    printf("\n%d INSERTED",data);
}

void dequeue(){
    if(front==-1){
        printf("\nUNDERFLOW");
        return;
    }

    int temp=arr[front];
    if(front==rear){
        front=rear=-1;
    }else{
        front++;
    }
    printf("\n%d DELETED",temp);
}

void display(){
    if(front==-1){
        printf("\nEMPTY");
        return;
    }

    printf("\n QUEUE : ");
    for(int i=front;i<=rear;i++){
        printf("%d ",arr[i]);
    }
}

int main(){
    display();
    enqueue(1); enqueue(2); enqueue(3); enqueue(4); enqueue(5); enqueue(6);
    display();
    dequeue(); dequeue(); dequeue(); display(); dequeue(); dequeue(); dequeue();
    return 0;
}