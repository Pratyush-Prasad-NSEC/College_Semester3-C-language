#include<stdio.h>

void heapify(int i,int n,int arr[]){
    int largest=i;
    int l=2*i+1;
    int r=2*i+2;

    if(l<=n && arr[l]>largest){
        largest=l;
    }
    if(r<=n && arr[r]>largest){
        largest=r;
    }

    if(largest!=i){
        int temp=arr[i];
        arr[i]=arr[largest];
        arr[largest]=temp;

        heapify(largest,n,arr);
    }
}

void buildHeap(int arr[],int n){
    for(int i=n/2;i>=0;i++){
        heapify(i,n,arr);
    }
}

void heapSort(int arr[],int n){
    buildHeap(arr,n);

    for(int i=n;i>=1;i--){
        int temp=arr[0];
        arr[0]=arr[n];
        arr[n]=temp;

        heapify(0,i-1,arr);
    }
}

int main(){
    int arr[]={6,7,4,8,2,3,1,2,5,9};

    heapSort(arr,9);

    for(int i=0;i<10;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}