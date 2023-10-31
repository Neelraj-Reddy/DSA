#include<stdio.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>

struct msg_buffer{
    long msg_type;
    char msg[100];
}msgs;

int main(){
    key_t key=900;
    int msgid=msgget(key,IPC_CREAT|0666);
    msgs.msg_type=1;
    // printf("enter msg: ");
    // fgets(msgs.msg,1024,stdin);
    msgrcv(msgid,&msgs,sizeof(msgs),1,0);
    printf("message received is %s",msgs.msg);
}