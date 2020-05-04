#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>
#include<fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


int main() 
{ 
    int pid,fd;
    fd = open("file2.txt",O_WRONLY); 
    pid = fork(); 
    printf("%d\n",pid);
    if (pid == 0) 
    { 
        printf("Child writing\n");
        lseek(fd,0,SEEK_END);
        write(fd,"CHILD WRITING\n",100);
    } 

    else{
        printf("Parent writing\n");
        lseek(fd,0,SEEK_END);
        write(fd,"PARENT WRITING\n",100);
    }
} 