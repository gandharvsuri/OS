#include <unistd.h>
#include <stdio.h>
#include <limits.h>

int main(){
    printf("max len of args to exec family = %ld\n",sysconf(_SC_ARG_MAX));
    printf("maximum number of simultaneous process per user id = %ld\n",sysconf(_SC_CHILD_MAX));
    printf("number of clock ticks (jiffy) per second = %ld\n",sysconf(_SC_CLK_TCK));
    printf("maximum number of open files = %ld\n",sysconf(_SC_ARG_MAX));
    printf("size of a page = %ld\n",sysconf(_SC_PAGESIZE));
    printf("total number of pages in the physical memory = %ld\n",sysconf(_SC_PHYS_PAGES));
    printf("number of currently available pages in the physical memory = %ld\n",sysconf(_SC_AVPHYS_PAGES));
    return 0;
}

/* NAME
       sysconf - get configuration information at run time

SYNOPSIS
       #include <unistd.h>

       long sysconf(int name);

DESCRIPTION
       POSIX allows an application to test at compile or run time whether certain options are supported, or what the value is of cer‐
       tain configurable constants or limits.

       At compile time this is done by including <unistd.h> and/or <limits.h> and testing the value of certain macros.

       At run time, one can ask for numerical values using the present function sysconf().  One can ask for numerical values that may
       depend on the filesystem a file is in using the calls fpathconf(3) and pathconf(3).  One can ask for string values using conf‐
       str(3).
*/