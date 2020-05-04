#include <unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include<fcntl.h>

int main(int argc, char **argv)
{
    struct stat buff;
    int fd;
    fd = open(argv[1],O_RDONLY);
    stat(argv[1],&buff);

    printf("file type = %d",buff.st_mode);
}