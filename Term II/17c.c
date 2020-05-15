#include<stdio.h>
#include<unistd.h>
#include<time.h>
#include<stdlib.h>
#include<wait.h>
#include<fcntl.h>

int main(){

    int fd[2];

    if( pipe(fd) == -1){
        printf("pipe error\n");
        return 1;
    }

    int pid = fork();
    if(pid == 0){
        //child

        close(fd[0]); //close read
        close(1);
        fd[1] = fcntl(fd[1],F_DUPFD); // STDOUT ----> fd[1] (write)

        execlp("/bin/ls","bin/ls","-l",(char *) NULL);
        close(fd[1]);
        return 0;
    }
    else{
        //parent

        close(fd[1]); //close write
        close(0);
        fd[0] = fcntl(fd[0],F_DUPFD); // STDIN ----> fd[0] read
        execlp("wc","wc",(char *) NULL);
        close(fd[0]);
    }

    return 0;
}