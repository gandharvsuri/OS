#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

int main(){

    int ret ;
    ret = creat("5_1",O_CREAT);
    ret = creat("5_2",O_CREAT);
    ret = creat("5_3",O_CREAT);
    ret = creat("5_4",O_CREAT);
    ret = creat("5_5",O_CREAT);
    printf("File discriptor %d\n",ret);
    while(1){}
}