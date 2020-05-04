#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

int main(){

    printf("a. execl\n");
    execl("/bin/ls", "ls", "-Rl", 0);


}