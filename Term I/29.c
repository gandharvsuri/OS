#include<stdio.h>
#include<unistd.h>
#include<sched.h>

int main(){
	


    int pid = getpid();
    int num1=sched_getscheduler(pid);
    printf("Current scheduling policy: %d\n", num1);

    struct sched_param sp;
    sp.sched_priority = 50;
	

	sched_setscheduler(pid,SCHED_FIFO,&sp);	 
    int num2=sched_getscheduler(pid);
    printf("New scheduling policy: %d\n", sched_getscheduler(getpid()));

    /* Run using sudo: sudo ./a.out */

}
