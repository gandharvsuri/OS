#define _GNU_SOURCE
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>


int main(){
    int p[2];
    pipe(p);
    int pipe_size = fcntl(p[0],F_GETPIPE_SZ);
    printf("pipe size = %d\n",pipe_size);
    printf("max nnum of open fds = %d\n",FOPEN_MAX);
    return 0;
}
