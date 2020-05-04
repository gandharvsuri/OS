#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>


int main(){

    char* vp[] = {"/bin/bash", "-c", "ls -Rl", NULL};
    int ret = execvp(vp[0], vp);

}