#include<stdio.h>
#include<signal.h>
#include<unistd.h>

void sig_handler()
{
    printf("received SIGSTOP\n");
}

int main(){
    int pid = getpid();
    printf("%d waiting for SIGSTOP...\n",pid);
    if (signal(SIGSTOP, sig_handler) == SIG_ERR){
        perror("signal ");
        printf("can't catch SIGSTOP\n");
    }
    while(1);
    return 0;
}