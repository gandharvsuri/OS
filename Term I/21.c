#include<stdio.h>
#include<stdlib.h>
#include <sys/types.h>
#include <unistd.h>
  

int main() 
{ 
    int pid; 
    pid = fork(); 
    printf("%d\n",pid);
    if (pid == 0) 
    { 
        printf("Child : %d\n",getpid());
        printf("Parent : %d\n",getppid());
    } 
} 