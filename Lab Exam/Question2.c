#include<stdio.h>
#define SIZE 10
static int pos,arr[SIZE],size=SIZE;

void createArray(){
    printf("ENTER ELEMENTS IN ARRAY : \n");
    for(int i=0;i<SIZE;i++){
        printf("\nelement : (%d/10) ",i+1);
        scanf("%d",&arr[i]);
    }
}

void delete(){
    for(int i=pos-1;i<SIZE-1;i++){
        arr[i]=arr[i+1];
    }
}

void display(){
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}

int main(){
    createArray();
    printf("ORIGINAL ARRAY : \n");
    display();

    printf("ENTER POSITION TO DELETE : (Index starting from 1)");
    scanf("%d",&pos);
    delete();size--;
    printf("AFTER DELETING : \n");
    display();

    return 0;
}