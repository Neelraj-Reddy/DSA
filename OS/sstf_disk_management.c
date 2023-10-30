#include<stdio.h>
#include<math.h>

int min(int*req_array,int current,int size){
    int ele=999;
    int diff=999;
    int ind=0;
    for(int i=0;i<size;i++){
        if(abs(current-req_array[i])<diff){
            diff=abs(current-req_array[i]);
            ele=req_array[i];
            ind=i;
        }
    }
    req_array[ind]=999;
    return ele;
}

void main(){
    int n_r,header;
    printf("enter head position : ");
    scanf("%d",&header);
    printf("enter no of requests : ");
    scanf("%d",&n_r);
    int req_array[header];
    for(int i=0;i<n_r;i++){
        scanf("%d",&req_array[i]);
    }

    int cylinder=0;

    for(int i=0;i<n_r;i++){
        int ele;
        ele=min(req_array,header,n_r);
        cylinder+=abs(header-ele);
        header=ele;
    }

    printf("cylinder value : %d \n",cylinder);
}