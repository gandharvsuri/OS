#include<stdio.h>
#include<signal.h>
#include<unistd.h>

void sig_handler(int signo)
{
    if (signo == SIGKILL){
        printf("received SIGKILL\n");
    }
}

int main(){
    if(!fork()){
        printf("in child process...sending kill signal\n");
        kill(getppid(),SIGKILL);  // Sending kill signal to Parent.
    }
    else{
        sleep(5);
        printf("in parent process\n");
        if (signal(SIGKILL, sig_handler) == SIG_ERR)
            printf("can't catch SIGKILL\n");
    }
    return 0;
}