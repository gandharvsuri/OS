#include<stdio.h>
#include<unistd.h>
#include<time.h>
#include<stdlib.h>
#include<wait.h>


int main(){

    int fd[2];


    if(!fork()){
        //child

        close(fd[0]);
        dup2(1,fd[1]);

        execl("ls","ls","-l",(char *) NULL);
        
    }
    else{
        //parent

        close(fd[1]);
        dup2(0,fd[0]);
        execl("wc","wc",(char *) NULL);
        wait(NULL);
    }

    return 0;
}