#include<stdio.h>

int partition(int l,int h,int arr[]){
    int pivot=arr[l];
    int p=l;
    int q=h;
    
    while(p<q){
        while(arr[p]<=pivot && p<=q)p++;

        while(arr[q]>=pivot && p<=q)q--;

        if(p<q){
            int temp=arr[p];
            arr[p]=arr[q];
            arr[q]=temp;
        }else{
            int temp=arr[l];
            arr[l]=arr[q];
            arr[q]=temp;

            break;
        }
    }

    return q;
}

void quickSort(int l,int h,int arr[]){
    // int pi=partition(l,h,arr);
    // if(pi-1>l){
    //     quickSort(l,pi-1,arr);
    // }
    // if(pi+1<h){
    //     quickSort(pi+1,h,arr);
    // }

    if(l<h){
        int pi=partition(l,h,arr);
        quickSort(l,pi-1,arr);
        quickSort(pi+1,h,arr);
    }
}

int main(){
    int arr[]={6,7,4,8,2,3,1,2,5,9};

    quickSort(0,9,arr);

    for(int i=0;i<10;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}