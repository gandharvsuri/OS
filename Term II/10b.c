#include<stdio.h>
#include<signal.h>
#include<unistd.h>
#include<stdlib.h>

void sig_handler(int signo)
{
    if (signo == SIGINT){
        printf("\nreceived SIGINT\n");
        exit(0);
    }
}

int main(void)
{
    struct sigaction act;
    act.sa_handler = &sig_handler;
    if (sigaction(SIGINT, &act, NULL) < 0) { // SIGINT : Interrupt from keyboard
		perror ("sigaction");
		return 1;
	}
    sleep(5);
    printf("no SIGINT received\n");
    return 0;
}