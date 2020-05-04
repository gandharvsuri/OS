#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>

int main(){

    int fd;
    fd = open("file1.txt",O_WRONLY);

    int ret;
    ret = fcntl(fd,F_GETFL);
    printf("RET: %d\n",ret);

    int flag=ret&O_ACCMODE;// to convert mode into flags 0,1,2
    if(flag==0)
        printf("Read mode \n");
    else if(flag==1)
        printf("write mode \n");
    else if(flag==2)
    printf("read and write mode \n");
}