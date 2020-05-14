#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <sys/wait.h>


int main(){
    int fd1[2];
    int fd2[2];

    if(pipe(fd1) == -1){
        printf("Pipe Error\n");
        return 0;
    }
    if(pipe(fd2) == -1){
        printf("Pipe Error\n");
        return 0;
    }

    int pid = fork();

    if(pid == 0){
        //child proc
        char s[100];
        char concatStr[100] = " WORLD";
        close(fd1[1]); //closing writing end of first pipe
        read(fd1[0],s,100);

        //printf("Child process, message recieved : %s \n",s);
        close(fd1[0]);
        close(fd2[0]); //close read

        strcat(s,concatStr);

        write(fd2[1],s,100);
        return 0;
    }
    else{
        char s[100] = "HELLO";
        close(fd1[0]); //close reading end of pipe1
        write(fd1[1],s,100);

        wait(NULL);
        close(fd1[1]);
        close(fd2[1]);


        read(fd2[0],s,100);

        printf("%s \n",s);

    }
    return 0;
}