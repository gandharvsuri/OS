#include<stdio.h>
#include<stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include<time.h>
  

int main() 
{ 
    clock_t start,end;
    start= clock();
    getpid();
    end = clock();
    printf("Time taken: %ld\n",(end-start));

} 