#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
    system("cp file1.txt file2.txt");
    //system uses exec familyy functions.
    return 0;
}