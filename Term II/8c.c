#include<stdio.h>
#include<signal.h>
#include<unistd.h>
#include<stdlib.h>

void sig_handler(int signo)
{
  if (signo == SIGFPE){
    printf("received SIGFPE\n");
    exit(0);
  }
}

int main(void)
{
  if (signal(SIGFPE, sig_handler) == SIG_ERR)
  printf("\ncan't catch SIGFPE\n");
  float n = 1/0;
  printf("no SIGFPE received\n");
  return 0;
}