#include<stdio.h>

int binarySearch(int arr[],int key){
    int u=0;
    int v=7;

    while(u<=v){
        int mid=u-(u-v)/2;

        if(arr[mid]==key){
            return mid;
        }else if(key>arr[mid]){
            u=mid+1;
        }else{
            v=mid-1;
        }
    }

    return -1;
}

int main(){
    int arr[]={2,3,6,9,14,22,43,54};
    int key=54;
    int pos=binarySearch(arr,key);
    
    if(pos==-1){
        printf("NOT FOUND");
    }else{
        printf("FOUND IN POSITION : %d",pos);
    }
    return 0;
}