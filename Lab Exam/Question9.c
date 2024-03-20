#include <stdio.h>
#include<stdlib.h>

#define SIZE 10
static int arr[SIZE],top=-1;

void insert(){
    if(top==SIZE-1){
        printf("STACK OVERFLOW\n");
    }else{
        int data;
        top++;
        printf("ENTER DATA TO INSERT : ");
        scanf("%d",&data);
        arr[top]=data;
        printf("%d PUSHED\n",data);
    }
}

void delete(){
    if(top==-1){
        printf("STACK UNDERFLOW\n");
    }else{
        printf("%d POPED\n",arr[top]);
        top--;
    }
}

void display(){
    if(top==-1){
        printf("STACK IS EMPTY.....\n");
    }else{
        for(int i=0;i<=top;i++){
            printf("%d ",arr[i]);
        }
        printf("\n");
    }
}

int main(){
    int choice;
    while(1){
        printf("\n\nMENU : \n1 FOR INSERTING \n2 FOR DELETING \n3 FOR DISPLAYING \n4 TO EXIT\n");
        scanf("%d",&choice);
        switch (choice){
            case 1: insert();break;
            case 2: delete();break;
            case 3: display();break;
            case 4: exit(0);
            default:printf("WRONG INPUT PLEASE RE-ENTER \n");
        }
    }

    return 0;
}