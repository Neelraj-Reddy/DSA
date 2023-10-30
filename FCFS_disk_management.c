#include<stdio.h>

int main(){
    int n_r,header;
    printf("enter head position : ");
    scanf("%d",&header);
    printf("enter no of requests : ");
    scanf("%d",&n_r);
    int count_cylinder=0;
    printf("Enter service request below : \n");
    for(int i=0;i<n_r;i++){
        int ele;
        scanf("%d",&ele);
        count_cylinder+=(header-ele>0)?(header-ele):(ele-header);
        header=ele;
    }
    printf(" the cylinder shift required is : %d \n",count_cylinder);
}