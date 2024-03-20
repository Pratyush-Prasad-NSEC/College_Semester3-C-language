#include<stdio.h>
#define PRIORITIES 5
#define SIZE 3
int arr[PRIORITIES][SIZE];
int FR[PRIORITIES][2];

void init(){
    for(int i=0;i<PRIORITIES;i++){
        for(int j=0;j<2;j++){
            FR[i][j]=-1;
        }
    }
}

void enqueue(int data,int priority){
    int front=FR[priority][0];
    int rear=FR[priority][1];

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
    FR[priority][0]=front;
    FR[priority][1]=rear;

    arr[priority][rear]=data;
    printf("\n%d INSERTED",data);
}

void dequeue(){
    int priority;
    for(int i=0;i<PRIORITIES;i++){
        if(FR[i][0]!=-1){
            priority=i;
            break;
        }
    }

    int front=FR[priority][0];
    int rear=FR[priority][1];
    if(front==-1){
        printf("\nUNDERFLOW");
        return;
    }

    int temp=arr[priority][front];
    if(front==rear){
        front=rear=-1;
    }else if(front==SIZE-1){
        front=0;
    }else{
        front++;
    }
    FR[priority][0]=front;
    FR[priority][1]=rear;
    printf("\n%d DELETED",temp);
}

void auxDisplay(int priority){
    printf("\n Queue : ");
    
    int front=FR[priority][0];
    int rear=FR[priority][1];

    if(front<=rear){
        for(int i=0;i<=rear;i++){
            printf("%d ",arr[priority][i]);
        }
    }else{
        for(int i=front;i<SIZE;i++){
            printf("%d ",arr[priority][i]);
        }
        for(int i=0;i<=rear;i++){
            printf("%d ",arr[priority][i]);
        }
    }
}

void display(){
    for(int i=0;i<PRIORITIES;i++){
        if(FR[i][0]==-1){
            printf("\n EMPTY");
        }else{
            auxDisplay(i);
        }
    }
}

int main(){
    init();

    enqueue(5,2); enqueue(1,1); enqueue(2,1); enqueue(3,1); enqueue(4,1); enqueue(4,2);
    display();
    enqueue(16,3); enqueue(14,4); enqueue(66,0);
    display();
    dequeue(); dequeue();
    enqueue(55,1);
    display();
}

