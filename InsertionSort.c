#include<stdio.h>

int main(){
    int arr[]={6,7,4,8,2,3,1,2,5,9};

    for(int i=1;i<10;i++){
        int temp=arr[i];
        int j=i-1;
        while(j>=0 && temp<arr[j]){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=temp;
    }

    for(int i=0;i<10;i++){
        printf("%d ",arr[i]);
    }
}