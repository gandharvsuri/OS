#include<stdio.h>
#include<signal.h>
#include<unistd.h>
#include<stdlib.h>
#include <sys/time.h>

void sig_handler(int signo)
{
    printf("in handler\n");
    if (signo == SIGPROF){
        printf("received SIGPROF\n");
        exit(0);
    }
}

int main(void)
{
    if (signal(SIGPROF, sig_handler) == SIG_ERR)
    printf("\ncan't catch SIGPROF\n");

    struct itimerval timer;
    timer.it_value.tv_sec = 2;
    timer.it_value.tv_usec = 0;

    timer.it_interval.tv_sec = 1;
    timer.it_interval.tv_usec = 0;

    setitimer (ITIMER_REAL, &timer, NULL);
    printf("going to sleep\n");
    sleep(5);
    printf("no SIGPROF received\n");
    return 0;
}