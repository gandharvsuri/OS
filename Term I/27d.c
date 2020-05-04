#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

int main(){

    printf("d. execv\n");
    char* v[] = {"/bin/bash", "-c", "ls -Rl", NULL};
    int ret = execv(v[0], v);


}