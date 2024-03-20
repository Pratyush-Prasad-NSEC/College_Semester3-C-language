#include<stdio.h>

void mergeSort(int a1,int a2,int b1,int b2,int arr[]){
    int size=b2-a1+1;
    int temp[size];
    int p=a1;
    int q=b1;
    int count=0;

    while(p<=a2 && q<=b2){
        if(arr[p]<=arr[q]){
            temp[count]=arr[p];
            p++;
        }else{
            temp[count]=arr[q];
            q++;
        }
        count++;
    }

    while(p<=a2){
        temp[count]=arr[p];
        count++;p++;
    }

    while(q<=b2){
        temp[count]=arr[q];
        count++;q++;
    }

    for(int i=0;i<size;i++){
        arr[a1+i]=temp[i];
    }
}

void divideConquer(int l,int h,int arr[]){
    if(l<h){
        int mid=l-((l-h)/2);

        divideConquer(l,mid,arr);
        divideConquer(mid+1,h,arr);

        mergeSort(l,mid,mid+1,h,arr);
    }
}

int main(){
    int arr[]={6,7,4,8,2,3,1,2,5,9};

    divideConquer(0,9,arr);

    for(int i=0;i<10;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}