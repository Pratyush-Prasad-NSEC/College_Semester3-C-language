#include<stdio.h>
#define SIZE 5
static int arr[SIZE];
static int front=-1;
static int rear=-1;

void enqueue(int data){
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
    }else if(front==SIZE-1){
        front=0;
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
    enqueue(1); enqueue(2); enqueue(3); enqueue(4); enqueue(5); enqueue(6);
    display();
    dequeue(); dequeue();
    enqueue(6); enqueue(7); enqueue(8);
    display();
    dequeue(); display(); dequeue(); dequeue(); dequeue();dequeue(); dequeue();
    return 0; 
}
