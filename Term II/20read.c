#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char* argv []){
    int fd = open("fifo_TERM-II",O_RDONLY);
    const int msg_size = 100;
    char msg[msg_size] ;
    int size = read(fd,msg,msg_size);
    printf("%s\n",msg);
    return 0;
}