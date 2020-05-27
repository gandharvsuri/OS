#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char* argv []){
    int fd = open("fifo_TERM-II",O_RDWR);
    const int msg_size = 100000;
    char msg_read[msg_size] ;
    char msg_write[msg_size];
    while(1){
        int size = read(fd,msg_read,msg_size);
        printf("%s\n",msg_read);
        printf("enter message : ");
        fgets(msg_write, msg_size, stdin);
        write(fd,msg_write,msg_size);
    }
    return 0;
}