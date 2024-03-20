#include<stdio.h>

int linearSearch(int arr[],int key){
    for(int i=0;i<5;i++){
        if(arr[i]==key){
            return i;
        }
    }

    return -1;
}

int main(){
    int arr[]={6,3,2,15,9};
    int key=15;
    int pos=linearSearch(arr,key);
    
    if(pos==-1){
        printf("NOT FOUND");
    }else{
        printf("FOUND IN POSITION : %d",pos);
    }
    
    return 0;
}
