#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

int main()
{
    char *args[] = {"./execfile", "Input from 26.c",NULL};
    execvp(args[0], args);
    return 0;
}