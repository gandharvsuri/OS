#include<stdio.h>
#include<unistd.h>
#include<sys/sem.h>

union semun
{
    int val;
    struct semid_ds *buf;
    unsigned short int *array;
};

int main(){
    union semun arg;
    int key, semid;

    key = ftok(".", 'a');
    semid = semget(key,1,0);
    printf("%d\n",semid);
    arg.val = 2; // cause counting sem.

    semctl(semid,0,SETVAL,arg);
}
