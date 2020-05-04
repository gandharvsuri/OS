#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
    char* buf = (char*)malloc(100);
    read(0,buf,100);
    write(1,buf,100);
}

// fd = 0 STDIN
//      = 1 STDOUT
//      = 2 STDERR 