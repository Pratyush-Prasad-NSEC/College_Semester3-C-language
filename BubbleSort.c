#include<stdio.h>

int main(){
    int arr[]={6,7,4,8,2,3,1,2,5,9};

    for(int i=0;i<10;i++){
        int swap=0;
        for(int j=0;j<10-i-1;j++){
            if(arr[j]>arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;

                swap=1;
            }
        }

        if(swap==0){
            break;
        }
    }

    for(int i=0;i<10;i++){
        printf("%d ",arr[i]);
    }
}