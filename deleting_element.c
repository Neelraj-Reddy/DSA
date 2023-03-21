#include<stdio.h>
#include<stdlib.h>

void display(int*,int);
int delete(int*,int,int);

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
    printf("enter positiont to delete (1. start , 2. specific ,3. end) : ");
    scanf("%d",&pos);

    if (pos==1){
        pos=0;
      }
    else if(pos==2){
        printf("indexing starts from 0 . \nenter specific position : ");
        scanf("%d",&pos);
    }
    else if(pos==3){
        pos=n;
    }
    else
    ("enter wrong option printed");
    
    n=delete(arr,n,pos);
    printf("array after deleteion is :- \n");
    display(arr,n);
}

void display(int *arr,int n){
    int i;
    for (i=0;i<n;i++){
        printf("%d \t",arr[i]);
    }
}

int delete(int* arr,int n,int pos){
    int i=n;
    for(i=pos;i<n;i++){
      arr[i]=arr[i+1];
    }
    realloc(arr,sizeof(int)*(n-1));
    return n-1;
}

