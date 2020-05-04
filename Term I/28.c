#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include<sched.h>


int main(){

    // max and min priority value that can be used. same for SCHED_RR and SCHED_FIFO
    int num1=sched_get_priority_min(SCHED_RR);
	int num2=sched_get_priority_max(SCHED_RR);

	printf("minimum and maximum priorities are %d  %d \n",num1,num2);
}