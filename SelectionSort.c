#include<stdio.h>

int main(){
    int arr[]={6,7,4,8,2,3,1,2,5,9};

    for(int i=0;i<9;i++){
        int min=arr[i];
        int pos=i;
        for(int j=i+1;j<10;j++){
            if(arr[j]<min){
                min=arr[j];
                pos=j;
            }
        }

        int temp=arr[i];
        arr[i]=arr[pos];
        arr[pos]=temp;
    }

    for(int i=0;i<10;i++){
        printf("%d ",arr[i]);
    }
}