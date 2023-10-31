#include<stdio.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>

int main(){
    key_t key=ftok("progfile",65);
    int shmid=shmget(key,1024,IPC_CREAT|0666);
    char *str=shmat(shmid,NULL,0);
    printf("message from memory is %s",str);
    shmdt(str);
}