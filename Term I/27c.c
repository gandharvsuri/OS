#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

extern char **environ;

int main(){

    printf("c. execle\n");
    execle("/bin/ls", "ls", "-Rl", 0, environ);

}