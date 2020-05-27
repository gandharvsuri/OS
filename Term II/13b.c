#include<stdio.h>
#include<signal.h>
#include<unistd.h>


int main(){
    int pid;
    printf("enter pid : ");
    scanf("%d",&pid);
    printf("sending kill signal\n");
    kill(pid,SIGSTOP);
    return 0;
}