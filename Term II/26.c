#include<stdio.h>
#include<unistd.h>
#include<sys/msg.h>
#include<sys/ipc.h>
#include<sys/types.h>

struct msg
{
    long int type;
    char message[100];
}mq;


int main(){
    int msgid;
    key_t key;

    key = ftok(".",'a');
    msgid = msgget(key,0); //Pass 0 if already exists

    mq.type = 10;
    fgets(mq.message, 100, stdin);
    msgsnd(msgid, &mq, sizeof(mq),0); // 0 or IPC_NOWAIT 0 will wait if space is not available IPC_NOWAIT will return -1.

    execlp("ipcs","ipcs","-q",NULL);
    return 0;
}