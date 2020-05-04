#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

int main(){

    int ret;
    ret = creat("3a", O_CREAT);
    printf("file discriptor: %d\n",ret);
}

