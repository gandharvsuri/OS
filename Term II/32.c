#include<stdio.h>
#include<unistd.h>
#include<sys/ipc.h>
#include<sys/types.h>
#include<sys/sem.h>

int main(){
    int key,semid;

    key = ftok(".",'a');
    struct sembuf buf = {0,-1,0};
    semid = semget(key,1,0);
    printf("Before Critical section... Checking for unlock\n");

    semop(semid,&buf,1);
    printf("Inside Critical Section.... Press Enter to Unlock\n");
    getchar();

    buf.sem_op = 1;
    semop(semid,&buf,1);
}