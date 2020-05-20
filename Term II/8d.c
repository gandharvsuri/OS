#include<stdio.h>
#include<signal.h>
#include<unistd.h>
#include<stdlib.h>

void sig_handler(int signo)
{
  if (signo == SIGALRM){
    printf("received SIGALRM\n");
    exit(0);
  }
}

int main(void)
{
  if (signal(SIGALRM, sig_handler) == SIG_ERR)
  printf("\ncan't catch SIGALRM\n");
  alarm(2);
  sleep(5);
  printf("no SIGALRM received\n");
  return 0;
}