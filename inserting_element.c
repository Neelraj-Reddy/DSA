#include<stdio.h>
#include<stdlib.h>

void display(int*,int);
int insert(int*,int,int,int);

int main(){
    int n,ele,pos,i;
    printf("enter array size : ");
    scanf("%d",&n);
    int *arr;
    arr=malloc(sizeof(int)*n);
    for (i=0;i<n;i++){
        printf("enter element %d : ",i+1);
        scanf("%d",&arr[i]);
    }
    display(arr,n);
    printf("\n");
    printf("enter position to insert (positioning starts from 0) : ");
    scanf("%d",&pos);
    printf("enter element to insert : ");
    scanf("%d",&ele);
    n=insert(arr,n,pos,ele);
    printf("%d \n",n);
    display(arr,n);
}

void display(int *arr,int n){
    int i;
    for (i=0;i<n;i++){
        printf("%d \t",arr[i]);
    }
}

int insert(int* arr,int n,int pos,int ele){
    int i=n;
    realloc(arr,sizeof(int)*(n+1));
    while(i!=0){
        if (i!=pos){
            arr[i]=arr[i-1];
        }
        if(i==pos){
            arr[i]=ele;
            break;
        }
        i--;
    }
    return n+1;
}
