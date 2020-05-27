#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char* argv []){
    int fd = open("fifo_TERM-II",O_WRONLY);
    const int msg_size = 100;
    char msg[100] = "hello! hope you have a nice day! :)\n" ;
    write(fd,msg,msg_size);
    return 0;
}