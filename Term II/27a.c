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

    /*
    mtype
        0 - FIFO
        +ve = message type
        -ve = first message or <=  to abs value
    */

    msgrcv(msgid, &mq, sizeof(mq),10,0); // 0 or IPC_NOWAIT 0 will wait if msg type is not available until any proc sends with that msg type IPC_NOWAIT will return -1.

    printf("Message recieved %s",mq.message);

    execlp("ipcs","ipcs","-q",NULL);
    return 0;
}