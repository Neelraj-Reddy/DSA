// Online C compiler to run C program online
#include <stdio.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>

int main() {
    key_t key = ftok("progfile",35);
    int shmid=shmget(key,1024,IPC_CREAT|0666);
    char *array=shmat(shmid,NULL,0);
    printf("Write data : ");
    fgets(array,50,stdin);
    printf("Data written in memory is %s",array);
    shmdt(array);
}