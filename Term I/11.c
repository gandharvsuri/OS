#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(){

    int fd,f,newfd,customfd=8;
    f = open("file1.txt",O_RDONLY);
    int ret;
    char* buff = (char*)malloc(100);

    fd = open("file3.txt",O_RDWR);

    newfd = dup(fd);

    read(f,buff,100);

    write(fd,buff,128);
    ret = lseek(fd,0,SEEK_END);
    write(newfd,buff,128);

    ret = dup2(fd,customfd);
    ret = lseek(customfd,0,SEEK_END);
    write(customfd,buff,100);

    newfd = fcntl(fd,F_DUPFD);
    ret = lseek(customfd,0,SEEK_END);
    write(customfd,buff,100);
    
    return 0;
}