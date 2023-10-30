#include<stdio.h>
#include<math.h>

void best_block_index(int ele,int *process_size,int size){
    int diff=9999;
    int curr=0;
    int index=0;
    for(int i=0;i<size;i++){
        if(process_size[i]>ele){
            if(process_size[i]-ele<diff){
                diff=process_size[i]-ele;
                curr=process_size[i];
                index=i;
            }
        }
    }
    process_size[index]=99999;
    if(curr==0){
        printf("%d goes in starvation \n",ele);
    }
    else{
        printf("%d goes in %d \n",ele,curr);
    }
}

void main(){
    int process_size[5]={100,500,200,300,600};
    int block_size[4]={212,417,112,626};
    for(int i=0;i<4;i++){
        best_block_index(block_size[i],process_size,5);
    }

}