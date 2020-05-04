#include <sys/select.h>
#include <sys/types.h>
#include <sys/time.h>
#include <unistd.h>
#include<stdio.h>


int main(){
    fd_set readfds;
    FD_ZERO(&readfds);
    FD_SET (0,&readfds);
    struct timeval timeout;

    timeout.tv_sec=10;
    timeout.tv_usec=0;
    int ret;

    ret = select(1,&readfds,NULL,NULL,&timeout);

    if(ret == 0){
        printf("No input\n");
    }

    else if(ret > 0){
        printf("Data available\n");
    }

}