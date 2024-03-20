#include<stdio.h>
#define SIZE 10
static int arr[SIZE];

void createArray(){
    printf("ENTER ELEMENTS IN ARRAY : \n");
    for(int i=0;i<SIZE;i++){
        printf("element (%d/10) -> ",i+1);
        scanf("%d",&arr[i]);
    }
}

int linearSearch(int key){
    for(int i=0;i<SIZE;i++){
        if(key==arr[i]){
            return i+1;
        }
    }

    return -1;
}

void display(){
    for(int i=0;i<SIZE;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}

int main(){
    createArray();
    printf("ARRAY : \n");
    display();

    printf("ENTER ELEMENT TO SEARCH : ");
    int key;
    scanf("%d",&key);

    int pos=linearSearch(key);
    if(pos==-1){
        printf("ELEMENT NOT FOUND");
    }else{
        printf("ELEMENT FOUND IN POSITION : %d",pos);
    }
}
