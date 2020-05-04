#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(){

    char buff[1024];
    int fd;
    fd = open("file1.txt",O_RDONLY);

    while(read(fd,buff,1))
    {
        if(buff[0] =='\n')
            getchar();
        else
        {
            printf("%c",buff[0]);
        }
        
    }
    close(fd);
}