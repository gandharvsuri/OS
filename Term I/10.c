#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(){

    int fd,f;
    f = open("file1.txt",O_RDONLY);

    fd = open("file3.txt",O_RDWR);

    char* buff = (char*)malloc(100);
    read(f,buff,100);

    write(fd,buff,10);
    int ret;

    ret = lseek(fd,0,SEEK_END);

    printf("lseek value: %d\n",ret);
    write(fd,buff,10);
    return 0;
}