#include<stdio.h>
static int arr[5];
static int top=-1;
void push(int data){
    if(top==4){
        printf("\nOVERFLOW");
        return;
    }

    arr[++top]=data;
    printf("\n%d PUSHED",data);
}

void pop(){
    if(top==-1){
        printf("\nUNDERFLOW");
        return;
    }

    top--;
    printf("\n%d POPED",arr[top+1]);
}

int peek(){
    if(top==-1){
        return -1;
    }else{
        return arr[top];
    }
}

void display(){
    if(top==-1){
        printf("\nEMPTY");
        return;
    }

    printf("\n STACK : ");
    for(int i=0;i<=top;i++){
        printf("%d ",arr[i]);
    }
}

int main(){
    printf("\n%d",peek());
    display();
    push(1); push(2); push(3); push(4); push(5); push(6);
    display();
    printf("\n%d",peek());
    pop(); pop(); display(); pop(); pop(); pop(); pop();
    return 0;
}
